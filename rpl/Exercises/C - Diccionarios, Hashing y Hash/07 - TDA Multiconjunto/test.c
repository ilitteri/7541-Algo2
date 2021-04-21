#include <criterion/criterion.h>  // No borrar esto!
#include "multiconj.h"  // Modificar con el nombre de la api que se le entrega al alumno!
#include <stdbool.h>

Test(misc, ConjVacioNoTieneElemento) {
    multiconj_t* mc = multiconj_crear();
    cr_assert(!multiconj_pertenece(mc, "hola"));
    multiconj_destruir(mc);
}

Test(misc, ConjConUnElemento) {
    multiconj_t* mc = multiconj_crear();
    multiconj_guardar(mc, "hola");
    cr_assert(multiconj_pertenece(mc, "hola"));
    cr_assert(!multiconj_pertenece(mc, "hola2"));
    multiconj_destruir(mc);
}

Test(misc, ConjConUnElementoYBorramos) {
    multiconj_t* mc = multiconj_crear();
    multiconj_guardar(mc, "hola");
    cr_assert(multiconj_pertenece(mc, "hola"));
    cr_assert(multiconj_borrar(mc, "hola"));
    cr_assert(!multiconj_pertenece(mc, "hola"));
    multiconj_destruir(mc);
}

Test(misc, ConjConUnElementoRepetidoYBorramos) {
    multiconj_t* mc = multiconj_crear();
    multiconj_guardar(mc, "hola");
    multiconj_guardar(mc, "hola");
    multiconj_guardar(mc, "hola");
    cr_assert(multiconj_pertenece(mc, "hola"));
    cr_assert(multiconj_borrar(mc, "hola"));
    cr_assert(multiconj_pertenece(mc, "hola"));
    cr_assert(multiconj_borrar(mc, "hola"));
    cr_assert(multiconj_pertenece(mc, "hola"));
    cr_assert(multiconj_borrar(mc, "hola"));
    cr_assert(!multiconj_pertenece(mc, "hola"));
    multiconj_destruir(mc);
}

Test(misc, ConjVariosElementos) {
    multiconj_t* mc = multiconj_crear();
    multiconj_guardar(mc, "hola");
    multiconj_guardar(mc, "hola1");
    multiconj_guardar(mc, "hola2");
    cr_assert(multiconj_pertenece(mc, "hola"));
    cr_assert(multiconj_pertenece(mc, "hola1"));
    cr_assert(multiconj_pertenece(mc, "hola2"));
    cr_assert(multiconj_borrar(mc, "hola"));
    cr_assert(!multiconj_pertenece(mc, "hola"));
    cr_assert(multiconj_pertenece(mc, "hola1"));
    cr_assert(multiconj_borrar(mc, "hola1"));
    cr_assert(multiconj_pertenece(mc, "hola2"));
    cr_assert(!multiconj_pertenece(mc, "hola1"));
    multiconj_destruir(mc);
}

Test(misc, TratoDeBorrarAlgoQueNoEsta) {
    multiconj_t* mc = multiconj_crear();
    multiconj_guardar(mc, "hola");
    multiconj_guardar(mc, "hola1");
    multiconj_guardar(mc, "hola2");
    cr_assert(multiconj_pertenece(mc, "hola"));
    cr_assert(multiconj_pertenece(mc, "hola1"));
    cr_assert(multiconj_pertenece(mc, "hola2"));
    cr_assert(!multiconj_borrar(mc, "hola3"));
    cr_assert(multiconj_pertenece(mc, "hola"));
    cr_assert(!multiconj_borrar(mc, "hola1"));
    cr_assert(!multiconj_pertenece(mc, "hola1"));
    multiconj_destruir(mc);
}

Test(misc, VariosElementosRepetidos) {
    multiconj_t* mc = multiconj_crear();
    for (int i = 0; i < 10; i++) {
        multiconj_guardar(mc, "hola");
        multiconj_guardar(mc, "hola1");
        multiconj_guardar(mc, "hola2");
    }
    bool ok = true;
    for (int i = 0; i < 10 && ok; i++) {
        ok &= multiconj_pertenece(mc, "hola");
        ok &= multiconj_pertenece(mc, "hola1");
        ok &= multiconj_pertenece(mc, "hola2");
        ok &= multiconj_borrar(mc, "hola");
        ok &= multiconj_borrar(mc, "hola1");
        ok &= multiconj_borrar(mc, "hola2");
    }
    cr_assert(ok);
    cr_assert(!multiconj_pertenece(mc, "hola"));
    cr_assert(!multiconj_pertenece(mc, "hola1"));
    cr_assert(!multiconj_pertenece(mc, "hola2"));
    cr_assert(!multiconj_borrar(mc, "hola"));
    cr_assert(!multiconj_borrar(mc, "hola1"));
    cr_assert(!multiconj_borrar(mc, "hola2"));
    multiconj_destruir(mc);
}
