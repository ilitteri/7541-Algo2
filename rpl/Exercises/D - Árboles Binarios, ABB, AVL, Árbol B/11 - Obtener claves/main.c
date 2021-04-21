#include "abb.h"
#include "lista.h"
#include "abb_struct.h"
#include <stddef.h>

void _abb_obtener_claves(abb_nodo_t *actual, lista_t *lista) {
    if (actual == NULL)
        return;
    
    lista_insertar_ultimo(lista, (void *) actual->clave);

    _abb_obtener_claves(actual->izq, lista);
    _abb_obtener_claves(actual->der, lista);
}

lista_t* abb_obtener_claves(abb_t* abb) {
    lista_t *lista = lista_crear();
    _abb_obtener_claves(abb->raiz, lista);
    return lista;
}