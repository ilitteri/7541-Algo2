static void copy_slice(lista_t *original, lista_t *slice, size_t inicio, size_t fin)
{   
    // Recorro desde el primero en la lista hasta que llegue al fin o al final
    // de la lista guardando los elementos en el rango, en el slice.
    nodo_t *actual = original->primero;
    size_t largo = original->largo;
    for (size_t pseudo_indice = 0; pseudo_indice < largo && pseudo_indice <= fin; pseudo_indice++)
    {
        if (pseudo_indice >= inicio && pseudo_indice <= fin)
        {
            lista_insertar_ultimo(slice, actual->dato);
        }
        actual = actual->proximo;
    }
}

lista_t *lista_slice(const lista_t *original, size_t inicio, size_t fin)
{
    // Si el fin o inicio no son posiciones validas devuelve NULL.
    if (fin <= inicio || inicio >= original->largo)
    {
        return NULL;
    }

    lista_t *slice;

    if ((slice = lista_crear()) == NULL)
    {
        return NULL;
    }

    copy_slice(original, slice, inicio, fin) // O(n)

    // Devuelvo el slice.
    return slice;
}

/* Complejidad
    La mayor complejidad se la lleva la funcion auxiliar copy_slice que cuesta
en el peor caso O(n) siendo n el largo de la lista original menos uno.
*/