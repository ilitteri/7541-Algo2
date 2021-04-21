#include <criterion/criterion.h>  // No borrar esto!
#include "ab.h"  // Modificar con el nombre de la api que se le entrega al alumno!
#include <stddef.h>

Test(misc, arbol_vacio) {
    cr_assert(ab_suma(NULL) == 0);
}

Test(misc, arbol_raiz) {
    ab_t* ab = ab_crear(5);
    cr_assert(ab_suma(ab) == 5);
    ab_destruir(ab);
}


Test(misc, arbol_completo) {
    ab_t* ab = ab_crear(5);
    ab->izq = ab_crear(7);
    ab->izq->izq = ab_crear(-3);
    ab->izq->der = ab_crear(19);
    ab->der = ab_crear(11);
    ab->der->izq = ab_crear(0);
    ab->der->der = ab_crear(-13);
    cr_assert(ab_suma(ab) == 26);
    ab_destruir(ab);
}

Test(misc, arbol_variado) {
    ab_t* ab = ab_crear(5);
    ab->izq = ab_crear(7);
    ab->izq->izq = ab_crear(-3);
    ab->izq->izq->izq = ab_crear(19);
    ab->der = ab_crear(11);
    ab->der->izq = ab_crear(0);
    ab->der->der = ab_crear(-13);
    ab->der->der->izq = ab_crear(6);
    cr_assert(ab_suma(ab) == 32);
    ab_destruir(ab);
}
