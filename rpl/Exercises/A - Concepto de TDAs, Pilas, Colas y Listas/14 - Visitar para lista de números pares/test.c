#include <criterion/criterion.h>  // No borrar esto!
#include "main.h"  // Modificar con el nombre de la api que se le entrega al alumno!
#include "lista.h"

Test(misc, test_todos_impares) {
    lista_t* lista = lista_crear();
    int valores[8] = {1, 3, 5, 1, 3, 5, 7, 7};
    for (int i = 0; i < 8; i++) lista_insertar_ultimo(lista, &valores[i]);
    int suma = 0;
    lista_iterar(lista, visitar_suma_pares, &suma);
    cr_assert(suma == 0);
    lista_destruir(lista, NULL);
}

Test(misc, test_todos_pares) {
    lista_t* lista = lista_crear();
    int valores[8] = {2, 4, 6, 2, 4, 6, 8, 8};
    for (int i = 0; i < 8; i++) lista_insertar_ultimo(lista, &valores[i]);
    int suma = 0;
    lista_iterar(lista, visitar_suma_pares, &suma);
    cr_assert(suma == 40);
    lista_destruir(lista, NULL);
}

Test(misc, test_todos_ceros) {
    lista_t* lista = lista_crear();
    int valores[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < 8; i++) lista_insertar_ultimo(lista, &valores[i]);
    int suma = 0;
    lista_iterar(lista, visitar_suma_pares, &suma);
    cr_assert(suma == 0);
    lista_destruir(lista, NULL);
}

Test(misc, test_diferente_paridad) {
    lista_t* lista = lista_crear();
    int valores[8] = {1, 2, 3, 4, 6, 8, 7, 9};
    for (int i = 0; i < 8; i++) lista_insertar_ultimo(lista, &valores[i]);
    int suma = 0;
    lista_iterar(lista, visitar_suma_pares, &suma);
    cr_assert(suma == 20);
    lista_destruir(lista, NULL);
}

Test(misc, test_con_negativos) {
    lista_t* lista = lista_crear();
    int valores[8] = {-1, -3, 6, -6, 8, 2, -4, 0};
    for (int i = 0; i < 8; i++) lista_insertar_ultimo(lista, &valores[i]);
    int suma = 0;
    lista_iterar(lista, visitar_suma_pares, &suma);
    cr_assert(suma == 0);
    lista_destruir(lista, NULL);
}
