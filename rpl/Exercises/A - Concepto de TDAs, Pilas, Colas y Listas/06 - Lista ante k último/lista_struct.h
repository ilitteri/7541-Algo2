#ifndef LISTA_STR
#define LISTA_STR

/*
 * Definición de los tipos de datos
 */

typedef struct nodo {
    void *dato;
    struct nodo *prox;
} nodo_t;

typedef struct lista {
    nodo_t *primero;
} lista_t;

#endif