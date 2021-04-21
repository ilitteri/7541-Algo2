#include <criterion/criterion.h>  // No borrar esto!
#include "lista.h"  // Modificar con el nombre de la api que se le entrega al alumno!

Test(misc, test_k_1) {
    int data[6] = {1,5,10,3,6,8};
    lista_t* lista = lista_crear();
    for (int i=5; i>=0; i--) {
        lista_insertar_primero(lista, (void*) &data[i]);
    }
    int r = *(int*) lista_ante_k_ultimo(lista, 1);
    cr_assert(r == 8);
}

Test(misc, test_k_2) {
    int data[6] = {1,5,10,3,6,8};
    lista_t* lista = lista_crear();
    for (int i=5; i>=0; i--) {
        lista_insertar_primero(lista, (void*) &data[i]);
    }
    int r = *(int*) lista_ante_k_ultimo(lista, 2);
    cr_assert(r == 6);
}

Test(misc, test_k_3) {
    int data[6] = {1,5,10,3,6,8};
    lista_t* lista = lista_crear();
    for (int i=5; i>=0; i--) {
        lista_insertar_primero(lista, (void*) &data[i]);
    }
    int r = *(int*) lista_ante_k_ultimo(lista, 3);
    cr_assert(r == 3);
}

Test(misc, test_k_largo) {
    int data[6] = {1,5,10,3,6,8};
    lista_t* lista = lista_crear();
    for (int i=5; i>=0; i--) {
        lista_insertar_primero(lista, (void*) &data[i]);
    }
    int r = *(int*) lista_ante_k_ultimo(lista, 6);
    cr_assert(r == 1);
}


