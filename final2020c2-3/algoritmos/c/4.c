lista_t *lista_filtrar_repetido(const lista_t *original)
{
    lista_t *elementos_unicos;

    if ((elementos_unicos = lista_crear()) == NULL)
    {
        return NULL;
    }

    lista_iter_t *filtro;

    if ((filtro = lista_iter_crear(original)) == NULL)
    {
        lista_destruir(elementos_unicos);
        return NULL;
    }

    hash_t *filtrados;

    if ((filtro = hash_crear()) == NULL)
    {
        lista_destruir(elementos_unicos);
        lista_iter_destruir(filtro);
        return NULL;
    }

    while (!lista_iter_al_final(filtro))
    {
        void *actual = lista_iter_ver_actual(filtro);
        if (!hash_pertenece(filtrados, actual))
        {
            lista_insertar_ultimo(elementos_unicos, lista_iter_ver_actual(filtro));
        }
        hash_guardar(filtrados, actual, NULL);
        lista_iter_avanzar(filtro);
    }

    lista_iter_destruir(filtro);
    hash_destruir(filtrados);

    return elementos_unicos;
}

/* Complejidad
    Crear las estructuras es O(1). Iterar la lista original es O(n) siendo n la
cantidad de elementos en la lista original, y las operaciones que se realizan en
cada iteracion del recorrido son O(1) (hash_pertenece, hash_guardar, y
lista_insertar_ultimo son O(1)). => la complejidad de esta primitiva es O(n).
*/