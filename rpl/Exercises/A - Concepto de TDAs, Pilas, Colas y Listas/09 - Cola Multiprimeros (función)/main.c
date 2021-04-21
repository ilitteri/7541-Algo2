#include "cola.h"

#include <stdlib.h>

void** cola_multiprimeros(const cola_t* cola, size_t k) {
    void **primeros = calloc(k, sizeof(void *));

    cola_t *colaAux;

    if ((colaAux = cola_crear()) == NULL) {
        free(primeros);
        return NULL;
    }

    for (int i = 0; !cola_esta_vacia(cola); i++) {
        void *dato = cola_desencolar(cola);

        if (i < k)
            primeros[i] = dato;
        
        if (!cola_encolar(colaAux, dato)) {
            cola_destruir(colaAux, NULL);
            free(primeros);
            return NULL;
        }
    }

    while (!cola_esta_vacia(colaAux)) {
        if (!cola_encolar(cola, cola_desencolar(colaAux))) {
            cola_destruir(colaAux, NULL);
            return NULL;
        }
    }

    cola_destruir(colaAux, NULL);

    return primeros;
}