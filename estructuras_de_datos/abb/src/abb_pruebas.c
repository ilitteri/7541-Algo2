#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>  // For ssize_t in Linux.

#include "abb.h"
#include "testing.h"

#define VOLUMEN 1000
#define LARGO_ARREGLO_INT 6
#define LARGO_ARREGLO_INT_7 7
#define LARGO_STRING 7

#define MINIMO_RAND 0
#define MAXIMO_RAND 99999999

static void swap(const char *x, const char *y) 
{ 
    const char *temp = x; 
    x = y; 
    y = temp; 
} 

static void prueba_crear_abb_vacio() {
    abb_t *abb = abb_crear(strcmp, NULL);

    print_test("El abb fue creado", abb != NULL);
    print_test("La cantidad es 0", abb_cantidad(abb) == 0);
    print_test("Borrar en un arbol vacio es NULL", abb_borrar(abb, "hola") == NULL);
    print_test("Obtener en un arbol vacio es NULL", abb_obtener(abb, "hola") == NULL);
    abb_destruir(abb);
    print_test("Destruyo el abb", true);
}

static void prueba_iterar_abb_vacio() {
    abb_t* abb = abb_crear(strcmp, NULL);
    abb_iter_t* iter = abb_iter_in_crear(abb);
    print_test("Prueba abb iter crear iterador abb vacio", iter);
    print_test("Prueba abb iter esta al final", abb_iter_in_al_final(iter));
    print_test("Prueba abb iter avanzar es false", !abb_iter_in_avanzar(iter));
    print_test("Prueba abb iter ver actual es NULL", !abb_iter_in_ver_actual(iter));

    abb_iter_in_destruir(iter);
    abb_destruir(abb);
}

static void prueba_abb_guardar() {
    abb_t *abb = abb_crear(strcmp, NULL);

    char* claves[LARGO_STRING] = {"M", "D", "A", "E", "O", "T", "U"};

    print_test("La cantidad es 0", abb_cantidad(abb) == 0);
    bool ok = true;
    for (size_t i = 0; i < LARGO_STRING; i++) {
        ok &= abb_guardar(abb, claves[i], NULL) && abb_cantidad(abb) == i+1;
        ok &= abb_obtener(abb, claves[i]) == NULL;
    }
    print_test("Agregar arreglo de claves", ok);
    abb_destruir(abb);
    print_test("Destruyo el abb", true);
}

static void prueba_abb_reemplazar() {
    abb_t *abb = abb_crear(strcmp, NULL);

    int a = 13;
    int b = 16;
    char* claves[LARGO_STRING] = {"M", "D", "A", "E", "O", "T", "U"};

    print_test("La cantidad es 0", abb_cantidad(abb) == 0);
    bool ok = true;
    for (size_t i = 0; i < LARGO_STRING; i++) {
        ok &= abb_guardar(abb, claves[i], &a) && abb_cantidad(abb) == i+1;
    }
    for (size_t i = 0; i < LARGO_STRING; i++) {
        ok &= abb_obtener(abb, claves[i]) == &a;
    }
    print_test("Agrego arreglo de claves correctamente", ok);
    for (size_t i = 0; i < LARGO_STRING; i++) {
        ok &= abb_guardar(abb, claves[i], &b) && abb_cantidad(abb) == LARGO_STRING;
    }
    for (size_t i = 0; i < LARGO_STRING; i++){
        ok &= abb_obtener(abb, claves[i]) == &b;
    }
    print_test("Reemplazo arreglo de claves correctamente", ok);
    abb_destruir(abb);
    print_test("Destruyo el abb", true);
}

static void prueba_abb_reemplazar_con_destruir() {
    abb_t *abb = abb_crear(strcmp, free);
    
    int *valores0[LARGO_ARREGLO_INT_7];
    int *valores1[LARGO_ARREGLO_INT_7];
    for (size_t i = 0; i < LARGO_STRING; i++) {
        valores0[i] = malloc(sizeof(int));
        valores1[i] = malloc(sizeof(int));
    }
    char* claves[LARGO_STRING] = {"M", "D", "A", "E", "O", "T", "U"};

    print_test("La cantidad es 0", abb_cantidad(abb) == 0);
    bool ok = true;
    for (size_t i = 0; i < LARGO_STRING; i++) {
        ok &= abb_guardar(abb, claves[i], valores0[i]) && abb_cantidad(abb) == i+1;
        ok &= abb_obtener(abb, claves[i]) == valores0[i];
    }
    print_test("Agrego 7 claves con destruir correctamente", ok);
    for (size_t i = 0; i < LARGO_STRING; i++) {
        ok &= abb_guardar(abb, claves[i], valores1[i]) && abb_cantidad(abb) == 7;
        ok &= abb_obtener(abb, claves[i]) == valores1[i];
    }
    print_test("Reemplazo 7 claves con destruir correctamente", ok);
    abb_destruir(abb);
    print_test("Destruyo el abb", true);
}

static void prueba_abb_borrar() {
    abb_t* abb = abb_crear(strcmp, NULL);

    char *clave1 = "perro", *valor1 = "guau";
    char *clave2 = "gato", *valor2 = "miau";
    char *clave3 = "vaca", *valor3 = "mu";

    print_test("Prueba abb insertar clave1", abb_guardar(abb, clave1, valor1));
    print_test("Prueba abb insertar clave2", abb_guardar(abb, clave2, valor2));
    print_test("Prueba abb insertar clave3", abb_guardar(abb, clave3, valor3));

    print_test("Prueba abb pertenece clave3, es verdadero", abb_pertenece(abb, clave3));
    print_test("Prueba abb borrar clave3, es valor3", abb_borrar(abb, clave3) == valor3);
    print_test("Prueba abb borrar clave3, es NULL", !abb_borrar(abb, clave3));
    print_test("Prueba abb pertenece clave3, es falso", !abb_pertenece(abb, clave3));
    print_test("Prueba abb obtener clave3, es NULL", !abb_obtener(abb, clave3));
    print_test("Prueba abb la cantidad de elementos es 2", abb_cantidad(abb) == 2);

    print_test("Prueba abb pertenece clave1, es verdadero", abb_pertenece(abb, clave1));
    print_test("Prueba abb borrar clave1, es valor1", abb_borrar(abb, clave1) == valor1);
    print_test("Prueba abb borrar clave1, es NULL", !abb_borrar(abb, clave1));
    print_test("Prueba abb pertenece clave1, es falso", !abb_pertenece(abb, clave1));
    print_test("Prueba abb obtener clave1, es NULL", !abb_obtener(abb, clave1));
    print_test("Prueba abb la cantidad de elementos es 1", abb_cantidad(abb) == 1);

    print_test("Prueba abb pertenece clave2, es verdadero", abb_pertenece(abb, clave2));
    print_test("Prueba abb borrar clave2, es valor2", abb_borrar(abb, clave2) == valor2);
    print_test("Prueba abb borrar clave2, es NULL", !abb_borrar(abb, clave2));
    print_test("Prueba abb pertenece clave2, es falso", !abb_pertenece(abb, clave2));
    print_test("Prueba abb obtener clave2, es NULL", !abb_obtener(abb, clave2));
    print_test("Prueba abb la cantidad de elementos es 0", abb_cantidad(abb) == 0);

    abb_destruir(abb);

}

static void prueba_abb_clave_vacia()
{
    abb_t* abb = abb_crear(strcmp, NULL);

    char *clave = "", *valor = "";

    print_test("Prueba abb insertar clave vacia", abb_guardar(abb, clave, valor));
    print_test("Prueba abb la cantidad de elementos es 1", abb_cantidad(abb) == 1);
    print_test("Prueba abb obtener clave vacia es valor", abb_obtener(abb, clave) == valor);
    print_test("Prueba abb pertenece clave vacia, es true", abb_pertenece(abb, clave));
    print_test("Prueba abb borrar clave vacia, es valor", abb_borrar(abb, clave) == valor);
    print_test("Prueba abb la cantidad de elementos es 0", abb_cantidad(abb) == 0);

    abb_destruir(abb);
}

static void prueba_abb_valor_null() {
    abb_t* abb = abb_crear(strcmp, NULL);

    char *clave = "", *valor = NULL;

    /* Inserta 1 valor y luego lo borra */
    print_test("Prueba abb insertar clave vacia valor NULL", abb_guardar(abb, clave, valor));
    print_test("Prueba abb la cantidad de elementos es 1", abb_cantidad(abb) == 1);
    print_test("Prueba abb obtener clave vacia es valor NULL", abb_obtener(abb, clave) == valor);
    print_test("Prueba abb pertenece clave vacia, es true", abb_pertenece(abb, clave));
    print_test("Prueba abb borrar clave vacia, es valor NULL", abb_borrar(abb, clave) == valor);
    print_test("Prueba abb la cantidad de elementos es 0", abb_cantidad(abb) == 0);

    abb_destruir(abb);
}

static void prueba_abb_volumen(size_t largo, bool debug)
{
    abb_t* abb = abb_crear(strcmp, NULL);

    const size_t largo_clave = 10;
    char (*claves)[largo_clave] = malloc(largo * largo_clave);

    unsigned* valores[largo];

    size_t cantidad = abb_cantidad(abb);

    /* Inserta 'largo' parejas en el abb */
    bool ok = true;
    for (unsigned i = 0; i < largo; i++) {
        valores[i] = malloc(sizeof(int));
        sprintf(claves[i], "%08d", i);
        *valores[i] = i;
        cantidad++;
        if (!ok) break;
    }

    for (unsigned i = 0; i < largo; i++)
    {
        size_t numero_random = ((size_t)rand() % ((largo-1) + 1 - MINIMO_RAND) + MINIMO_RAND);
        swap(claves[i], claves[numero_random]);
    }

    for (unsigned i = 0; i < largo; i++)
    {
        ok &= abb_guardar(abb, claves[i], valores[i]);
    }

    if (debug) print_test("Cantidad correcta", abb_cantidad(abb) == cantidad);
    if (debug) print_test("Prueba abb almacenar muchos elementos", ok);

    /* Verifica que devuelva los valores correctos */
    for (size_t i = 0; i < largo; i++) {
        ok = abb_pertenece(abb, claves[i]);
        if (!ok) break;
        ok = abb_obtener(abb, claves[i]) == valores[i];
        if (!ok) break;
    }

    if (debug) print_test("Prueba abb pertenece y obtener muchos elementos", ok);
    if (debug) print_test("Prueba abb la cantidad de elementos es correcta", abb_cantidad(abb) == largo);

    /* Verifica que borre y devuelva los valores correctos */
    for (size_t i = 0; i < largo; i++) {
        ok = abb_borrar(abb, claves[i]) == valores[i];
        if (!ok) break;
    }

    if (debug) print_test("Prueba abb borrar muchos elementos", ok);
    if (debug) print_test("Prueba abb la cantidad de elementos es 0", abb_cantidad(abb) == 0);

    /* Destruye el abb y crea uno nuevo que sí libera */
    abb_destruir(abb);
    abb = abb_crear(strcmp, free);

    /* Inserta 'largo' parejas en el abb */
    ok = true;
    for (size_t i = 0; i < largo; i++) {
        ok = abb_guardar(abb, claves[i], valores[i]);
        if (!ok) break;
    }

    free(claves);

    /* Destruye el abb - debería liberar los enteros */
    abb_destruir(abb);

}

static ssize_t buscar(const char* clave, char* claves[], size_t largo)
{
    for (size_t i = 0; i < largo; i++) {
        if (strcmp(clave, claves[i]) == 0) return (ssize_t) i;
    }
    return -1;
}

static void prueba_abb_in_order()
{
    abb_t* abb = abb_crear(strcmp, NULL);

    char *claves[] = {"perro", "gato", "vaca"};
    char *valores[] = {"guau", "miau", "mu"};

    /* Inserta 3 valores */
    print_test("Prueba abb insertar clave1", abb_guardar(abb, claves[0], valores[0]));
    print_test("Prueba abb insertar clave2", abb_guardar(abb, claves[1], valores[1]));
    print_test("Prueba abb insertar clave3", abb_guardar(abb, claves[2], valores[2]));

    // Prueba de iteración sobre las claves almacenadas.
    abb_iter_t* iter = abb_iter_in_crear(abb);
    const char *clave;
    ssize_t indice;

    print_test("Prueba abb iterador esta al final, es false", !abb_iter_in_al_final(iter));

    /* Primer valor */
    clave = abb_iter_in_ver_actual(iter);
    indice = buscar(clave, claves, sizeof(claves) / sizeof(char *));
    print_test("Prueba abb iterador ver actual, es una clave valida", indice == 1);
    print_test("Prueba abb iterador ver actual, no es el mismo puntero", clave != claves[indice]);
    print_test("Prueba abb iterador avanzar es true", abb_iter_in_avanzar(iter));
    print_test("Prueba abb iterador esta al final, es false", !abb_iter_in_al_final(iter));

    /* Segundo valor */
    clave = abb_iter_in_ver_actual(iter);
    indice = buscar(clave, claves, sizeof(claves) / sizeof(char *));
    print_test("Prueba abb iterador ver actual, es una clave valida", indice == 0);
    print_test("Prueba abb iterador ver actual, no es el mismo puntero", clave != claves[indice]);
    print_test("Prueba abb iterador avanzar es true", abb_iter_in_avanzar(iter));
    print_test("Prueba abb iterador esta al final, es false", !abb_iter_in_al_final(iter));

    /* Tercer valor */
    clave = abb_iter_in_ver_actual(iter);
    indice = buscar(clave, claves, sizeof(claves) / sizeof(char *));
    print_test("Prueba abb iterador ver actual, es una clave valida", indice == 2);
    print_test("Prueba abb iterador ver actual, no es el mismo puntero", clave != claves[indice]);
    abb_iter_in_avanzar(iter);
    print_test("Prueba abb iterador esta al final, es true", abb_iter_in_al_final(iter));

    /* Vuelve a tratar de avanzar, por las dudas */
    print_test("Prueba abb iterador ver actual, es NULL", !abb_iter_in_ver_actual(iter));
    print_test("Prueba abb iterador avanzar es false", !abb_iter_in_avanzar(iter));
    print_test("Prueba abb iterador esta al final, es true", abb_iter_in_al_final(iter));

    abb_iter_in_destruir(iter);
    abb_destruir(abb);
}

static void prueba_abb_in_order_volumen(size_t largo)
{
    abb_t *abb = abb_crear(strcmp, NULL);

    const size_t largo_clave = 10;
    char (*claves)[largo_clave] = malloc(largo * largo_clave);

    size_t valores[largo];

    size_t cantidad = abb_cantidad(abb);

    /* Inserta 'largo' parejas en el abb */
    bool ok = true;
    for (unsigned i = 0; i < largo; i++) {
        sprintf(claves[i], "%08d", i);
        valores[i] = i;
        cantidad++;
    }

    for (unsigned i = 0; i < largo; i++)
    {
        size_t numero_random = ((size_t)rand() % ((largo-1) + 1 - MINIMO_RAND) + MINIMO_RAND);
        swap(claves[i], claves[numero_random]);
    }

    for (unsigned i = 0; i < largo; i++)
    {
        ok &= abb_guardar(abb, claves[i], &valores[i]);
    }
    
    print_test("Cantidad correcta", abb_cantidad(abb) == cantidad);
    print_test("Prueba abb almacenar muchos elementos", ok);

    unsigned i;
    const char *clave;
    size_t *valor;

    abb_iter_t *iter = abb_iter_in_crear(abb);

    for (i = 0; i < largo; i++) {
        if ( abb_iter_in_al_final(iter) ) {
            ok = false;
            break;
        }
        clave = abb_iter_in_ver_actual(iter);
        if ( clave == NULL ) {
            printf("%d\n", i);
            ok = false;
            break;
        }
        valor = abb_obtener(abb, clave);
        if ( valor == NULL ) {
            ok = false;
            break;
        }
        *valor = largo;
        abb_iter_in_avanzar(iter);
    }
    print_test("Prueba abb iteración en volumen", ok);
    print_test("Prueba abb iteración en volumen, recorrio todo el largo", i == largo);
    print_test("Prueba abb iterador esta al final, es true", abb_iter_in_al_final(iter));

    ok = true;
    for (i = 0; i < largo; i++) {
        if ( valores[i] != largo ) {
            ok = false;
            break;
        }
    }
    print_test("Prueba abb iteración en volumen, se cambiaron todo los elementos", ok);

    free(claves);
    abb_iter_in_destruir(iter);
    abb_destruir(abb);
}

bool visitar_suma_pares(const char *clave, void *dato, void *extra) {
    if (*(int *) dato % 2 == 0) 
        *(int *) extra += *(int *) dato;
    return true;
}

bool visitar_sumar_todos(const char *clave, void *dato, void *extra) {
    *(int *) extra += *(int *) dato;
    return true;
}

bool visitar_sumar_corte_simple(const char *clave, void *dato, void *extra) {
    if (strcmp(clave, "G") == 0) return false;
    *(int *) extra += *(int *) dato;
    return true;
}

bool visitar_sumar_corte_rama_izquierda(const char *clave, void *dato, void *extra) {
    if (strcmp(clave, "E") < 0) return false;
    *(int *) extra += *(int *) dato;
    return true;
}

bool visitar_sumar_corte_rama_der_rama_izq(const char *clave, void *dato, void *extra) {
    if (strcmp(clave, "C") == 0) return false;
    *(int *) extra += *(int *) dato;
    return true;
}

static void prueba_abb_iterador_interno(void) {
    /* Creo un abb */
    abb_t *abb = abb_crear(strcmp, NULL);

    /* Creo los datos a usar */
    int vec[LARGO_ARREGLO_INT_7] = {43, 2, 644, 876, 0, 8, 3};
    char *claves[LARGO_STRING] = {"E", "B", "A", "C", "G", "F", "H"};
    // char *vec_ordenado[LARGO_ARREGLO_INT_7] = {"A", "B", "C", "D", "E", "F", "G", "H"};

    bool insertado = true;
    for (size_t i = 0; i < LARGO_STRING; i++) 
        insertado &= abb_guardar(abb, claves[i], &vec[i]);
    
    print_test("Creo un abb", true);
    print_test("Inserto varios elementos", insertado == true);

    int suma = 0;
    abb_in_order(abb, visitar_sumar_todos, &suma);
    print_test("Itero con la funcion visitar que suma los numeros", true);
    print_test("Sumo todos los elementos de el abb", suma == (vec[0] + vec[1] + vec[2] + vec[3] + vec[4] + vec[5] + vec[6]));
    
    int suma_pares = 0;
    abb_in_order(abb, visitar_suma_pares, &suma_pares);
    print_test("Itero con la funcion visitar que suma los numeros pares", true);
    print_test("Sumo todos los elementos de el abb", suma_pares == (vec[1] + vec[2] + vec[3] + vec[4] + vec[5]));

    int extra = 0;
    abb_in_order(abb, NULL, &extra);
    print_test("Itero con la funcion visitar en NULL (no deberia pasar nada)", true);
    print_test("No pasa nada", extra == 0);

    int suma_corte_simple = 0; // Corte simple
    abb_in_order(abb, visitar_sumar_corte_simple, &suma_corte_simple);
    print_test("Itero con la funcion visitar que suma hasta una G", true);
    print_test("Sumo correctamente", suma_corte_simple == vec[0] + vec[1] + vec[2] + vec[3] + vec[5]);

    int suma_corte_izquierda = 0; // Corte rama izq
    abb_in_order(abb, visitar_sumar_corte_rama_izquierda, &suma_corte_izquierda);
    print_test("Itero con la funcion visitar que suma hasta una G", true);
    print_test("Sumo correctamente", suma_corte_izquierda == 0);

    int suma_corte_derecha_izquierda = 0; // Corte rama der de rama izq
    abb_in_order(abb, visitar_sumar_corte_rama_der_rama_izq, &suma_corte_derecha_izquierda);
    print_test("Itero con la funcion visitar que suma hasta una G", true);
    print_test("Sumo correctamente", suma_corte_derecha_izquierda == vec[1] + vec[2]);

    /* Destruyo el abb */
    abb_destruir(abb);
    print_test("Destruyo el abb", true);
}

static int *crear_dato(int a) {
    int *dato = malloc(sizeof(int));
    *dato = a;
    return dato;
}

static void pruebas_varias() {

    int *datos[LARGO_ARREGLO_INT];

    for (int i = 0; i < 6; i++)
        datos[i] = crear_dato(i);

    abb_t* abb = abb_crear(strcmp, free);

    abb_guardar(abb, "hola", datos[0]);
    abb_guardar(abb, "chau", datos[1]);
    abb_guardar(abb, "dormir", datos[2]);

    print_test("dormir pertenece", abb_pertenece(abb, "dormir"));
    print_test("borrar dormir", abb_borrar(abb, "dormir") == datos[2]);
    print_test("borar dormir (NULL)", abb_borrar(abb, "dormir") == NULL);
    print_test("dormir no pertenece", !abb_pertenece(abb, "dormir"));
    print_test("no se puede obtener dormir", abb_obtener(abb, "dormir") == NULL);
    print_test("cantidad es 2", abb_cantidad(abb) == 2);

    print_test("hola pertenece", abb_pertenece(abb, "hola"));
    print_test("borrar hola", abb_borrar(abb, "hola") == datos[0]);
    print_test("borrar hola (NULL)", abb_borrar(abb, "hola") == NULL);
    print_test("hola no pertenece", !abb_pertenece(abb, "hola"));
    print_test("no se puede obtener hola", abb_obtener(abb, "hola") == NULL);
    print_test("cantidad es 1", abb_cantidad(abb) == 1);

    print_test("chau pertenece", abb_pertenece(abb, "chau"));
    print_test("borrar chau", abb_borrar(abb, "chau") == datos[1]);
    print_test("borrar chau (NULL)", abb_borrar(abb, "chau") == NULL);
    print_test("chau no pertenece", !abb_pertenece(abb, "chau"));
    print_test("no se puede obtener chau", abb_obtener(abb, "chau") == NULL);
    print_test("cantidad es 0", abb_cantidad(abb) == 0);
    
    abb_guardar(abb, "hola", datos[3]);
    abb_guardar(abb, "chau", datos[4]);
    abb_guardar(abb, "dormir", datos[5]);

    print_test("", abb_borrar(abb, "hola") == datos[3]);
    print_test("", abb_borrar(abb, "chau") == datos[4]);
    print_test("", abb_borrar(abb, "dormir") == datos[5]);

    abb_destruir(abb);

    for (int i = 0; i < 6; i++)
        free(datos[i]);

}

static void pruebas_borrar_punteros() {

    abb_t *abb = abb_crear(strcmp, free);

    int *datos[LARGO_ARREGLO_INT];

    for (int i = 0; i < LARGO_ARREGLO_INT; i++)
        datos[i] = crear_dato(i + 2);

    print_test("Cantidad es 0", abb_cantidad(abb) == 0);
    abb_guardar(abb, "hola", datos[0]);
    print_test("Cantidad es 1", abb_cantidad(abb) == 1);
    abb_guardar(abb, "chau", datos[1]);
    print_test("Cantidad es 2", abb_cantidad(abb) == 2);
    abb_guardar(abb, "dormir", datos[2]);
    print_test("Cantidad es 3", abb_cantidad(abb) == 3);
    print_test("Borrar 'hola' es !NULL", abb_borrar(abb, "hola") != NULL);
    print_test("Cantidad es 2", abb_cantidad(abb) == 2);
    print_test("Borrar 'hola' es NULL", abb_borrar(abb, "hola") == NULL);
    print_test("Cantidad es 2", abb_cantidad(abb) == 2);
    print_test("Borrar es 'hola' NULL", abb_borrar(abb, "hola") == NULL);
    print_test("Cantidad es 2", abb_cantidad(abb) == 2);
    print_test("Borrar 'chau' es !NULL", abb_borrar(abb, "chau") != NULL);
    print_test("Cantidad es 1", abb_cantidad(abb) == 1);
    print_test("Borrar 'dormir' es !NULL", abb_borrar(abb, "dormir") != NULL);
    print_test("Cantidad es 0", abb_cantidad(abb) == 0);

    abb_destruir(abb);

    for (int i = 0; i < LARGO_ARREGLO_INT; i++)
        free(datos[i]);

}
static void pruebas_abb_iguales_claves_distintas() {

    abb_t *abb = abb_crear(strcmp, free);

    int *datos[LARGO_ARREGLO_INT];

    for (int i = 0; i < LARGO_ARREGLO_INT; i++)
        datos[i] = crear_dato(i + 10);

    // ce y x estan tienen el mismo numero de abb.

    abb_guardar(abb, "ce", datos[5]);
    print_test("Cantidad es 1", abb_cantidad(abb) == 1);
    abb_guardar(abb, "x", datos[4]);
    print_test("Cantidad es 2", abb_cantidad(abb) == 2);
    abb_guardar(abb, "x", datos[3]);
    print_test("Cantidad es 2", abb_cantidad(abb) == 2);
    abb_borrar(abb, "x");
    print_test("Cantidad es 1", abb_cantidad(abb) == 1);
    print_test("No puedo obtener la clave", abb_obtener(abb, "x") == NULL);

    abb_destruir(abb);

    for (int i = 0; i < LARGO_ARREGLO_INT - 2; i++)
        free(datos[i]);
}

static void pruebas_guardar_borrar() {
    abb_t *abb = abb_crear(strcmp, free);

    int *datos[LARGO_ARREGLO_INT];

    for (int i = 0; i < LARGO_ARREGLO_INT; i++)
        datos[i] = crear_dato(i * 100);

    print_test("Cantidad inicial es 0", abb_cantidad(abb) == 0);
    print_test("Guardo datos[0]", abb_guardar(abb, "ce", datos[0]));
    print_test("Cantidad es 1", abb_cantidad(abb) == 1);
    print_test("Guardo datos[1]", abb_guardar(abb, "ce", datos[1]));
    print_test("Cantidad es 1", abb_cantidad(abb) == 1);
    print_test("Guardo datos[2] en 'x'", abb_guardar(abb, "x", datos[2]) == true);
    print_test("Cantidad es 2", abb_cantidad(abb) == 2);
    print_test("Borro 'ce'", abb_borrar(abb, "ce") == datos[1]);
    print_test("Cantidad es 1", abb_cantidad(abb) == 1);
    print_test("Guardo datos[1] en 'ce'", abb_guardar(abb, "ce", datos[1]) == true);
    print_test("Guardo datos[3] en 'ce'", abb_guardar(abb, "ce", datos[3]) == true);
    print_test("Guardo NULL como valor", abb_guardar(abb, "messi", NULL) == true);
    print_test("Guardo \"\"", abb_guardar(abb, "", NULL) == true);

    abb_destruir(abb);

    free(datos[4]);
    free(datos[5]);

}

static int free_count = 0;
static void mi_free(int *dato) {
    free_count++;
    free(dato);
}

static void prueba_destruir_null() {

    abb_t *abb = abb_crear(strcmp, (void (*)(void *))mi_free);

    int *dato = crear_dato(9);

    print_test("Guardo NULL", abb_guardar(abb, "hola", NULL));
    print_test("Reemplazo dato", abb_guardar(abb, "hola", dato));
    abb_destruir(abb);

    print_test("Se invocó el destructor el número esperado de veces", free_count == 2);

}

void pruebas_abb_estudiante() {
    /* Ejecuta todas las pruebas unitarias. */
    prueba_crear_abb_vacio();
    prueba_iterar_abb_vacio();
    prueba_abb_guardar();
    prueba_abb_reemplazar();
    prueba_abb_reemplazar_con_destruir();
    prueba_abb_borrar();
    prueba_abb_clave_vacia();
    prueba_abb_valor_null();
    prueba_abb_volumen(VOLUMEN, true);
    prueba_abb_in_order();
    prueba_abb_in_order_volumen(VOLUMEN);
    prueba_abb_iterador_interno();

    pruebas_varias();
    pruebas_borrar_punteros();
    pruebas_abb_iguales_claves_distintas();
    pruebas_guardar_borrar();

    prueba_destruir_null();
}

void pruebas_volumen_estudiante(size_t largo) {
    prueba_abb_volumen(largo, false);
}