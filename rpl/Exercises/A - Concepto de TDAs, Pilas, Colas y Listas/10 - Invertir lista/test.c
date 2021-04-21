#include <criterion/criterion.h>  // No borrar esto!
#include "lista.h"  // Modificar con el nombre de la api que se le entrega al alumno!

Test(misc, test_invertir_vacia) {
    int data[5] = {1,2,3,4};
    lista_t* lista = lista_crear();
    lista_invertir(lista);
    cr_assert(lista_esta_vacia(lista));
    lista_destruir(lista, NULL);
}


Test(misc, test_invertir) {
    int data[5] = {1,2,3,4};
    lista_t* lista = lista_crear();
    for (int i=0; i<4; i++) {
        lista_insertar_primero(lista, (void*) &data[i]);
    }
    lista_invertir(lista);

    lista_iter_t* iter = lista_iter_crear(lista);
    for (int i=0; i<4; i++, lista_iter_avanzar(iter)) {
        int r = *(int*) lista_iter_ver_actual(iter);
        cr_assert(r == data[i]);
    }

    lista_destruir(lista, NULL);
}
