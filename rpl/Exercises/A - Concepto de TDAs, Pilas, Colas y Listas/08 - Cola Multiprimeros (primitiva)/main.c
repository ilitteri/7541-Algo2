#include "cola.h"
#include "cola_struct.h"

#include <stdlib.h>

void** cola_multiprimeros(const cola_t* cola, size_t k) {
    void **primeros = calloc(k, sizeof(void *));

    if (primeros == NULL)
        return NULL;
    
    nodo_t *actual = cola->prim;

    for (size_t i = 0; i < k && actual != NULL;) {
        primeros[i++] = actual->dato;
        actual = actual->sig;
    }

    return primeros;
}