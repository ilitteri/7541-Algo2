#include <criterion/criterion.h>  // No borrar esto!
#include "ab.h"  // Modificar con el nombre de la api que se le entrega al alumno!
#include <stdbool.h>
#include <stddef.h>
#include <string.h>

struct aplicar {
    lista_t* lista;
    boolean todo_ok;
};

bool validar(void* dato, void* extra) {
    char* letra_actual = dato;
    struct aplicar* aplicar = extra;
    if (lista_esta_vacia(aplicar->lista)) {
        aplicar->todo_ok = false;
        return false;
    }
    char* esperado = lista_borrar_primero(aplicar->lista);
    if (*esperado != letra_actual) {
        aplicar->todo_ok = false;
        return false;
    } else {
        return true;
    }
}


Test(misc, arbol_correcto) {
    ab_t* ab = arbol_con_recorridos();
    lista_t* pre = ab_pre_order(ab);
    lista_t* inor = ab_in_order(ab);
    const char* esperado_pre = "EURMAONDVSZT";
    const char* esperado_in = "MRAUOZSVDNET";
    struct aplicar ap;
    ap.lista = lista_crear();
    ap.todo_ok = true;

    for (size_t i = 0; i < strlen(esperado_pre); i++) {
        lista_insertar_ultimo(ap.lista, &esperado_pre[i]);
    }

    lista_iterar(pre, validar, &ap);
    
    cr_assert(ap.todo_ok);
    lista_destruir(ap.lista);

    ap.lista = lista_crear();
    for (size_t i = 0; i < strlen(esperado_in); i++) {
        lista_insertar_ultimo(ap.lista, &esperado_in[i]);
    }
    ap.todo_ok = true;

    lista_iterar(pre, validar, &ap);
    cr_assert(ap.todo_ok);
    lista_destruir(ap.lista);

    lista_destruir(pre, NULL);
    lista_destruir(inor, NULL);
    ab_destruir(ab);
}

