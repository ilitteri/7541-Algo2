#include <criterion/criterion.h>  // No borrar esto!
#include "cola.h"  // Modificar con el nombre de la api que se le entrega al alumno!
#include "cola_filtrar.h"

bool filtro_true(void* a) {
    return true;
}

bool filtro_false(void* a) {
    return false;
}

bool filtro_pares(void* a) {
    int* v = a;
    return (*v) % 2 == 0;
}

Test(misc, cola_vacia) {
    cola_t* cola_crear();
    cola_filtrar(cola, filtro_false);
    cr_assert(cola_esta_vacia(cola));
    cola_destruir(cola, NULL);
}

Test(misc, cola_todos) {
    cola_t* cola_crear();
    cola_encolar(cola, 0x1); cola_encolar(cola, 0x2); cola_encolar(cola, 0x3);
    cola_filtrar(cola, filtro_true);
    cr_assert(cola_desencolar(cola) == 0x1 && cola_desencolar(cola) == 0x2 && cola_desencolar(cola) == 0x3);
    cr_assert(cola_esta_vacia(cola));
    cola_destruir(cola, NULL);
}

Test(misc, cola_ninguno) {
    cola_t* cola_crear();
    cola_encolar(cola, 0x1); cola_encolar(cola, 0x2); cola_encolar(cola, 0x3);
    cola_filtrar(cola, filtro_false);
    cr_assert(cola_esta_vacia(cola));
    cola_destruir(cola, NULL);
}

Test(misc, cola_pares) {
    cola_t* cola_crear();
    int valores[8] = {1, 2, 4, 7, 7, 3, 6, 1};
    for (int i = 0; i < 8; i++) cola_encolar(cola, &valores[i]);
    cola_filtrar(cola, filtro_pares);
    cr_assert(cola_desencolar(cola) == &valores[1] && cola_desencolar(cola) == &valores[2] && cola_desencolar(cola) == &valores[7]);
    cr_assert(cola_esta_vacia(cola));
    cola_destruir(cola, NULL);
}

