#include "main.h"

/* viborita */

bool pila_es_piramidal(pila_t* pila) {
    pila_t *pilaTemp = pila_crear();

    bool es_piramidal = true;

    while (!pila_esta_vacia(pila)) {
        int *temp = pila_desapilar(pila);
        
        if (!pila_esta_vacia(pilaTemp) && *(int *)pila_ver_tope(pilaTemp) >= *temp)
            es_piramidal = false;
        pila_apilar(pilaTemp, temp);
    }

    while(!pila_esta_vacia(pilaTemp))
        pila_apilar(pila, pila_desapilar(pilaTemp));

    pila_destruir(pilaTemp);

    return es_piramidal;
}