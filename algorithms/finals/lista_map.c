struct extra
{
    lista_t *lista;
    void (*f) (void *);
};

bool visitar_map(void *dato, void *estructura)
{
    lista_insertar_ultimo(*(struct extra*) estructura.lista, *(struct extra*) estructura.f(dato));
    return true;
}

lista_t *lista_map(lista_t *lista, void (*f) (void *))
{
    lista_t *lista_map = lista_crear();
    struct extra estructura = { lista_map, f };
    lista_iterar(lista, visitar_map, estructura);
    return lista_map;
}