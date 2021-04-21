#include <criterion/criterion.h>  // No borrar esto!
#include "main.h"  // Modificar con el nombre de la api que se le entrega al alumno!

Test(misc, test_array_un_elemento) {
    int v[1] = {1};
    cr_assert(buscar_minimo(v, 1) == 1);
}

Test(misc, test_array_completo) {
    int v[10] = {12, 2, 3, 4, 5, 1, 2, 8, 10, 11};
    cr_assert(buscar_minimo(v, 10) == 1);
}

Test(misc, test_minimo_negativo) {
    int v[10] = {12, 2, 3, 4, 5, 1, 2, 8, 10, -11};
    cr_assert(buscar_minimo(v, 10) == -11);
}
