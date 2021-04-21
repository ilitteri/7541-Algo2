#include <criterion/criterion.h>  // No borrar esto!
#include "main.h"  // Modificar con el nombre de la api que se le entrega al alumno!

Test(misc, pico_medio) {
    int v[8] = {0, 1, 2, 3, 2, 1, 0, -1};
    cr_assert(posicion_pico(v, 0, 7) == 3);
}

Test(misc, pico_principio) {
    int v[8] = {10, 9, 8, 7, 6, 5, 4, 3};
    cr_assert(posicion_pico(v, 0, 7) == 0);
}

Test(misc, pico_fin) {
    int v[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    cr_assert(posicion_pico(v, 0, 7) == 7);
}