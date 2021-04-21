Dada una lista enlazada implementada con las siguientes estructuras:

```
typedef struct nodo {
    void *dato;
    struct nodo *prox;
} nodo_t;

struct lista {
    nodo_t *primero;
};
```

Escribir una primitiva que reciba una lista y devuelva el elemento que esté a _k_ posiciones del final (el ante-k-último), recorriendo la lista una sola vez y sin usar estructuras auxiliares. Considerar que _k_ es siempre menor al largo de la lista. Por ejemplo, si se recibe la lista [ 1, 5, 10, 3, 6, 8 ], y k = 4, debe devolver 10. Indicar el orden de complejidad de la primitiva.

