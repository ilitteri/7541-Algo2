#include <stddef.h> 
#include "invertir_arreglo.h"

#include "pila.h"

/*
void invertir_arreglo(void** arreglo, size_t n) {

    pila_t *pila = pila_crear();

    if (pila != NULL) {
        size_t i;
        for (i = 0; i < n; pila_apilar(pila, arreglo[i++]));

        i = 0;
        while (!pila_esta_vacia(pila))
            arreglo[i++] = pila_desapilar(pila);
        pila_destruir(pila);
    }
    return NULL;
}
*/

#include <stddef.h> 
#include "invertir_arreglo.h"

#include "pila.h"

void invertir_arreglo(void** arreglo, size_t n) {

    pila_t *pila = pila_crear();

    for (size_t i = 0; i < n; pila_apilar(pila, arreglo[i++]));

    for (size_t i = 0; i < n; arreglo[i++] = pila_desapilar(pila));

    pila_destruir(pila);
}

// #include <stddef.h> 
// #include "invertir_arreglo.h"

// #include "pila.h"

// void invertir_arreglo(void** arreglo, size_t n) {
//     pila_t *pila = pila_crear();

//     size_t i;

//     for (i = 0; i < n; pila_apilar(pila, arreglo[i++]));

//     for (i = 0; (arreglo[i++] = pila_desapilar(pila)););

//     pila_destruir(pila);
// }
