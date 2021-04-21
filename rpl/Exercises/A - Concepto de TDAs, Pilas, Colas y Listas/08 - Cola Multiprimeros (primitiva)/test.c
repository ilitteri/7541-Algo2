#include <criterion/criterion.h>  // No borrar esto!
#include "cola.h"  // Modificar con el nombre de la api que se le entrega al alumno!
#include <stdbool.h>
#include <stdlib.h>

Test(misc, cola_vacia) {
    cola_t* cola = cola_crear();
    void** datos = cola_multiprimeros(cola, 5);
    bool ok = true;
    for (int i = 0; ok && i < 5; i++) {
        ok &= datos[i] == NULL;
    }
    free(datos);
    cola_destruir(cola, NULL);
    cr_assert(ok);
}

Test(misc, cola_con_menos_elementos_que_k) {
    cola_t* cola = cola_crear();
    cola_encolar(cola, 0x1);
    cola_encolar(cola, 0x2);
    cola_encolar(cola, 0x3);
    void** datos = cola_multiprimeros(cola, 5);
    cr_assert(datos[0] == 0x1 && datos[1] == 0x2 && datos[2] == 0x3 && datos[3] == NULL && datos[4] == NULL);
    free(datos);
    cola_destruir(cola, NULL);
}

Test(misc, cola_con_igual_cant) {
    cola_t* cola = cola_crear();
    cola_encolar(cola, 0x1);
    cola_encolar(cola, 0x2);
    cola_encolar(cola, 0x3);
    void** datos = cola_multiprimeros(cola, 3);
    cr_assert(datos[0] == 0x1 && datos[1] == 0x2 && datos[2] == 0x3);
    free(datos);
    cola_destruir(cola, NULL);
}

Test(misc, cola_con_mas_elementos_que_k) {
    cola_t* cola = cola_crear();
    cola_encolar(cola, 0x1);
    cola_encolar(cola, 0x2);
    cola_encolar(cola, 0x3);
    cola_encolar(cola, 0x4);
    void** datos = cola_multiprimeros(cola, 2);
    cr_assert(datos[0] == 0x1 && datos[1] == 0x2);
    free(datos);
    cola_destruir(cola, NULL);
}

Test(misc, cola_con_mas_elementos_que_k_NULLs_en_el_medio) {
    cola_t* cola = cola_crear();
    cola_encolar(cola, 0x1);
    cola_encolar(cola, NULL);
    cola_encolar(cola, 0x3);
    cola_encolar(cola, 0x4);
    void** datos = cola_multiprimeros(cola, 3);
    cr_assert(datos[0] == 0x1 && datos[1] == NULL && datos[2] == 0x);
    free(datos);
    
}