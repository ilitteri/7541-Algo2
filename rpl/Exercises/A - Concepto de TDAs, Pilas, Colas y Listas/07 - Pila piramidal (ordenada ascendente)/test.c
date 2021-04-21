#include <criterion/criterion.h>  // No borrar esto!
#include "main.h"  // Modificar con el nombre de la api que se le entrega al alumno!

Test(misc, test_pila_piramidal) {
    pila_t* pila = pila_crear();
    int elementos[4] = {1,2,3,4};
    pila_apilar(pila, (void*) &elementos[3]);
    pila_apilar(pila, (void*) &elementos[2]);
    pila_apilar(pila, (void*) &elementos[1]);
    pila_apilar(pila, (void*) &elementos[0]);
    cr_assert(pila_es_piramidal(pila));
    pila_destruir(pila);
}

Test(misc, test_pila_no_piramidal) {
    pila_t* pila = pila_crear();
    int elementos[4] = {1,4,3,2};
    pila_apilar(pila, (void*) &elementos[3]);
    pila_apilar(pila, (void*) &elementos[2]);
    pila_apilar(pila, (void*) &elementos[1]);
    pila_apilar(pila, (void*) &elementos[0]);
    cr_assert(!pila_es_piramidal(pila));
    pila_destruir(pila);
}

Test(misc, test_pila_no_piramidal_iguales) {
    pila_t* pila = pila_crear();
    int elementos[4] = {4,4,4,4};
    pila_apilar(pila, (void*) &elementos[3]);
    pila_apilar(pila, (void*) &elementos[2]);
    pila_apilar(pila, (void*) &elementos[1]);
    pila_apilar(pila, (void*) &elementos[0]);
    cr_assert(!pila_es_piramidal(pila));
    pila_destruir(pila);
}


