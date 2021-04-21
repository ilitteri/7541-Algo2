#include "hash.h"
#include "hash_struct.h"
#include "lista.h"

lista_t* hash_claves(const hash_t* hash) {
    lista_t* claves = lista_crear();

    for (size_t i = 0; i < hash->capacidad; i++)
        if (hash->tabla[i].estado == OCUPADO){
            lista_insertar_ultimo(claves, hash->tabla[i].clave);

    return claves;
}