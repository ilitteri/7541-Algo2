#include <criterion/criterion.h>  // No borrar esto!
#include <string.h>
#include "abb.h"  // Modificar con el nombre de la api que se le entrega al alumno!

Test(misc, test_1_mayor) {
    abb_t* abb = abb_crear(strcmp, NULL);
    abb_guardar(abb, "A", NULL);
    abb_guardar(abb, "D", NULL);
    abb_guardar(abb, "C", NULL);
    abb_guardar(abb, "B", NULL);
    abb_guardar(abb, "E", NULL);
    lista_t* lista = abb_mayores(abb, "D");
    cr_assert(lista_largo(lista) == 1);
    abb_destruir(abb);
    lista_destruir(lista, NULL);
}

Test(misc, test_clave_no_presente) {
    abb_t* abb = abb_crear(strcmp, NULL);
    abb_guardar(abb, "A", NULL);
    abb_guardar(abb, "D", NULL);
    abb_guardar(abb, "C", NULL);
    abb_guardar(abb, "B", NULL);
    abb_guardar(abb, "E", NULL);
    lista_t* lista = abb_mayores(abb, "BA");
    cr_assert(lista_largo(lista) == 3);
    abb_destruir(abb);
    lista_destruir(lista, NULL);
}

Test(misc, test_sin_mayores) {
    abb_t* abb = abb_crear(strcmp, NULL);
    abb_guardar(abb, "A", NULL);
    abb_guardar(abb, "D", NULL);
    abb_guardar(abb, "C", NULL);
    abb_guardar(abb, "B", NULL);
    abb_guardar(abb, "E", NULL);
    lista_t* lista = abb_mayores(abb, "Z");
    cr_assert(lista_largo(lista) == 0);
    abb_destruir(abb);
    lista_destruir(lista, NULL);
}


