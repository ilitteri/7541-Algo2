#include <criterion/criterion.h>  // No borrar esto!
#include "main.h"  // Modificar con el nombre de la api que se le entrega al alumno!

Test(misc, test_caso_1) {
    int a[5] = {1, 2, 1, 2, 3};
    void* b[5] = {};
    for (size_t i=0; i < 5; i++) {
        b[i] = (void*) &a[i];
    }
    cr_assert(!mas_de_mitad(b, 5));
}

Test(misc, test_caso_2) {
    int a[4] = {1, 1, 2, 3};
    void* b[5] = {};
    for (size_t i=0; i < 4; i++) {
        b[i] = (void*) &a[i];
    }
    cr_assert(!mas_de_mitad(b, 4));
}

Test(misc, test_caso_3) {
    int a[6] = {1, 2, 3, 1, 1, 1};
    void* b[6] = {};
    for (size_t i=0; i < 6; i++) {
        b[i] = (void*) &a[i];
    }
    cr_assert(mas_de_mitad(b, 6));
}

Test(misc, test_caso_4) {
    int a[1] = {1};
    void* b[5] = {};
    for (size_t i=0; i < 1; i++) {
        b[i] = (void*) &a[i];
    }
    cr_assert(mas_de_mitad(b, 1));
}




