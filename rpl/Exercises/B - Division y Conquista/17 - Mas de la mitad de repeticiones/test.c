#include <criterion/criterion.h>  // No borrar esto!
#include "main.h"  // Modificar con el nombre de la api que se le entrega al alumno!

Test(misc, test_caso_1) {
    int a[5] = {1, 2, 1, 2, 3};
    cr_assert(!mas_de_mitad(a, 5));
}

Test(misc, test_caso_2) {
    int a[4] = {1, 1, 2, 3};
    cr_assert(!mas_de_mitad(a, 4));
}

Test(misc, test_caso_3) {
    int a[6] = {1, 2, 3, 1, 1, 1};
    cr_assert(mas_de_mitad(a, 6));
}

Test(misc, test_caso_4) {
    int a[1] = {1};
    cr_assert(mas_de_mitad(a, 1));
}

