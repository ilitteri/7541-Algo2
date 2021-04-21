#include <criterion/criterion.h>  // No borrar esto!
#include "main.h"  // Modificar con el nombre de la api que se le entrega al alumno!

Test(misc, basico) {
    int v[5] = {1, 1, 0, 0, 0};
    cr_assert(primer_cero(v, 5) == 2);
}

Test(misc, sin_unos) {
    int v[5] = {0, 0, 0, 0, 0};
    cr_assert(primer_cero(v, 5) == 0);
}

Test(misc, sin_ceros) {
    int v[5] = {1, 1, 1, 1, 1};
    cr_assert(primer_cero(v, 5) == -1);
}