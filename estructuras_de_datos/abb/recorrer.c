
typedef enum motivos_recorrido
{
    AGREGAR = 1,
    REEMPLAZAR = 2,
    ENCONTRAR = 4,
    OBTENER = 8
} motivos_recorrido;


static bool recorrer(abb_nodo_t *actual, const char *clave, void **dato, abb_comparar_clave_t cmp, abb_destruir_dato_t destruir_dato, motivos_recorrido motivo_recorrido)
{
    if (actual == NULL)
        return false;

    int comparacion = cmp(clave, actual->clave);

    if (comparacion == 0 && ((REEMPLAZAR | ENCONTRAR | OBTENER) & motivo_recorrido))
    {
        if (motivo_recorrido == REEMPLAZAR)
        {
            if (destruir_dato != NULL)
                destruir_dato(actual->dato);
            actual->dato = *dato;
        }
        else if (motivo_recorrido == OBTENER)
        {
            *dato = actual->dato;
        }
        return true;
    }

    else if (comparacion < 0)
    {
        if (motivo_recorrido == AGREGAR && actual->izq == NULL)
            return !((actual->izq = abb_nodo_crear(clave, *dato)) == NULL);
        return recorrer(actual->izq, clave, dato, cmp, destruir_dato, motivo_recorrido);
    }

    else if (comparacion > 0)
    {
        if (motivo_recorrido == AGREGAR && actual->der == NULL)
            return !((actual->der = abb_nodo_crear(clave, *dato)) == NULL);
        return recorrer(actual->der, clave, dato, cmp, destruir_dato, motivo_recorrido);
    }

    return false;
}