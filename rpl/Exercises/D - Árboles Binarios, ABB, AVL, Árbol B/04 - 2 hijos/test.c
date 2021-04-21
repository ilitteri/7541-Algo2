#include <criterion/criterion.h>  // No borrar esto!
#include "ab.h"  // Modificar con el nombre de la api que se le entrega al alumno!
#include <stddef.h>

Test(misc, arbol_vacio) {
    cr_assert(ab_2_hijos(NULL) == 0);
}

Test(misc, arbol_raiz) {
    ab_t* ab = ab_crear();
    cr_assert(ab_2_hijos(ab) == 0);
    ab_destruir(ab);
}


Test(misc, arbol_completo) {
    ab_t* ab = ab_crear();
    ab->izq = ab_crear();
    ab->izq->izq = ab_crear();
    ab->izq->der = ab_crear();
    ab->der = ab_crear();
    ab->der->izq = ab_crear();
    ab->der->der = ab_crear();
    cr_assert(ab_2_hijos(ab) == 3);
    ab_destruir(ab);
}

Test(misc, arbol_variado) {
    ab_t* ab = ab_crear();
    ab->izq = ab_crear();
    ab->izq->izq = ab_crear();
    ab->izq->izq->izq = ab_crear();
    ab->izq->der = ab_crear();
    ab->izq->der->izq = ab_crear();
    ab->izq->der->der = ab_crear();
    ab->izq->der->der->izq = ab_crear();
    cr_assert(ab_2_hijos(ab) == 2);
    ab_destruir(ab);
}