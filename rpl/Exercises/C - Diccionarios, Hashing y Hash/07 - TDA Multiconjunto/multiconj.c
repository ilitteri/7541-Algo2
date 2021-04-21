#include <stdbool.h>
#include <stdlib.h>

#include "multiconj.h"
#include "hash.h"

/* viborita */

typedef struct multiconj {
    hash_t *hash;
} multiconj_t;

multiconj_t* multiconj_crear() {
    multiconj_t *multiconj;

    if ((multiconj = malloc(sizeof(multiconj_t))) == NULL)
        return NULL;
    
    if ((multiconj->hash = hash_crear(NULL)) == NULL) {
        free(multiconj);
        return NULL;
    }

    return multiconj;
}

bool multiconj_guardar(multiconj_t* multiconj, const char* elem) {
    if (!hash_pertenece(multiconj->hash, elem)) 
        return hash_guardar(multiconj->hash, elem, (void *) 1);

    size_t veces = *(size_t *) hash_obtener(multiconj->hash, elem);

    return hash_guardar(multiconj->hash, elem, (void *)(veces + 1));
}

bool multiconj_pertenece(const multiconj_t* multiconj, const char* elem) {
    return hash_obtener(multiconj->hash, elem);
}

bool multiconj_borrar(multiconj_t* multiconj, char* elem) {
    if (!multiconj_pertenece(multiconj, elem))
        return false;

    size_t veces = *(size_t *) hash_obtener(multiconj->hash, elem);
    hash_guardar(multiconj->hash, elem, (void *)(veces - 1));

    if (!multiconj_pertenece(multiconj, elem))
        hash_borrar(multiconj->hash, elem);
    
    return true;
    
}

void multiconj_destruir(multiconj_t* multiconj) {
    hash_destruir(multiconj->hash);
    free(multiconj);
}