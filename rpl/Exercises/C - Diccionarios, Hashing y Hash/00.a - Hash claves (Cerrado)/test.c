#include <criterion/criterion.h>  // No borrar esto!
#include "hash.h"  // Modificar con el nombre de la api que se le entrega al alumno!
#include "lista.h"

Test(misc, test_1_clave) {
    hash_t* hash = hash_crear(NULL);
    hash_guardar(hash, "1", NULL);
    lista_t* claves = hash_claves(hash);
    lista_iter_t* iter = lista_iter_crear(claves);
    for (; !lista_iter_al_final(iter); lista_iter_avanzar(iter)) {
        char* clave = (char*) lista_iter_ver_actual(iter);
        hash_borrar(hash, clave);
    }
    lista_iter_destruir(iter);
    cr_assert(hash_cantidad(hash) == 0);
    hash_destruir(hash);
    lista_destruir(claves, NULL);
}

Test(misc, test_5_clave) {
    hash_t* hash = hash_crear(NULL);
    hash_guardar(hash, "1", NULL);
    hash_guardar(hash, "2", NULL);
    hash_guardar(hash, "3", NULL);
    hash_guardar(hash, "4", NULL);
    hash_guardar(hash, "5", NULL);
    lista_t* claves = hash_claves(hash);
    lista_iter_t* iter = lista_iter_crear(claves);
    for (; !lista_iter_al_final(iter); lista_iter_avanzar(iter)) {
        char* clave = (char*) lista_iter_ver_actual(iter);
        hash_borrar(hash, clave);
    }
    lista_iter_destruir(iter);
    cr_assert(hash_cantidad(hash) == 0);
    hash_destruir(hash);
    lista_destruir(claves, NULL);
}


