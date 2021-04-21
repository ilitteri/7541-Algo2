#include <criterion/criterion.h>  // No borrar esto!
#include <stdlib.h>
#include <stdbool.h>  // Modificar con el nombre de la api que se le entrega al alumno!

Test(misc, test_arreglo_es_magico) {
    int a[6] = { -3, 0, 1, 3, 7, 9};
    cr_assert(arreglo_es_magico(a, 6));
}

Test(misc, test_arreglo_no_magico) {
    int a[6] = { 1, 2, 4, 6, 7, 9};
    cr_assert(!arreglo_es_magico(a, 6));
}

