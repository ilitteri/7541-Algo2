#include "heap.h"
#include <stdlib.h>
#include <string.h>  // memcpy()

#define TAM_INI 10
#define CTE_REDIMENSION 2

/* ******************************************************************
 *                     FUNCIONES AUXILIARES
 * *****************************************************************/

static void swap(void **datos, size_t pos1, size_t pos2) {
    void *temp = datos[pos1];
    datos[pos1] = datos[pos2];
    datos[pos2] = temp;
}

static size_t obtener_pos_padre(size_t i) {
    return (i - 1) / 2;
}

static size_t obtener_pos_hijo_izq(size_t i) {
    return i * 2 + 1;
}

static size_t obtener_pos_hijo_der(size_t i) {
    return i * 2 + 2;
}

/* Dado un elemento, lo compara con sus padres hasta dejarlo en la
 * ubicación correcta de manera tal que no se pierda la propiedad de
 * heap. */
static void upheap(void **datos, cmp_func_t cmp, size_t pos_actual) {
    /* No se aplican operaciones si la posición es la raíz. */
    if (pos_actual == 0)
        return;

    void *actual = datos[pos_actual];

    size_t pos_padre = obtener_pos_padre(pos_actual);
    void *padre = datos[pos_padre];

    /* Se intercambian y se continúa recursivamente si el elemento
     * actual es mayor que el padre. */
    if (cmp(actual, padre) > 0) {
        swap(datos, pos_actual, pos_padre);
        upheap(datos, cmp, pos_padre);
    }
}

/* Dado un elemento, lo compara con sus hijos hasta dejarlo en la
 * ubicación correcta de manera tal que no se pierda la propiedad de
 * heap. */
static void downheap(void **datos,
                     size_t cant,
                     cmp_func_t cmp,
                     size_t pos_actual) {
    /* No se opera si pos_actual es inválida. */
    if (pos_actual >= cant)
        return;

    size_t pos_izq = obtener_pos_hijo_izq(pos_actual);
    size_t pos_der = obtener_pos_hijo_der(pos_actual);

    /* Se busca el mayor de los dos hijos. */
    size_t pos_mayor = pos_actual;
    void *actual = datos[pos_actual];

    if (pos_izq < cant) {
        void *izquierdo = datos[pos_izq];
        if (cmp(actual, izquierdo) < 0)
            pos_mayor = pos_izq;
    }

    if (pos_der < cant) {
        void *mayor = datos[pos_mayor];
        void *derecho = datos[pos_der];
        if (cmp(mayor, derecho) < 0)
            pos_mayor = pos_der;
    }

    /* Si hay un hijo es más grande que el actual, se intercambian y se
     * continúa recursivamente. */
    if (pos_mayor != pos_actual) {
        swap(datos, pos_mayor, pos_actual);
        downheap(datos, cant, cmp, pos_mayor);
    }
}


/* Modifica el orden de los elementos del arreglo para que cumpla la
 * propiedad de heap usando la función de comparación especificada. */
void heapify(void *elementos[], size_t cant, cmp_func_t cmp) {
    /* Hace downheap sólo a los nodos internos (no a las hojas). */
    size_t i = cant / 2;
    while (i--)
        downheap(elementos, cant, cmp, i);
}

static bool redimensionar_datos(heap_t *heap, size_t tam_nuevo) {
    void *datos_nuevo = realloc(heap->datos, tam_nuevo * sizeof(void *));

    if (tam_nuevo > 0 && datos_nuevo == NULL) {
        return false;
    }

    heap->datos = datos_nuevo;
    heap->tam = tam_nuevo;
    return true;
}


/* Función de heapsort genérica. Esta función ordena mediante heap_sort
 * un arreglo de punteros opacos, para lo cual requiere que se
 * le pase una función de comparación. Modifica el arreglo "in-place".
 * Notar que esta función NO es formalmente parte del TAD Heap.
 */
void heap_sort(void *elementos[], size_t cant, cmp_func_t cmp) {
    if (!elementos || cant == 0)
        return;

    /* Convierte el arreglo en un heap. */
    heapify(elementos, cant, cmp);

    /* Extrae el mayor y lo coloca en la posición correspondiente. */
    for (size_t i = cant - 1; i > 0; i--) {
        swap(elementos, 0, i);
        downheap(elementos, i, cmp, 0);
    }
}


/* Crea un heap. Recibe como único parámetro la función de comparación a
 * utilizar. Devuelve un puntero al heap, el cual debe ser destruido con
 * heap_destruir().
 */
heap_t *heap_crear(cmp_func_t cmp){
    heap_t *heap = malloc(sizeof(heap_t));

    if (!heap || !(heap->datos = malloc(TAM_INI * sizeof(void*)))) {
        free(heap);
        return NULL;
    }

    heap->cmp = cmp;
    heap->tam = TAM_INI;
    heap->cant = 0;

    return heap;
}


/*
 * Constructor alternativo del heap. Además de la función de comparación,
 * recibe un arreglo de valores con que inicializar el heap. Complejidad
 * O(n).
 *
 * Excepto por la complejidad, es equivalente a crear un heap vacío y encolar
 * los valores de uno en uno
*/
heap_t *heap_crear_arr(void *arreglo[], size_t n, cmp_func_t cmp) {
    heap_t *heap = malloc(sizeof(heap_t));

    if (!heap || !(heap->datos = malloc(n * sizeof(void*)))) {
        free(heap);
        return NULL;
    }

    memcpy(heap->datos, arreglo, n * sizeof(void*));
    heapify(heap->datos, n, cmp);

    heap->cmp = cmp;
    heap->tam = n;
    heap->cant = n;

    return heap;
}


/* Elimina el heap, llamando a la función dada para cada elemento del mismo.
 * El puntero a la función puede ser NULL, en cuyo caso no se llamará.
 * Post: se llamó a la función indicada con cada elemento del heap. El heap
 * dejó de ser válido. */
void heap_destruir(heap_t *heap, void (*destruir_elemento)(void *)) {
    if (destruir_elemento) {
        for (size_t i = 0; i < heap->cant; i++)
            destruir_elemento(heap->datos[i]);
    }

    free(heap->datos);
    free(heap);
}

/* Devuelve la cantidad de elementos que hay en el heap. */
size_t heap_cantidad(const heap_t *heap) {
    return heap->cant;
}

/* Devuelve true si la cantidad de elementos que hay en el heap es 0, false en
 * caso contrario. */
bool heap_esta_vacio(const heap_t *heap) {
    return heap->cant == 0;
}


/* Agrega un elemento al heap. El elemento no puede ser NULL.
 * Devuelve true si fue una operación exitosa, o false en caso de error.
 * Pre: el heap fue creado.
 * Post: se agregó un nuevo elemento al heap.
 */
bool heap_encolar(heap_t *heap, void *elem) {
    /* Verifica si tiene que redimensionar antes de encolar. */
    if (heap->cant == heap->tam) {
        if (!redimensionar_datos(heap, CTE_REDIMENSION * heap->tam))
            return false;
    }

    heap->datos[heap->cant] = elem;
    heap->cant++;
    upheap(heap->datos, heap->cmp, heap->cant - 1);

    return true;
}

/* Devuelve el elemento con máxima prioridad. Si el heap esta vacío, devuelve
 * NULL.
 * Pre: el heap fue creado.
 */
void *heap_ver_max(const heap_t *heap) {
    if (heap->cant == 0)
        return NULL;

    return heap->datos[0];
}

/* Elimina el elemento con máxima prioridad, y lo devuelve.
 * Si el heap esta vacío, devuelve NULL.
 * Pre: el heap fue creado.
 * Post: el elemento desencolado ya no se encuentra en el heap.
 */
void *heap_desencolar(heap_t *heap) {
    if (heap->cant == 0)
        return NULL;

    void *elem = heap->datos[0];
    heap->cant--;

    /* Actualiza la propiedad de heap. */
    if (heap->cant > 0) {
        swap(heap->datos, 0, heap->cant);
        downheap(heap->datos, heap->cant, heap->cmp, 0);
    }

    /* Redimensiona en caso de ser necesario. */
    if (heap->cant < heap->tam / CTE_REDIMENSION && heap->tam > TAM_INI) {
        if (!redimensionar_datos(heap, heap->tam / CTE_REDIMENSION))
            return NULL;
    }

    return elem;
}