#include "main.h" // No borrar

/* viborita */

bool son_iguales(hash_t* a, hash_t* b) {
    if (hash_cantidad(a) == 0 && hash_cantidad(b) == 0)
        return true;

    hash_iter_t *iter;

    if ((iter = hash_iter_crear(a)) == NULL || hash_cantidad(a) != hash_cantidad(b))
        return false;

    bool iguales = true;
    while (!hash_iter_al_final(iter)) {
        const char *clave = hash_iter_ver_actual(iter);
        iguales &= (hash_pertenece(b, clave) && hash_obtener(b, clave) == hash_obtener(a, clave));
        hash_iter_avanzar(iter);
    }
    
    hash_iter_destruir(iter);

    return iguales;
}