#include <criterion/criterion.h>  // No borrar esto!
#include "abb.h"  // Modificar con el nombre de la api que se le entrega al alumno!

Test(misc, test_abb_vacio) {
    abb_t* abb = abb_crear(strcmp, NULL);
    lista_t* claves = abb_obtener_claves(abb);
    cr_assert(lista_largo(claves) == 0);
}

Test(misc, test_varias_claves) {
    abb_t* abb = abb_crear(strcmp, NULL);
    abb_guardar(abb, "M", NULL);
    abb_guardar(abb, "D", NULL);
    abb_guardar(abb, "A", NULL);
    abb_guardar(abb, "E", NULL);
    abb_guardar(abb, "O", NULL);
    abb_guardar(abb, "T", NULL);
    abb_guardar(abb, "U", NULL);

    char* orden[7] = {"M", "D", "A", "E", "O", "T", "U"};

    lista_t* claves = abb_obtener_claves(abb);
    cr_assert(lista_largo(claves) == 7);
    
    size_t i = 0;
    lista_iter_t* iter = lista_iter_crear(claves);
    for (; !lista_iter_al_final(iter); lista_iter_avanzar(iter)) {
        char* clave = (char*) lista_iter_ver_actual(iter);
        cr_assert_str_eq(clave, orden[i]);
        abb_borrar(abb, clave);
        i++;
    }
    lista_iter_destruir(iter);
    cr_assert(abb_cantidad(abb) == 0);
    abb_destruir(abb);
    lista_destruir(claves, NULL);
}

