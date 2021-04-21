#include <criterion/criterion.h>  // No borrar esto!
#include "ab.h"  // Modificar con el nombre de la api que se le entrega al alumno!
#include <stddef.h>

Test(misc, arbol_nulo) {
    cr_assert(ab_altura(NULL) == 0);
}

Test(misc, arbol_solo_raiz) {
    ab_t* ab = ab_crear();
    cr_assert(ab_altura(ab) == 1);
    ab_destruir(ab);
}

Test(misc, arbol_solo_un_lado) {
    ab_t* ab = ab_crear();
    ab->izq = ab_crear();
    ab->izq->izq = ab_crear();
    ab->izq->izq->izq = ab_crear();
    cr_assert(ab_altura(ab) == 4);
    ab_destruir(ab);
}

Test(misc, arbol_completo) {
    ab_t* ab = ab_crear();
    ab->izq = ab_crear();
    ab->der = ab_crear();
    ab->izq->izq = ab_crear();
    ab->izq->der = ab_crear();
    ab->der->izq = ab_crear();
    ab->der->der = ab_crear();
    cr_assert(ab_altura(ab) == 3);
    ab_destruir(ab);
}

Test(misc, arbol_zig_zag) {
    ab_t* ab = ab_crear();
    ab->izq = ab_crear();
    ab->izq->der = ab_crear();
    ab->izq->der->izq = ab_crear();
    ab->izq->der->izq->der = ab_crear();
    cr_assert(ab_altura(ab) == 5);
    ab_destruir(ab);
}

Test(misc, arbol_diverso) {
    ab_t* ab = ab_crear();
    ab->izq = ab_crear();
    ab->der = ab_crear();
    ab->izq->izq = ab_crear();
    ab->izq->der = ab_crear();
    ab->der->der = ab_crear();
    ab->der->der->izq = ab_crear();
    cr_assert(ab_altura(ab) == 4);
    ab_destruir(ab);
}