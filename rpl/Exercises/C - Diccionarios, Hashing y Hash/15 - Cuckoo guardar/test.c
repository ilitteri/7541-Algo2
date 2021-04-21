#include <criterion/criterion.h>  // No borrar esto!
#include "hash.h"  // Modificar con el nombre de la api que se le entrega al alumno!
#include <string.h> 

Test(misc, testUnElemento) {
    hash_t* hash = hash_crear();
    cr_assert(hash_guardar(hash, "Mondi", "miau"));
    cr_assert(hash_pertenece(hash, "Mondi"));
    cr_assert(strcmp(hash_obtener(hash, "Mondi"), "miau") == 0);
    cr_assert(hash_cantidad(hash) == 1);
    hash_destruir(hash);
}

Test(misc, testUnElementoRepetido) {
    hash_t* hash = hash_crear();
    cr_assert(hash_guardar(hash, "Mondi", "miau"));
    cr_assert(!hash_guardar(hash, "Mondi", "miau"));
    cr_assert(hash_pertenece(hash, "Mondi"));
    cr_assert(strcmp(hash_obtener(hash, "Mondi"), "miau") == 0);
    cr_assert(hash_cantidad(hash) == 1);
    hash_destruir(hash);
}

Test(misc, testDosElementos) {
    hash_t* hash = hash_crear();
    hash_guardar(hash, "Mondi", "miau");
    hash_guardar(hash, "Viena", "miu");
    cr_assert(hash_pertenece(hash, "Mondi"));
    cr_assert(hash_pertenece(hash, "Viena"));
    cr_assert(strcmp(hash_obtener(hash, "Mondi"), "miau") == 0);
    cr_assert(strcmp(hash_obtener(hash, "Viena"), "miu") == 0);
    cr_assert(hash_cantidad(hash) == 2);
    hash_destruir(hash);
}

Test(misc, testElementosConColisiones) {
    hash_t* hash = hash_crear();
    hash_guardar(hash, "Mondi", "miau");
    hash_guardar(hash, "Viena", "miu");
    hash_guardar(hash, "Mruzka", "miauczec");
    cr_assert(hash_pertenece(hash, "Mondi"));
    cr_assert(hash_pertenece(hash, "Viena"));
    cr_assert(hash_pertenece(hash, "Mruzka"));
    cr_assert(strcmp(hash_obtener(hash, "Mondi"), "miau") == 0);
    cr_assert(strcmp(hash_obtener(hash, "Viena"), "miu") == 0);
    cr_assert(strcmp(hash_obtener(hash, "Mruzka"), "miauczec") == 0);
    cr_assert(hash_cantidad(hash) == 3);
    hash_destruir(hash);
}

Test(misc, testElementosConColisionesYBorrados) {
    hash_t* hash = hash_crear();
    hash_guardar(hash, "Mondi", "miau");
    hash_guardar(hash, "Viena", "miu");
    hash_guardar(hash, "Mruzka", "miauczec");
    hash_borrar(hash, "Mondi");
    cr_assert(!hash_pertenece(hash, "Mondi"));
    cr_assert(hash_pertenece(hash, "Viena"));
    cr_assert(hash_pertenece(hash, "Mruzka"));
    cr_assert(hash_obtener(hash, "Mondi") == NULL);
    cr_assert(strcmp(hash_obtener(hash, "Viena"), "miu") == 0);
    cr_assert(strcmp(hash_obtener(hash, "Mruzka"), "miauczec") == 0);
    cr_assert(hash_cantidad(hash) == 2);
    hash_borrar(hash, "Viena");
    cr_assert(!hash_pertenece(hash, "Mondi"));
    cr_assert(!hash_pertenece(hash, "Viena"));
    cr_assert(hash_pertenece(hash, "Mruzka"));
    cr_assert(hash_obtener(hash, "Viena") == NULL);
    cr_assert(hash_cantidad(hash) == 1);
    hash_destruir(hash);
}

Test(misc, testElementosConColisionesYCiclo) {
    hash_t* hash = hash_crear();
    cr_assert(hash_guardar(hash, "Mondi", "miau"));
    cr_assert(hash_guardar(hash, "Viena", "miu"));
    cr_assert(hash_guardar(hash, "Mruzka", "miauczec"));
    cr_assert(!hash_guardar(hash, "Viking", "Raaaar"));
    cr_assert(hash_pertenece(hash, "Mondi"));
    cr_assert(hash_pertenece(hash, "Viena"));
    cr_assert(hash_pertenece(hash, "Mruzka"));
    cr_assert(!hash_pertenece(hash, "Viking"));
    cr_assert(strcmp(hash_obtener(hash, "Mondi"), "miau") == 0);
    cr_assert(strcmp(hash_obtener(hash, "Viena"), "miu") == 0);
    cr_assert(strcmp(hash_obtener(hash, "Mruzka"), "miauczec") == 0);
    cr_assert(hash_cantidad(hash) == 3);
    hash_destruir(hash);
}