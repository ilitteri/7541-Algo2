#include "hash.h"
#include "hash_struct.h"
#include "lista.h"

/* viborita */

lista_t* hash_claves(const hash_t* hash) {
    lista_t *claves;

    if ((claves = lista_crear()) == NULL)
      return NULL;
    
    hash_iter_t *iter;

    if ((iter = hash_iter_crear(hash)) == NULL) {
      lista_destruir(claves, NULL);
      return NULL;
    }

    while (!hash_iter_al_final(iter)) {
      if (!lista_insertar_primero(claves, (void *) hash_iter_ver_actual(iter)))
        return NULL;
      hash_iter_avanzar(iter);
    }
    
    hash_iter_destruir(iter);

    return claves;
}