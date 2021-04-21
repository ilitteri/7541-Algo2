#include <criterion/criterion.h>  // No borrar esto!
#include "composicion_funciones.h"  // Modificar con el nombre de la api que se le entrega al alumno!

double f(double x) {
    return x*2;
}

double g(double x) {
    return x*3;
}

double h(double x) {
    return x + 5;
}

Test(misc, test_composicion_1_funcion) {
    composicion_t* composicion = composicion_crear();
    composicion_agregar_funcion(composicion, h);
    double r = composicion_aplicar(composicion, 2);
    cr_assert(r == 7);
    composicion_destruir(composicion);
}

Test(misc, test_composicion_2_funciones) {
    composicion_t* composicion = composicion_crear();
    composicion_agregar_funcion(composicion, f);
    composicion_agregar_funcion(composicion, h);
    double r = composicion_aplicar(composicion, 2);
    cr_assert(r == 14);
    composicion_destruir(composicion);
}

Test(misc, test_composicion_3_funciones) {
    composicion_t* composicion = composicion_crear();
    composicion_agregar_funcion(composicion, f);
    composicion_agregar_funcion(composicion, g);
    composicion_agregar_funcion(composicion, h);
    double r = composicion_aplicar(composicion, 2);
    cr_assert(r == 42);
    composicion_destruir(composicion);
}


