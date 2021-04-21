// Implementar para un árbol binario una primitiva lista_t* ab_primos_datos(const ab_t* ab, void* dato_buscado)
// que devuelva los datos de los nodos primos a uno que se esté buscando. Dos nodos son primos si se encuentran en el mismo
// nivel dentro del árbol. Por simplificación, considerar que dos nodos hermanos (i.e. tienen mismo padre) son también primos.
// Suponer que en el árbol no hay elementos repetidos, y que se puede comparar los punteros por igualdad de dirección de
// memoria apuntada. En caso de no encontrarse el elemento, devolver una lista vacía. Indicar y justificar la complejidad de la
// primitiva implementada. A efectos del ejercicio, la estructura del árbol es:
// typedef struct ab {
//     struct ab* izq;
//     struct ab* der;
//     void* dato;
// } ab_t;

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "abb.h"
#include "lista.h"
#include "cola.h"

typedef struct ab {
    struct ab* izq;
    struct ab* der;
    void* dato;
} ab_t;

void niveles(ab_t *actual, lista_t *datos_buscados, void *dato_buscado, size_t nivel) {
    // Si no hay ab entonces no hay lista con datos.
    if (actual == NULL) 
        return NULL;

    // Define la cola, en donde se encolaran los elementos
    cola_t *abs;

    // Asigna memoria a la cola, si no lo logra, devuelve NULL
    if ((abs = cola_crear()) == NULL)
        return NULL;

    cola_encolar(actual);

    while (!cola_esta_vacia()):
        ab = cola_desencolar(abs);

        lista_insertar_ultimo(datos_buscado, ab->dato);

        if (ab->izq != NULL) {
            cola_encolar(ab->izq);
        if (ab->der != NULL)
            cola_encolar(ab->der);
}

lista_t *ab_primos_datos(const ab_t *ab, void *dato_buscado) {
    // Si no hay ab entonces no hay lista con datos.
    if (ab == NULL)
        return NULL;

    // Crea la lista de datos buscados.
    lista_t *datos_buscados;

    // Asigna memoria a la lista, si no lo logra, devuelve NULL.
    if ((datos_buscados = lista_crear()) == NULL)
        return NULL;

    // Recorro el arbol por niveles.
    niveles(ab, dato_buscado, 0);

    return datos_buscados;
}