#include <criterion/criterion.h>  // No borrar esto!
#include "main.h"  // Modificar con el nombre de la api que se le entrega al alumno!

Test(misc, desordenado_primero) {
    int v[10] = {11,2,3,4,5,6,7,8,9,10};
    cr_assert(elemento_desordenado(v, 10) == 11);
}

Test(misc, desordenado_casi_ultimo) {
    int v[10] = {1,2,3,4,5,6,7,8,90,10};
    cr_assert(elemento_desordenado(v, 10) == 90);
}

Test(misc, desordenado_medio) {
    int v[10] = {1,2,3,4,5,6,7,13,9,10};
    cr_assert(elemento_desordenado(v, 10) == 13);
}

