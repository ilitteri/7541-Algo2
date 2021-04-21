#include <criterion/criterion.h>  // No borrar esto!
#include "heap.h"  // Modificar con el nombre de la api que se le entrega al alumno!
#include <string.h>

int strcmp_inv(const char* str1, const char* str2) {
    return strcmp(str2, str1);
}

Test(misc, test_cambiar_prioridad_basico) {
    char* a[5] = { "A", "D", "C", "E", "B"};
    heap_t* heap = heap_crear_arr(a, 5, (cmp_func_t) strcmp);
    char* max = heap_ver_max(heap);
    char* res1 = "E";
    cr_assert_str_eq(max, res1);
    heap_cambiar_prioridad(heap, (cmp_func_t) strcmp_inv);
    max = heap_ver_max(heap);
    char* res2 = "A";
    cr_assert_str_eq(max, res2);
}


