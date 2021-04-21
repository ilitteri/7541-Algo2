#include <criterion/criterion.h>  // No borrar esto!
#include "fraccion.h"  // Modificar con el nombre de la api que se le entrega al alumno!

Test(misc, test_fraccion_crear) {
    fraccion_t* fraccion = fraccion_crear(2, 2);
    cr_assert(fraccion != NULL);
    fraccion_destruir(fraccion);
}

Test(misc, test_fraccion_denominador_cero) {
    fraccion_t* fraccion = fraccion_crear(2, 0);
    cr_assert(fraccion == NULL);
    fraccion_destruir(fraccion);
}

Test(misc, test_fraccion_parte_entera_exacta) {
    fraccion_t* fraccion = fraccion_crear(2, 2);
    cr_assert(fraccion_parte_entera(fraccion) == 1);
    fraccion_destruir(fraccion);
}

Test(misc, test_fraccion_parte_entera_redondeo) {
    fraccion_t* fraccion = fraccion_crear(3, 2);
    cr_assert(fraccion_parte_entera(fraccion) == 1);
    fraccion_destruir(fraccion);
}

Test(misc, test_fraccion_representacion) {
    fraccion_t* fraccion = fraccion_crear(3, 2);
    char* representacion = fraccion_representacion(fraccion);
    cr_assert_str_eq(representacion, "3/2");
    fraccion_destruir(fraccion);
}

Test(misc, test_fraccion_representacion_simplificacion) {
    fraccion_t* fraccion = fraccion_crear(6, 4);
    char* representacion = fraccion_representacion(fraccion);
    cr_assert_str_eq(representacion, "3/2");
    fraccion_destruir(fraccion);
}

Test(misc, test_fraccion_representacion_entero) {
    fraccion_t* fraccion = fraccion_crear(4, 4);
    char* representacion = fraccion_representacion(fraccion);
    cr_assert_str_eq(representacion, "1");
    fraccion_destruir(fraccion);
}

Test(misc, test_fraccion_sumar) {
    fraccion_t* f1 = fraccion_crear(3, 2);
    fraccion_t* f2 = fraccion_crear(3, 2);
    fraccion_t* r = fraccion_sumar(f1, f2);
    char* representacion = fraccion_representacion(r);
    cr_assert_str_eq(representacion, "3");
    fraccion_destruir(f1);
    fraccion_destruir(f2);
    fraccion_destruir(r);
}

Test(misc, test_fraccion_multiplicar) {
    fraccion_t* f1 = fraccion_crear(3, 2);
    fraccion_t* f2 = fraccion_crear(3, 2);
    fraccion_t* r = fraccion_mul(f1, f2);
    char* representacion = fraccion_representacion(r);
    cr_assert_str_eq(representacion, "9/4");
    fraccion_destruir(f1);
    fraccion_destruir(f2);
    fraccion_destruir(r);
}

