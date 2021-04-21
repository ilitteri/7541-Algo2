#include <criterion/criterion.h>  // No borrar esto!
#include "api.h"  // Modificar con el nombre de la api que se le entrega al alumno!

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


void test_validar(const char* esperado_pre, const char* esperado_in) {
    ab_t* ab = ab_reconstruir(esperado_pre, esperado_in);
    lista_t* pre = ab_pre_order(ab);
    lista_t* inor = ab_in_order(ab);
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

Test(misc, vacio) {
    test_validar("", "");
}

Test(misc, pocos_elementos) {
    test_validar("BAC", "ABC");
}

Test(misc, lista) {
    test_validar("ABCDEFGH", "ABCDEFGH");
}

Test(misc, completo) {
    test_validar("DCABFEG", "ABCDEFG");
}

Test(misc, variado) {
    test_validar("EURMAONDVSZT", "MRAUOZSVDNET");
}

Test(misc, variado2) {
    test_validar("DBACHTLKYXZ", "ABCDHKLTXYZ");
}


