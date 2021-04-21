#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>  // For ssize_t in Linux.

#include "heap.h"
#include "testing.h"

#define VOLUMEN 1000
#define LARGO_ARREGLO_INT 8
#define MINIMO_RAND 0

static void swap(const char *a, const char *b)
{
    const char *temp = a;
    a = b;
    b = temp;
}

int cmp_propio(const void* n, const void* m) {
    if (n == NULL && m != NULL) {
        return -1;
    }

    else if(n != NULL && m == NULL) {
        return 1;
    }

    else if (n == NULL && m == NULL) {
        return 0;
    }

    return *(const int*)n == *(const int*)m ? 0 : *(const int*)n > *(const int*)m ? 1 : -1;
}

static int *crear_dato(int a) {
    int *dato = malloc(sizeof(int));
    *dato = a;
    return dato;
}

static void prueba_crear_heap_vacio() {
    heap_t *heap = heap_crear(cmp_propio);

    print_test("El heap fue creado", heap != NULL);
    print_test("El heap esta vacio", heap_esta_vacio(heap) == true);
    print_test("La cantidad es 0", heap_cantidad(heap) == 0);
    print_test("Desencolar en un heap vacio es NULL", heap_desencolar(heap) == NULL);
    heap_destruir(heap, NULL);
    print_test("Destruyo el heap", true);

}

static void prueba_heap_encolar() {
    heap_t *heap = heap_crear(cmp_propio);

    int valores[LARGO_ARREGLO_INT] = {0, 1, 2, 3, 4, 5, 6, 7};

    print_test("La cantidad es 0", heap_cantidad(heap) == 0);
    bool ok = true;
    for (size_t i = 0; i < LARGO_ARREGLO_INT; i++) {
        ok &= heap_encolar(heap, &valores[i]) && heap_cantidad(heap) == i+1;
    }
    print_test("Encola arreglo de numeros", ok);
    heap_destruir(heap, NULL);
    print_test("Destruyo el heap", true);

}

static void prueba_heap_desencolar() {
    heap_t* heap = heap_crear(cmp_propio);

    int valores[LARGO_ARREGLO_INT] = {0, 1, 2, 3, 4, 5, 6, 7};

    print_test("La cantidad es 0", heap_cantidad(heap) == 0);
    bool ok = true;
    for (size_t i = 0; i < LARGO_ARREGLO_INT; i++) {
        ok &= heap_encolar(heap, &valores[i]) && heap_cantidad(heap) == i+1;
    }
    print_test("Encola arreglo de numeros", ok);
    print_test("La cantidad es la correcta", heap_cantidad(heap) == LARGO_ARREGLO_INT);
    
    ok = true;
    for (size_t i = LARGO_ARREGLO_INT; i > 0; i--) {
        ok &= heap_desencolar(heap) == &valores[i - 1] && heap_cantidad(heap) == i - 1;
    }
    print_test("Desencola arreglo de numeros", ok);
    print_test("La cantidad vuelve a ser 0", heap_cantidad(heap) == 0);

    heap_destruir(heap, NULL);
}

static void prueba_heap_valor_null() {
    heap_t* heap = heap_crear(cmp_propio);

    void *valor = NULL;

    /* Inserta NULL y luego lo borra */
    print_test("Prueba heap insertar valor NULL", heap_encolar(heap, valor));
    print_test("El heap no esta vacio", heap_esta_vacio(heap) == false);
    print_test("Prueba heap la cantidad de elementos es 1", heap_cantidad(heap) == 1);
    print_test("Prueba heap desencolar es valor NULL", heap_desencolar(heap) == valor);
    print_test("Prueba heap la cantidad de elementos es 0", heap_cantidad(heap) == 0);

    heap_destruir(heap, NULL);
}

static void prueba_heap_volumen(size_t largo, bool debug) {
    heap_t* heap = heap_crear(cmp_propio);

    unsigned int *valores[largo];

    /* Inserta 'largo' parejas en el heap */
    bool ok = true;
    for (unsigned int i = 0; i < largo; i++) {
        valores[i] = malloc(sizeof(int));
        *valores[i] = i;
        ok &= heap_encolar(heap, valores[i]);
        if (!ok) break;
    }

    if (debug) print_test("Prueba heap almacenar muchos elementos", ok);
    if (debug) print_test("Prueba heap la cantidad de elementos es correcta", heap_cantidad(heap) == largo);

    /* Verifica que devuelva los valores correctos */
    for (size_t i = largo; i > 0; i--) {
        ok &= heap_desencolar(heap) == valores[i-1];
        if (!ok) break;
    }

    if (debug) print_test("Prueba heap desencolar muchos elementos", ok);
    if (debug) print_test("Prueba heap la cantidad de elementos es correcta", heap_cantidad(heap) == 0);

    /* Destruye el heap y crea uno nuevo que sí libera */
    heap_destruir(heap, NULL);
    heap = heap_crear(cmp_propio);

    /* Inserta 'largo' parejas en el heap */
    ok = true;
    for (size_t i = 0; i < largo; i++) {
        ok = heap_encolar(heap, valores[i]);
        if (!ok) break;
    }

    if (debug) print_test("Prueba heap almacenar muchos elementos", ok);
    if (debug) print_test("Prueba heap la cantidad de elementos es correcta", heap_cantidad(heap) == largo);

    /* Destruye el heap - debería liberar los enteros */
    heap_destruir(heap, free);
}

static void pruebas_con_varios_elementos() {

    int *datos[LARGO_ARREGLO_INT];

    for (int i = 0; i < 6; i++)
        datos[i] = crear_dato(i);

    heap_t* heap = heap_crear(cmp_propio);

    heap_encolar(heap, datos[0]);
    heap_encolar(heap, datos[1]);
    heap_encolar(heap, datos[2]);

    print_test("desencolar es el correcto", heap_desencolar(heap) == datos[2]);
    print_test("cantidad es 2", heap_cantidad(heap) == 2);

    print_test("desencolar es el correcto", heap_desencolar(heap) == datos[1]);
    print_test("cantidad es 1", heap_cantidad(heap) == 1);

    print_test("desencolar es el correcto", heap_desencolar(heap) == datos[0]);
    print_test("desencolar da NULL", heap_desencolar(heap) == NULL);
    print_test("cantidad es 0", heap_cantidad(heap) == 0);
    
    heap_encolar(heap, datos[3]);
    heap_encolar(heap, datos[4]);
    heap_encolar(heap, datos[5]);

    print_test("desencolar es el correcto", heap_desencolar(heap) == datos[5]);
    print_test("desencolar es el correcto", heap_desencolar(heap) == datos[4]);
    print_test("desencolar es el correcto", heap_desencolar(heap) == datos[3]);

    heap_destruir(heap, NULL);

    /* no hay datos en el heap */
    for (int i = 0; i < 6; i++)
        free(datos[i]);
}

static void pruebas_desencolar_punteros() {

    heap_t *heap = heap_crear(cmp_propio);

    int *datos[LARGO_ARREGLO_INT];

    for (int i = 0; i < LARGO_ARREGLO_INT; i++)
        datos[i] = crear_dato(i + 2);

    print_test("Cantidad es 0", heap_cantidad(heap) == 0);
    heap_encolar(heap, datos[0]);
    print_test("Cantidad es 1", heap_cantidad(heap) == 1);
    heap_encolar(heap, datos[1]);
    print_test("Cantidad es 2", heap_cantidad(heap) == 2);
    heap_encolar(heap, datos[2]);
    print_test("Cantidad es 3", heap_cantidad(heap) == 3);
    print_test("desencolar es !NULL", heap_desencolar(heap) != NULL);
    print_test("Cantidad es 2", heap_cantidad(heap) == 2);
    print_test("desencolar es !NULL", heap_desencolar(heap) != NULL);
    print_test("Cantidad es 1", heap_cantidad(heap) == 1);
    print_test("desencolar es !NULL", heap_desencolar(heap) != NULL);
    print_test("Cantidad es 0", heap_cantidad(heap) == 0);
    print_test("desencolar es NULL", heap_desencolar(heap) == NULL);
    print_test("Cantidad es 0", heap_cantidad(heap) == 0);
    print_test("El heap esta vacio", heap_esta_vacio(heap) == true);

    heap_destruir(heap, NULL);

    for (int i = 0; i < LARGO_ARREGLO_INT; i++)
        free(datos[i]);

}

static void pruebas_encolar_desencolar() {
    heap_t *heap = heap_crear(cmp_propio);

    int *datos[LARGO_ARREGLO_INT];

    for (int i = 0; i < LARGO_ARREGLO_INT; i++)
        datos[i] = crear_dato(i * 100);

    print_test("Cantidad inicial es 0", heap_cantidad(heap) == 0);
    heap_encolar(heap, datos[0]);
    print_test("Cantidad es 1", heap_cantidad(heap) == 1);
    print_test("Encolo datos[2]", heap_encolar(heap, datos[2]));
    print_test("Cantidad es 2", heap_cantidad(heap) == 2);
    print_test("Desencolar es correcto", heap_desencolar(heap) == datos[2]);
    print_test("Cantidad es 1", heap_cantidad(heap) == 1);
    print_test("Encolo datos[1]", heap_encolar(heap, datos[1]));
    print_test("Encolo datos[3]", heap_encolar(heap, datos[3]));
    print_test("Encolo NULL como valor", heap_encolar(heap, NULL));

    heap_destruir(heap, free);

    free(datos[2]);
    free(datos[4]);
    free(datos[5]);
    free(datos[6]);
    free(datos[7]);
}

static int free_count = 0;
static void mi_free(int *dato) {
    free_count++;
    free(dato);
}

static void prueba_destruir_null() {

    heap_t *heap = heap_crear(cmp_propio);

    int *dato = crear_dato(9);

    heap_encolar(heap, NULL);
    heap_encolar(heap, dato);
    heap_destruir(heap, (void (*)(void *))mi_free);

    print_test("Se invocó el destructor el número esperado de veces", free_count == 2);

}

static void pruebas_heap_heapsort() {

    void *arreglo_ordenado[LARGO_ARREGLO_INT];
    void *arreglo_desordenado[LARGO_ARREGLO_INT];

    for (int i = 0; i < LARGO_ARREGLO_INT; i++) {
        arreglo_ordenado[i] = crear_dato(i+2);
        arreglo_desordenado[i] = crear_dato(i+2);
    }

    for (int i = 0; i < LARGO_ARREGLO_INT; i++)
    {
        size_t numero_random = ((size_t)rand() % ((LARGO_ARREGLO_INT-1) + 1 - MINIMO_RAND) + MINIMO_RAND);
        swap(arreglo_ordenado[i], arreglo_ordenado[numero_random]);
    }

    heap_sort(arreglo_desordenado, LARGO_ARREGLO_INT, cmp_propio);

    bool ok = true;
    for (size_t i = 0; i < LARGO_ARREGLO_INT; i++) {
        ok &= *(int*)arreglo_ordenado[i] == *(int*)arreglo_desordenado[i];
    }

    for (int i = 0; i < LARGO_ARREGLO_INT; i++) {
        free(arreglo_desordenado[i]);
        free(arreglo_ordenado[i]);
    }

    print_test("Heapsort ordena como la gente", ok);
}

static void  pruebas_heap_crear_arr() {
    void *arreglo_int[LARGO_ARREGLO_INT];

    for (int i = 0; i < LARGO_ARREGLO_INT; i++) {
        arreglo_int[i] = crear_dato(i+2);
    }

    for (int i = 0; i < LARGO_ARREGLO_INT; i++)
    {
        size_t numero_random = ((size_t)rand() % ((LARGO_ARREGLO_INT-1) + 1 - MINIMO_RAND) + MINIMO_RAND);
        swap(arreglo_int[i], arreglo_int[numero_random]);
    }

    heap_t *heap_con_arreglo = heap_crear_arr(arreglo_int, LARGO_ARREGLO_INT, cmp_propio);

    bool ok = true;
    ok &= !heap_esta_vacio(heap_con_arreglo);
    ok &= heap_cantidad(heap_con_arreglo) == LARGO_ARREGLO_INT;
    ok &= heap_ver_max(heap_con_arreglo) == arreglo_int[LARGO_ARREGLO_INT-1];
    ok &= heap_encolar(heap_con_arreglo, crear_dato(9999));
    void *dato;
    ok &= *(int*)(dato = heap_desencolar(heap_con_arreglo)) == 9999;

    print_test("Pruebas con heap creado a partir de un arreglo", ok);

    heap_destruir(heap_con_arreglo, free);
    free(dato);
}

void pruebas_heap_estudiante() {
    /* Ejecuta todas las pruebas unitarias. */
    prueba_crear_heap_vacio();
    prueba_heap_encolar();
    prueba_heap_desencolar();
    prueba_heap_valor_null();
    prueba_heap_volumen(VOLUMEN, true);

    pruebas_con_varios_elementos();
    pruebas_desencolar_punteros();
    pruebas_encolar_desencolar();
    pruebas_heap_crear_arr();
    pruebas_heap_heapsort();

    prueba_destruir_null();
}

void pruebas_volumen_estudiante(size_t largo) {
    prueba_heap_volumen(largo, false);
}

// COMENTAR PARA PROBAR
#ifndef CORRECTOR
int main(int argc, char *argv[]) {
    printf("~~~ PRUEBAS ESTUDIANTE ~~~\n");
    pruebas_heap_estudiante();
    return failure_count() > 0;
}
#endif