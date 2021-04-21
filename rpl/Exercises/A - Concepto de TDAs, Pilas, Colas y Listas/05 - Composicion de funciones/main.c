#include <stdlib.h>
#include <stdbool.h>

#include "composicion_funciones.h"
#include "pila.h"

struct composicion {
    pila_t *pila_funciones;
};

composicion_t* composicion_crear() {
    composicion_t *composicion;

    if ((composicion = malloc(sizeof(composicion))) == NULL)
        return NULL;
    
    if ((composicion->pila_funciones = pila_crear()) == NULL) {
        free(composicion);
        return NULL;
    }

    return composicion;
}

void composicion_destruir(composicion_t* composicion) {
    pila_destruir(composicion->pila_funciones);
    free(composicion);
}

bool composicion_agregar_funcion(composicion_t* composicion, funcion_t f) {
    return pila_apilar(composicion->pila_funciones, (void *) f);
}

double composicion_aplicar(composicion_t* composicion, double x) {
    double res = x;

    while(!pila_esta_vacia(composicion->pila_funciones))
        res = ((funcion_t) pila_desapilar(composicion->pila_funciones)) (res);
    
    return res;
}