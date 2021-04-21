#include "abb.h"
#include "lista.h"
#include <stdbool.h>

void insertar_mayores(abb_nodo_t *actual, lista_t *mayores, const char *clave, abb_comparar_clave_t cmp)
{
    if (actual == NULL)
        return;

    if (cmp(actual->clave, clave) > 0)
        insertar_mayores(actual->izq, mayores, clave, cmp);

    lista_insertar_ultimo(mayores, actual->dato);
    
    insertar_mayores(actual->der, mayores, clave, cmp);
}

lista_t *abb_mayores(const abb_t *abb, const char *clave) {
    lista_t *mayores;

    if ((mayores = lista_crear()) == NULL)
    {
        return NULL;
    }

    insertar_mayores(abb->raiz, mayores, clave, abb->cmp);

    return mayores;
}