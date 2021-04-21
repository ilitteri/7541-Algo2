#include <criterion/criterion.h>  // No borrar esto!
#include "main.h"  // Modificar con el nombre de la api que se le entrega al alumno!

Test(misc, arreglo_vacio) {
    int v[10];
    cr_assert(arreglo_ordenado(v, 0));
}

Test(misc, arreglo_ordenado) {
    int v[10] = {1, 2, 45, 67, 234, 432, 500, 600, 923, 1000};
    cr_assert(arreglo_ordenado(v, 10));
}

Test(misc, arreglo_desordenado) {
    int v[10] = {1, 2, 45, 67, 234, 432, 500, -600, 923, 1000};
    cr_assert(!arreglo_ordenado(v, 10));
}