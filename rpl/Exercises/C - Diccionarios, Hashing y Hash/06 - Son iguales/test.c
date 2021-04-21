#include <criterion/criterion.h>  // No borrar esto!
#include "main.h"  // Modificar con el nombre de la api que se le entrega al alumno!

Test(misc, test_hash_vacios) {
    hash_t* a = hash_crear(NULL);
    hash_t* b = hash_crear(NULL);
    cr_assert(son_iguales(a,b));
    hash_destruir(a);
    hash_destruir(b);
}

Test(misc, test_hash_iguales) {
    hash_t* a = hash_crear(NULL);
    hash_guardar(a, "a", NULL);
    hash_guardar(a, "b", NULL);
    hash_t* b = hash_crear(NULL);
    hash_guardar(b, "a", NULL);
    hash_guardar(b, "b", NULL);
    cr_assert(son_iguales(a,b));
    hash_destruir(a);
    hash_destruir(b);
}

Test(misc, test_hash_claves_distintas) {
    hash_t* a = hash_crear(NULL);
    hash_guardar(a, "a", NULL);
    hash_guardar(a, "c", NULL);
    hash_t* b = hash_crear(NULL);
    hash_guardar(b, "a", NULL);
    hash_guardar(b, "b", NULL);
    cr_assert(!son_iguales(a,b));
    hash_destruir(a);
    hash_destruir(b);
}

Test(misc, test_hash_comprendido) {
    hash_t* a = hash_crear(NULL);
    hash_guardar(a, "a", NULL);
    hash_guardar(a, "b", NULL);
    hash_guardar(a, "c", NULL);
    hash_t* b = hash_crear(NULL);
    hash_guardar(b, "a", NULL);
    hash_guardar(b, "b", NULL);
    cr_assert(!son_iguales(a,b));
    hash_destruir(a);
    hash_destruir(b);
}

Test(misc, test_hash_valores_distintos) {
    int* valor = malloc(sizeof(int));
    *valor = 1;
    hash_t* a = hash_crear(NULL);
    hash_guardar(a, "a", NULL);
    hash_guardar(a, "b", NULL);
    hash_t* b = hash_crear(NULL);
    hash_guardar(b, "a", NULL);
    hash_guardar(b, "b", valor);
    cr_assert(!son_iguales(a,b));
    hash_destruir(a);
    hash_destruir(b);
    free(valor);
}

