#ifndef HASH_STRUCT_H
#define HASH_STRUCT_H

// tipo de función para destruir dato
typedef void (*hash_destruir_dato_t)(void *);

/* Estructura para almacenar clave, valor */
typedef struct hash_nodo {
    char *clave;
    void *valor;
} hash_nodo_t;

/* Estructura del hash: arreglo de punteros a lista. */
typedef struct hash {
    lista_t **tabla;
    size_t cantidad;
    size_t largo;
    hash_destruir_dato_t destruir_dato;
} hash_t;

/* Estructura del iterador. */
typedef struct hash_iter {
    const hash_t *hash;
    size_t indice;
    lista_iter_t *iter_actual;
} hash_iter_t;

#endif