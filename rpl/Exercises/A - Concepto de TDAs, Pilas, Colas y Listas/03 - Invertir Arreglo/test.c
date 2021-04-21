#include <criterion/criterion.h>  // No borrar esto!
#include <stdlib.h>
#include <stdbool.h>
#include "invertir_arreglo.h"

#define TAM_PAR 6
#define TAM_IMPAR 6

Test(misc, test_un_elemento) {
    int** arreglo = malloc(sizeof(int*));
    arreglo[0] = malloc(sizeof(int));
    *arreglo[0] = 1;
    invertir_arreglo((void**)arreglo, 1);
    cr_assert(*arreglo[0] == 1);
    free(arreglo[0]);
    free(arreglo);
}

void test_elems(int cant) {
    int** arreglo = malloc(sizeof(int*) * cant);
    for (int i = 0; i < cant; i++) {
        arreglo[i] = malloc(sizeof(int));
        *arreglo[i] = i;
    }
    invertir_arreglo((void**)arreglo, cant);
    bool ok = true;
    for (int i = 0; i < cant && ok; i++) {
        ok &= *arreglo[i] == cant - i - 1;
    }
    for (int i = 0; i < cant; i++) {
        free(arreglo[i]);
    }
    free(arreglo);
    cr_assert(ok);
}

Test(misc, test_con_varios_elementos_pares) {
    test_elems(TAM_PAR);
}

Test(misc, test_con_varios_elementos_impares) {
    test_elems(TAM_IMPAR);
}
