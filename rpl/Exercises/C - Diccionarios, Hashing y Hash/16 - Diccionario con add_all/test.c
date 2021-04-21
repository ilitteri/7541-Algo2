#include <criterion/criterion.h>  // No borrar esto!
#include "dic_all.h"  // Modificar con el nombre de la api que se le entrega al alumno!

Test(misc, test_simple) {
    dic_all_t* da = dic_all_crear();
    cr_assert(dic_all_guardar(da, "Mondi", 14));
    cr_assert(dic_all_guardar(da, "Viena", 4));
    cr_assert(dic_all_obtener(da, "Viena") == 4);
    cr_assert(dic_all_obtener(da, "Mondi") == 14);
    dic_all_destruir(da);
}

Test(misc, test_addall_funciona_con_los_ya_creados) {
    dic_all_t* da = dic_all_crear();
    dic_all_guardar(da, "Mondi", 14);
    dic_all_guardar(da, "Viena", 4);
    dic_all_add_all(da, 12);
    cr_assert(dic_all_obtener(da, "Viena") == 16);
    cr_assert(dic_all_obtener(da, "Mondi") == 26);
    dic_all_destruir(da);
}

Test(misc, test_agrego_luego_de_addall) {
    dic_all_t* da = dic_all_crear();
    dic_all_guardar(da, "Mondi", 14);
    dic_all_add_all(da, 12);
    dic_all_guardar(da, "Viena", 4);
    cr_assert(dic_all_obtener(da, "Viena") == 4);
    cr_assert(dic_all_obtener(da, "Mondi") == 26);
    dic_all_destruir(da);
}

Test(misc, test_agrego_luego_de_addall_y_luego_hago_otro_addall) {
    dic_all_t* da = dic_all_crear();
    dic_all_guardar(da, "Mondi", 14);
    dic_all_add_all(da, 12);
    dic_all_guardar(da, "Viena", 4);
    dic_all_add_all(da, 3);
    cr_assert(dic_all_obtener(da, "Viena") == 7);
    cr_assert(dic_all_obtener(da, "Mondi") == 29);
    dic_all_destruir(da);
}

Test(misc, test_addall_antes_de_guardar) {
    dic_all_t* da = dic_all_crear();
    dic_all_add_all(da, 12);
    cr_assert(dic_all_guardar(da, "Mondi", 14));
    cr_assert(dic_all_guardar(da, "Viena", 4));
    cr_assert(dic_all_obtener(da, "Viena") == 4);
    cr_assert(dic_all_obtener(da, "Mondi") == 14);
    dic_all_destruir(da);
}