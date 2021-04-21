#include <string.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"
#include "hash_struct.h"


/* crea una copia (memoria dinamica) de la cadena pasada por parametro */
char* strdup(const char* org) {
    char* cpy = malloc(sizeof(char) * (strlen(org) + 1));
    if (!cpy) return NULL;
    strcpy(cpy, org);
    return cpy;
}

bool hash_guardar(hash_t* hash, const char* clave, void* dato) {
    // TODO
    // Asumir que no hay que lidiar con potenciales redimensiones (en caso de tener que,
    // devovler false)
}