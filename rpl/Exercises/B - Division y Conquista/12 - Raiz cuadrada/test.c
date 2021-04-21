#include <criterion/criterion.h>  // No borrar esto!
#include "main.h"  // Modificar con el nombre de la api que se le entrega al alumno!

Test(misc, test_raiz_entera_exacta) {
    size_t r = raiz_entera(25);
    cr_assert(r == 5);
}

Test(misc, test_raiz_entera_con_redondeo) {
    size_t r = raiz_entera(10);
    cr_assert(r == 3);
}

