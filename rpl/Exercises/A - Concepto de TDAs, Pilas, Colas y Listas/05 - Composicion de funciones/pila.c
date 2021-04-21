#include "pila.h"

#include <stdlib.h>

/* Definición del struct pila proporcionado por la cátedra.
 */
struct pila {
    void **datos;
    size_t cantidad;   // Cantidad de elementos almacenados.
    size_t capacidad;  // Capacidad del arreglo 'datos'.
};

/* *****************************************************************
 *                    PRIMITIVAS DE LA PILA
 * *****************************************************************/

pila_t *pila_crear(void) {
    pila_t *pila = malloc(sizeof(pila_t));

    if (pila != NULL) {
        pila->cantidad = 0;
        pila->capacidad = 8;
        pila->datos = malloc(sizeof(void *) * pila->capacidad);
        if (pila->datos != NULL) {
            return pila;
        }
        free(pila);
    }

    return NULL;
}

void pila_destruir(pila_t *pila) {
    free(pila->datos);
    free(pila);
}

bool pila_esta_vacia(const pila_t *pila) {
    return !(pila->cantidad);
}

bool pila_apilar(pila_t *pila, void *valor) {
    if (pila->cantidad == pila->capacidad) {
        pila->datos = realloc(pila->datos, sizeof(void *) * (pila->capacidad *= 2));
        if (pila->datos == NULL)
            return false;
    }

    pila->datos[pila->cantidad++] = valor;

    return true;
}

void *pila_ver_tope(const pila_t *pila) {
    return pila->cantidad ? pila->datos[pila->cantidad-1] : NULL;
}

void *pila_desapilar(pila_t *pila) {
    if (pila->cantidad == pila->capacidad / 4) {
        pila->datos = realloc(pila->datos, sizeof(void *) * (pila->capacidad /= 2));
        if (pila->datos == NULL)
            return false;
    }
    
    return pila->cantidad ? pila->datos[--pila->cantidad] : NULL;
}