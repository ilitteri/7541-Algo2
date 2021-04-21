#include <criterion/criterion.h>  // No borrar esto!
#include "ab.h"  // Modificar con el nombre de la api que se le entrega al alumno!
#include <stddef.h>

Test(misc, arbol_raiz) {
    ab_t* ab = ab_crear(5);
    ab_invertir(ab);
    cr_assert(ab->dato == 5);
    cr_assert(ab->izq == NULL && ab->der == NULL);
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

    ab_invertir(ab);

    cr_assert(ab->dato == 5);
    cr_assert(ab->der->dato == 7);
    cr_assert(ab->der->der->dato == -3);
    cr_assert(ab->der->izq->dato == 19);
    cr_assert(ab->izq->dato == 11);
    cr_assert(ab->izq->der->dato == 0);
    cr_assert(ab->izq->izq->dato == -13);

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

    ab_invertir(ab);

    cr_assert(ab->dato == 5);
    cr_assert(ab->der->dato == 7);
    cr_assert(ab->der->der->dato == -3);
    cr_assert(ab->der->der->der->dato == 19);
    cr_assert(ab->izq->dato == 11);
    cr_assert(ab->izq->der->dato == 0);
    cr_assert(ab->izq->izq->dato == -13);
    cr_assert(ab->izq->izq->der->dato == 6);

    ab_destruir(ab);
}