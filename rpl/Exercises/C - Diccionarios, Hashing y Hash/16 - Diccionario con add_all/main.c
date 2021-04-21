#include "hash.h"
#include "dic_all.h"
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

// Pueden agregar la dependencia al TDA que quieran, inclusive agregar archivos de otros
// TDAs que hayan implementado ustedes

struct dic_all {
    hash_t *hash;
};

dic_all_t* dic_all_crear() {
    dic_all_t *dic_all;
    if ((dic_all = malloc(sizeof(dic_all_t))) == NULL)
    {
        return NULL;
    }
    hash_t *hash;
    if ((hash = hash_crear(NULL)) == NULL)
    {
        free(dic_all);
        return NULL;
    }
    
    dic_all->hash = hash;

    return NULL;
}

bool dic_all_guardar(dic_all_t* dic, const char* clave, int dato) {
    return hash_guardar(dic->hash, clave, &dato);
}

int dic_all_obtener(dic_all_t* dic, const char* clave) {
    
    return *(int *)hash_obtener(dic->hash, clave);
}

int dic_all_borrar(dic_all_t* dic, const char* clave) {
    return *(int *)hash_borrar(dic->hash, clave);
}

bool dic_all_add(dic_all_t* dic, const char* clave, int valor) {
    int x;
    if ((x = *(int *)hash_obtener(dic->hash, clave)) == false)
    {
        return false;
    }
    return x + valor;
}

void dic_all_add_all(dic_all_t* dic, int valor) {
    
}

void dic_all_destruir(dic_all_t* dic) {
    hash_destruir(dic->hash);
    free(dic);
}

int main()
{
    dic_all_t* da = dic_all_crear();
    printf("%d", dic_all_guardar(da, "Mondi", 14));
    printf("%d", dic_all_guardar(da, "Viena", 4));
    printf("%d", dic_all_obtener(da, "Viena") == 4);
    printf("%d", dic_all_obtener(da, "Mondi") == 14);
    dic_all_destruir(da);
    return 0;
}