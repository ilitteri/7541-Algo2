/*
 * prueba_hash.c
 * Pruebas para el tipo de dato abstracto Tabla de Hash
 * Copyright: (2011) Margarita Manterola, Maximiliano Curia
 * Licencia: CC-BY-SA 2.5 (ar) ó CC-BY-SA 3.0
 */

#include "hash.h"
#include "testing.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>  // For ssize_t in Linux.

#define VOLUMEN 5000  
#define LARGO_ARREGLO_INT 6


/* ******************************************************************
 *                        PRUEBAS UNITARIAS
 * *****************************************************************/

static void prueba_crear_hash_vacio()
{
    hash_t* hash = hash_crear(NULL);

    print_test("Prueba hash crear hash vacio", hash);
    print_test("Prueba hash la cantidad de elementos es 0", hash_cantidad(hash) == 0);
    print_test("Prueba hash obtener clave A, es NULL, no existe", !hash_obtener(hash, "A"));
    print_test("Prueba hash pertenece clave A, es false, no existe", !hash_pertenece(hash, "A"));
    print_test("Prueba hash borrar clave A, es NULL, no existe", !hash_borrar(hash, "A"));

    hash_destruir(hash);
}

static void prueba_iterar_hash_vacio()
{
    hash_t* hash = hash_crear(NULL);
    hash_iter_t* iter = hash_iter_crear(hash);
    print_test("Prueba hash iter crear iterador hash vacio", iter);
    print_test("Prueba hash iter esta al final", hash_iter_al_final(iter));
    print_test("Prueba hash iter avanzar es false", !hash_iter_avanzar(iter));
    print_test("Prueba hash iter ver actual es NULL", !hash_iter_ver_actual(iter));

    hash_iter_destruir(iter);
    hash_destruir(hash);
}

static void prueba_hash_insertar()
{
    hash_t* hash = hash_crear(NULL);

    char *clave1 = "perro", *valor1 = "guau";
    char *clave2 = "gato", *valor2 = "miau";
    char *clave3 = "vaca", *valor3 = "mu";

    /* Inserta 1 valor y luego lo borra */
    print_test("Prueba hash insertar clave1", hash_guardar(hash, clave1, valor1));
    print_test("Prueba hash la cantidad de elementos es 1", hash_cantidad(hash) == 1);
    print_test("Prueba hash obtener clave1 es valor1", hash_obtener(hash, clave1) == valor1);
    print_test("Prueba hash obtener clave1 es valor1", hash_obtener(hash, clave1) == valor1);
    print_test("Prueba hash pertenece clave1, es true", hash_pertenece(hash, clave1));
    print_test("Prueba hash borrar clave1, es valor1", hash_borrar(hash, clave1) == valor1);
    print_test("Prueba hash la cantidad de elementos es 0", hash_cantidad(hash) == 0);

    /* Inserta otros 2 valores y no los borra (se destruyen con el hash) */
    print_test("Prueba hash insertar clave2", hash_guardar(hash, clave2, valor2));
    print_test("Prueba hash la cantidad de elementos es 1", hash_cantidad(hash) == 1);
    print_test("Prueba hash obtener clave2 es valor2", hash_obtener(hash, clave2) == valor2);
    print_test("Prueba hash obtener clave2 es valor2", hash_obtener(hash, clave2) == valor2);
    print_test("Prueba hash pertenece clave2, es true", hash_pertenece(hash, clave2));

    print_test("Prueba hash insertar clave3", hash_guardar(hash, clave3, valor3));
    print_test("Prueba hash la cantidad de elementos es 2", hash_cantidad(hash) == 2);
    print_test("Prueba hash obtener clave3 es valor3", hash_obtener(hash, clave3) == valor3);
    print_test("Prueba hash obtener clave3 es valor3", hash_obtener(hash, clave3) == valor3);
    print_test("Prueba hash pertenece clave3, es true", hash_pertenece(hash, clave3));

    hash_destruir(hash);
}

static void prueba_hash_reemplazar()
{
    hash_t* hash = hash_crear(NULL);

    char *clave1 = "perro", *valor1a = "guau", *valor1b = "warf";
    char *clave2 = "gato", *valor2a = "miau", *valor2b = "meaow";

    /* Inserta 2 valores y luego los reemplaza */
    print_test("Prueba hash insertar clave1", hash_guardar(hash, clave1, valor1a));
    print_test("Prueba hash obtener clave1 es valor1a", hash_obtener(hash, clave1) == valor1a);
    print_test("Prueba hash obtener clave1 es valor1a", hash_obtener(hash, clave1) == valor1a);
    print_test("Prueba hash insertar clave2", hash_guardar(hash, clave2, valor2a));
    print_test("Prueba hash obtener clave2 es valor2a", hash_obtener(hash, clave2) == valor2a);
    print_test("Prueba hash obtener clave2 es valor2a", hash_obtener(hash, clave2) == valor2a);
    print_test("Prueba hash la cantidad de elementos es 2", hash_cantidad(hash) == 2);

    print_test("Prueba hash insertar clave1 con otro valor", hash_guardar(hash, clave1, valor1b));
    print_test("Prueba hash obtener clave1 es valor1b", hash_obtener(hash, clave1) == valor1b);
    print_test("Prueba hash obtener clave1 es valor1b", hash_obtener(hash, clave1) == valor1b);
    print_test("Prueba hash insertar clave2 con otro valor", hash_guardar(hash, clave2, valor2b));
    print_test("Prueba hash obtener clave2 es valor2b", hash_obtener(hash, clave2) == valor2b);
    print_test("Prueba hash obtener clave2 es valor2b", hash_obtener(hash, clave2) == valor2b);
    print_test("Prueba hash la cantidad de elementos es 2", hash_cantidad(hash) == 2);

    hash_destruir(hash);
}

static void prueba_hash_reemplazar_con_destruir()
{
    hash_t* hash = hash_crear(free);

    char *clave1 = "perro", *valor1a, *valor1b;
    char *clave2 = "gato", *valor2a, *valor2b;

    /* Pide memoria para 4 valores */
    valor1a = malloc(10 * sizeof(char));
    valor1b = malloc(10 * sizeof(char));
    valor2a = malloc(10 * sizeof(char));
    valor2b = malloc(10 * sizeof(char));

    /* Inserta 2 valores y luego los reemplaza (debe liberar lo que reemplaza) */
    print_test("Prueba hash insertar clave1", hash_guardar(hash, clave1, valor1a));
    print_test("Prueba hash obtener clave1 es valor1a", hash_obtener(hash, clave1) == valor1a);
    print_test("Prueba hash obtener clave1 es valor1a", hash_obtener(hash, clave1) == valor1a);
    print_test("Prueba hash insertar clave2", hash_guardar(hash, clave2, valor2a));
    print_test("Prueba hash obtener clave2 es valor2a", hash_obtener(hash, clave2) == valor2a);
    print_test("Prueba hash obtener clave2 es valor2a", hash_obtener(hash, clave2) == valor2a);
    print_test("Prueba hash la cantidad de elementos es 2", hash_cantidad(hash) == 2);

    print_test("Prueba hash insertar clave1 con otro valor", hash_guardar(hash, clave1, valor1b));
    print_test("Prueba hash obtener clave1 es valor1b", hash_obtener(hash, clave1) == valor1b);
    print_test("Prueba hash obtener clave1 es valor1b", hash_obtener(hash, clave1) == valor1b);
    print_test("Prueba hash insertar clave2 con otro valor", hash_guardar(hash, clave2, valor2b));
    print_test("Prueba hash obtener clave2 es valor2b", hash_obtener(hash, clave2) == valor2b);
    print_test("Prueba hash obtener clave2 es valor2b", hash_obtener(hash, clave2) == valor2b);
    print_test("Prueba hash la cantidad de elementos es 2", hash_cantidad(hash) == 2);

    /* Se destruye el hash (se debe liberar lo que quedó dentro) */
    hash_destruir(hash);
}

static void prueba_hash_borrar()
{
    hash_t* hash = hash_crear(NULL);

    char *clave1 = "perro", *valor1 = "guau";
    char *clave2 = "gato", *valor2 = "miau";
    char *clave3 = "vaca", *valor3 = "mu";

    /* Inserta 3 valores y luego los borra */
    print_test("Prueba hash insertar clave1", hash_guardar(hash, clave1, valor1));
    print_test("Prueba hash insertar clave2", hash_guardar(hash, clave2, valor2));
    print_test("Prueba hash insertar clave3", hash_guardar(hash, clave3, valor3));

    /* Al borrar cada elemento comprueba que ya no está pero los otros sí. */
    print_test("Prueba hash pertenece clave3, es verdadero", hash_pertenece(hash, clave3));
    print_test("Prueba hash borrar clave3, es valor3", hash_borrar(hash, clave3) == valor3);
    print_test("Prueba hash borrar clave3, es NULL", !hash_borrar(hash, clave3));
    print_test("Prueba hash pertenece clave3, es falso", !hash_pertenece(hash, clave3));
    print_test("Prueba hash obtener clave3, es NULL", !hash_obtener(hash, clave3));
    print_test("Prueba hash la cantidad de elementos es 2", hash_cantidad(hash) == 2);

    print_test("Prueba hash pertenece clave1, es verdadero", hash_pertenece(hash, clave1));
    print_test("Prueba hash borrar clave1, es valor1", hash_borrar(hash, clave1) == valor1);
    print_test("Prueba hash borrar clave1, es NULL", !hash_borrar(hash, clave1));
    print_test("Prueba hash pertenece clave1, es falso", !hash_pertenece(hash, clave1));
    print_test("Prueba hash obtener clave1, es NULL", !hash_obtener(hash, clave1));
    print_test("Prueba hash la cantidad de elementos es 1", hash_cantidad(hash) == 1);

    print_test("Prueba hash pertenece clave2, es verdadero", hash_pertenece(hash, clave2));
    print_test("Prueba hash borrar clave2, es valor2", hash_borrar(hash, clave2) == valor2);
    print_test("Prueba hash borrar clave2, es NULL", !hash_borrar(hash, clave2));
    print_test("Prueba hash pertenece clave2, es falso", !hash_pertenece(hash, clave2));
    print_test("Prueba hash obtener clave2, es NULL", !hash_obtener(hash, clave2));
    print_test("Prueba hash la cantidad de elementos es 0", hash_cantidad(hash) == 0);

    hash_destruir(hash);
}

static void prueba_hash_clave_vacia()
{
    hash_t* hash = hash_crear(NULL);

    char *clave = "", *valor = "";

    print_test("Prueba hash insertar clave vacia", hash_guardar(hash, clave, valor));
    print_test("Prueba hash la cantidad de elementos es 1", hash_cantidad(hash) == 1);
    print_test("Prueba hash obtener clave vacia es valor", hash_obtener(hash, clave) == valor);
    print_test("Prueba hash pertenece clave vacia, es true", hash_pertenece(hash, clave));
    print_test("Prueba hash borrar clave vacia, es valor", hash_borrar(hash, clave) == valor);
    print_test("Prueba hash la cantidad de elementos es 0", hash_cantidad(hash) == 0);

    hash_destruir(hash);
}

static void prueba_hash_valor_null()
{
    hash_t* hash = hash_crear(NULL);

    char *clave = "", *valor = NULL;

    /* Inserta 1 valor y luego lo borra */
    print_test("Prueba hash insertar clave vacia valor NULL", hash_guardar(hash, clave, valor));
    print_test("Prueba hash la cantidad de elementos es 1", hash_cantidad(hash) == 1);
    print_test("Prueba hash obtener clave vacia es valor NULL", hash_obtener(hash, clave) == valor);
    print_test("Prueba hash pertenece clave vacia, es true", hash_pertenece(hash, clave));
    print_test("Prueba hash borrar clave vacia, es valor NULL", hash_borrar(hash, clave) == valor);
    print_test("Prueba hash la cantidad de elementos es 0", hash_cantidad(hash) == 0);

    hash_destruir(hash);
}

static void prueba_hash_volumen(size_t largo, bool debug)
{
    hash_t* hash = hash_crear(NULL);

    const size_t largo_clave = 10;
    char (*claves)[largo_clave] = malloc(largo * largo_clave);

    unsigned* valores[largo];

    /* Inserta 'largo' parejas en el hash */
    bool ok = true;
    for (unsigned i = 0; i < largo; i++) {
        valores[i] = malloc(sizeof(int));
        sprintf(claves[i], "%08d", i);
        *valores[i] = i;
        ok = hash_guardar(hash, claves[i], valores[i]);
        if (!ok) break;
    }

    if (debug) print_test("Prueba hash almacenar muchos elementos", ok);
    if (debug) print_test("Prueba hash la cantidad de elementos es correcta", hash_cantidad(hash) == largo);

    /* Verifica que devuelva los valores correctos */
    for (size_t i = 0; i < largo; i++) {
        ok = hash_pertenece(hash, claves[i]);
        if (!ok) break;
        ok = hash_obtener(hash, claves[i]) == valores[i];
        if (!ok) break;
    }

    if (debug) print_test("Prueba hash pertenece y obtener muchos elementos", ok);
    if (debug) print_test("Prueba hash la cantidad de elementos es correcta", hash_cantidad(hash) == largo);

    /* Verifica que borre y devuelva los valores correctos */
    for (size_t i = 0; i < largo; i++) {
        ok = hash_borrar(hash, claves[i]) == valores[i];
        if (!ok) break;
    }

    if (debug) print_test("Prueba hash borrar muchos elementos", ok);
    if (debug) print_test("Prueba hash la cantidad de elementos es 0", hash_cantidad(hash) == 0);

    /* Destruye el hash y crea uno nuevo que sí libera */
    hash_destruir(hash);
    hash = hash_crear(free);

    /* Inserta 'largo' parejas en el hash */
    ok = true;
    for (size_t i = 0; i < largo; i++) {
        ok = hash_guardar(hash, claves[i], valores[i]);
        if (!ok) break;
    }

    free(claves);

    /* Destruye el hash - debería liberar los enteros */
    hash_destruir(hash);

}

static ssize_t buscar(const char* clave, char* claves[], size_t largo)
{
    for (size_t i = 0; i < largo; i++) {
        if (strcmp(clave, claves[i]) == 0) return (ssize_t) i;
    }
    return -1;
}

static void prueba_hash_iterar()
{
    hash_t* hash = hash_crear(NULL);

    char *claves[] = {"perro", "gato", "vaca"};
    char *valores[] = {"guau", "miau", "mu"};

    /* Inserta 3 valores */
    print_test("Prueba hash insertar clave1", hash_guardar(hash, claves[0], valores[0]));
    print_test("Prueba hash insertar clave2", hash_guardar(hash, claves[1], valores[1]));
    print_test("Prueba hash insertar clave3", hash_guardar(hash, claves[2], valores[2]));

    // Prueba de iteración sobre las claves almacenadas.
    hash_iter_t* iter = hash_iter_crear(hash);
    const char *clave;
    ssize_t indice;

    print_test("Prueba hash iterador esta al final, es false", !hash_iter_al_final(iter));

    /* Primer valor */
    clave = hash_iter_ver_actual(iter);
    indice = buscar(clave, claves, sizeof(claves) / sizeof(char *));
    print_test("Prueba hash iterador ver actual, es una clave valida", indice != -1);
    print_test("Prueba hash iterador ver actual, no es el mismo puntero", clave != claves[indice]);
    print_test("Prueba hash iterador avanzar es true", hash_iter_avanzar(iter));
    print_test("Prueba hash iterador esta al final, es false", !hash_iter_al_final(iter));

    /* Segundo valor */
    clave = hash_iter_ver_actual(iter);
    indice = buscar(clave, claves, sizeof(claves) / sizeof(char *));
    print_test("Prueba hash iterador ver actual, es una clave valida", indice != -1);
    print_test("Prueba hash iterador ver actual, no es el mismo puntero", clave != claves[indice]);
    print_test("Prueba hash iterador avanzar es true", hash_iter_avanzar(iter));
    print_test("Prueba hash iterador esta al final, es false", !hash_iter_al_final(iter));

    /* Tercer valor */
    clave = hash_iter_ver_actual(iter);
    indice = buscar(clave, claves, sizeof(claves) / sizeof(char *));
    print_test("Prueba hash iterador ver actual, es una clave valida", indice != -1);
    print_test("Prueba hash iterador ver actual, no es el mismo puntero", clave != claves[indice]);
    hash_iter_avanzar(iter);
    print_test("Prueba hash iterador esta al final, es true", hash_iter_al_final(iter));

    /* Vuelve a tratar de avanzar, por las dudas */
    print_test("Prueba hash iterador ver actual, es NULL", !hash_iter_ver_actual(iter));
    print_test("Prueba hash iterador avanzar es false", !hash_iter_avanzar(iter));
    print_test("Prueba hash iterador esta al final, es true", hash_iter_al_final(iter));

    hash_iter_destruir(iter);
    hash_destruir(hash);
}

static void prueba_hash_iterar_volumen(size_t largo)
{
    hash_t* hash = hash_crear(NULL);

    const size_t largo_clave = 10;
    char (*claves)[largo_clave] = malloc(largo * largo_clave);

    size_t valores[largo];

    /* Inserta 'largo' parejas en el hash */
    bool ok = true;
    for (unsigned i = 0; i < largo; i++) {
        sprintf(claves[i], "%08d", i);
        valores[i] = i;
        ok = hash_guardar(hash, claves[i], &valores[i]);
        if (!ok) break;
    }

    // Prueba de iteración sobre las claves almacenadas.
    hash_iter_t* iter = hash_iter_crear(hash);
    print_test("Prueba hash iterador esta al final, es false", !hash_iter_al_final(iter));

    ok = true;
    unsigned i;
    const char *clave;
    size_t *valor;

    for (i = 0; i < largo; i++) {
        if ( hash_iter_al_final(iter) ) {
            ok = false;
            break;
        }
        clave = hash_iter_ver_actual(iter);
        if ( clave == NULL ) {
            printf("%d\n", i);
            ok = false;
            break;
        }
        valor = hash_obtener(hash, clave);
        if ( valor == NULL ) {
            ok = false;
            break;
        }
        *valor = largo;
        hash_iter_avanzar(iter);
    }
    print_test("Prueba hash iteración en volumen", ok);
    print_test("Prueba hash iteración en volumen, recorrio todo el largo", i == largo);
    print_test("Prueba hash iterador esta al final, es true", hash_iter_al_final(iter));

    ok = true;
    for (i = 0; i < largo; i++) {
        if ( valores[i] != largo ) {
            ok = false;
            break;
        }
    }
    print_test("Prueba hash iteración en volumen, se cambiaron todo los elementos", ok);

    free(claves);
    hash_iter_destruir(iter);
    hash_destruir(hash);
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

    hash_t* hash = hash_crear(free);

    hash_guardar(hash, "hola", datos[0]);
    hash_guardar(hash, "chau", datos[1]);
    hash_guardar(hash, "dormir", datos[2]);

    print_test("dormir pertenece", hash_pertenece(hash, "dormir"));
    print_test("borrar dormir", hash_borrar(hash, "dormir") == datos[2]);
    print_test("borar dormir (NULL)", hash_borrar(hash, "dormir") == NULL);
    print_test("dormir no pertenece", !hash_pertenece(hash, "dormir"));
    print_test("no se puede obtener dormir", hash_obtener(hash, "dormir") == NULL);
    print_test("cantidad es 2", hash_cantidad(hash) == 2);

    print_test("hola pertenece", hash_pertenece(hash, "hola"));
    print_test("borrar hola", hash_borrar(hash, "hola") == datos[0]);
    print_test("borrar hola (NULL)", hash_borrar(hash, "hola") == NULL);
    print_test("hola no pertenece", !hash_pertenece(hash, "hola"));
    print_test("no se puede obtener hola", hash_obtener(hash, "hola") == NULL);
    print_test("cantidad es 1", hash_cantidad(hash) == 1);

    print_test("chau pertenece", hash_pertenece(hash, "chau"));
    print_test("borrar chau", hash_borrar(hash, "chau") == datos[1]);
    print_test("borrar chau (NULL)", hash_borrar(hash, "chau") == NULL);
    print_test("chau no pertenece", !hash_pertenece(hash, "chau"));
    print_test("no se puede obtener chau", hash_obtener(hash, "chau") == NULL);
    print_test("cantidad es 0", hash_cantidad(hash) == 0);
    
    hash_guardar(hash, "hola", datos[3]);
    hash_guardar(hash, "chau", datos[4]);
    hash_guardar(hash, "dormir", datos[5]);

    print_test("", hash_borrar(hash, "hola") == datos[3]);
    print_test("", hash_borrar(hash, "chau") == datos[4]);
    print_test("", hash_borrar(hash, "dormir") == datos[5]);

    hash_destruir(hash);

    for (int i = 0; i < 6; i++)
        free(datos[i]);

}

static void pruebas_borrar_punteros() {

    hash_t *hash = hash_crear(free);

    int *datos[LARGO_ARREGLO_INT];

    for (int i = 0; i < LARGO_ARREGLO_INT; i++)
        datos[i] = crear_dato(i + 2);

    print_test("Cantidad es 0", hash_cantidad(hash) == 0);
    hash_guardar(hash, "hola", datos[0]);
    print_test("Cantidad es 1", hash_cantidad(hash) == 1);
    hash_guardar(hash, "chau", datos[1]);
    print_test("Cantidad es 2", hash_cantidad(hash) == 2);
    hash_guardar(hash, "dormir", datos[2]);
    print_test("Cantidad es 3", hash_cantidad(hash) == 3);
    print_test("Borrar 'hola' es !NULL", hash_borrar(hash, "hola") != NULL);
    print_test("Cantidad es 2", hash_cantidad(hash) == 2);
    print_test("Borrar 'hola' es NULL", hash_borrar(hash, "hola") == NULL);
    print_test("Cantidad es 2", hash_cantidad(hash) == 2);
    print_test("Borrar es 'hola' NULL", hash_borrar(hash, "hola") == NULL);
    print_test("Cantidad es 2", hash_cantidad(hash) == 2);
    print_test("Borrar 'chau' es !NULL", hash_borrar(hash, "chau") != NULL);
    print_test("Cantidad es 1", hash_cantidad(hash) == 1);
    print_test("Borrar 'dormir' es !NULL", hash_borrar(hash, "dormir") != NULL);
    print_test("Cantidad es 0", hash_cantidad(hash) == 0);

    hash_destruir(hash);

    for (int i = 0; i < LARGO_ARREGLO_INT; i++)
        free(datos[i]);

}
static void pruebas_hash_iguales_claves_distintas() {

    hash_t *hash = hash_crear(free);

    int *datos[LARGO_ARREGLO_INT];

    for (int i = 0; i < LARGO_ARREGLO_INT; i++)
        datos[i] = crear_dato(i + 10);

    // ce y x estan tienen el mismo numero de hash.

    hash_guardar(hash, "ce", datos[5]);
    print_test("Cantidad es 1", hash_cantidad(hash) == 1);
    hash_guardar(hash, "x", datos[4]);
    print_test("Cantidad es 2", hash_cantidad(hash) == 2);
    hash_guardar(hash, "x", datos[3]);
    print_test("Cantidad es 2", hash_cantidad(hash) == 2);
    hash_borrar(hash, "x");
    print_test("Cantidad es 1", hash_cantidad(hash) == 1);
    print_test("No puedo obtener la clave", hash_obtener(hash, "x") == NULL);

    hash_destruir(hash);

    for (int i = 0; i < LARGO_ARREGLO_INT - 2; i++)
        free(datos[i]);
}

static void pruebas_guardar_borrar() {
    hash_t *hash = hash_crear(free);

    int *datos[LARGO_ARREGLO_INT];

    for (int i = 0; i < LARGO_ARREGLO_INT; i++)
        datos[i] = crear_dato(i * 100);

    print_test("Cantidad inicial es 0", hash_cantidad(hash) == 0);
    hash_guardar(hash, "ce", datos[0]);
    print_test("Cantidad es 1", hash_cantidad(hash) == 1);
    hash_guardar(hash, "ce", datos[1]);
    print_test("Cantidad es 1", hash_cantidad(hash) == 1);
    print_test("Guardo datos[2] en 'x'", hash_guardar(hash, "x", datos[2]));
    print_test("Cantidad es 2", hash_cantidad(hash) == 2);
    print_test("Borro 'ce'", hash_borrar(hash, "ce") == datos[1]);
    print_test("Cantidad es 1", hash_cantidad(hash) == 1);
    print_test("Guardo datos[1] en 'ce'", hash_guardar(hash, "ce", datos[1]));
    print_test("Guardo datos[3] en 'ce'", hash_guardar(hash, "ce", datos[3]));
    print_test("Guardo NULL como valor", hash_guardar(hash, "messi", NULL));
    print_test("Guardo \"\"", hash_guardar(hash, "", NULL));

    hash_destruir(hash);

    free(datos[4]);
    free(datos[5]);

}

static int free_count = 0;
static void mi_free(int *dato) {
    free_count++;
    free(dato);
}

static void prueba_destruir_null() {

    hash_t *hash = hash_crear((void (*)(void *))mi_free);

    int *dato = crear_dato(9);

    hash_guardar(hash, "hola", NULL);
    hash_guardar(hash, "hola", dato);
    hash_destruir(hash);

    print_test("Se invocó el destructor el número esperado de veces", free_count == 2);

}

/* ******************************************************************
 *                        FUNCIÓN PRINCIPAL
 * *****************************************************************/


void pruebas_hash_catedra()
{
    /* Ejecuta todas las pruebas unitarias. */
    prueba_crear_hash_vacio();
    prueba_iterar_hash_vacio();
    prueba_hash_insertar();
    prueba_hash_reemplazar();
    prueba_hash_reemplazar_con_destruir();
    prueba_hash_borrar();
    prueba_hash_clave_vacia();
    prueba_hash_valor_null();
    prueba_hash_volumen(VOLUMEN, true);
    prueba_hash_iterar();
    prueba_hash_iterar_volumen(VOLUMEN);

    pruebas_varias();
    pruebas_borrar_punteros();
    pruebas_hash_iguales_claves_distintas();
    pruebas_guardar_borrar();

    prueba_destruir_null();
}

void pruebas_volumen_catedra(size_t largo)
{
    prueba_hash_volumen(largo, false);
}
