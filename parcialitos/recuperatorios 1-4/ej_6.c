// José trabaja en una tienda de ropa. Tiene una pila enorme de medias que tiene que juntar de a pares por colores (asumir
// talle único). Dado un arreglo de cadenas donde cada cadena representa un color, donde cada elemento del arreglo representa
// una media de dicho color, implementar una función de tiempo lineal (en la cantidad de medias) que nos indique cuántos
// pares se pueden armar para cada color. Esta información se puede devolver en un diccionario (clave: color, valor: cantidad
// de pares). Justificar la complejidad de la función implementada.

#include <stdbool.h>
#include <stdlib.h>

#include "hash.h"

bool guardar_medias(hash_t *hash, char *colores, size_t n) {
    // Itero sobre el arreglo de colores y los guardo
    for (size_t i = 0; i < n; i++) {
        // Si el color no esta en el diccionario, lo agrega con su valor inicial (1).
        if (!hash_pertenece(hash, colores[i]))
            // Si no se pudo guardar devuelve NULL
            if (!hash_guardar(hash, colores[i], 1))
                return NULL;
        else {
            size_t medias = hash_obtener(hash, colores[i]);
            
            // Si no se pudo guardar devuelve NULL
            if (!hash_guardar(hash, colores[i], medias + 1))
                return NULL;
        }
    }
    return true;
}

bool guardar_pares(hash_t *diccionario_pares_medias, hash_t *diccionario_medias, hash_iter_t *iter) {
    // Avanzo el iterador hasta el final.
    while (!hash_iter_al_final(iter)) {
        // Veo la clave actual.
        const char *clave_actual = hash_iter_ver_actual(iter);
        // Obtengo la cantidad de medias (dato segun la clave).
        size_t cantidad_medias = hash_obtener(diccionario_medias, clave_actual);
        // Guardo en el nuevo diccionario la cantidad de pares de medias segun la clave actual.
        if (!hash_guardar(diccionario_pares_medias, clave_actual, cantidad_medias / 2))
            // Si no se pudo guardar devuelve false.
            return false;
        // Avanzo el iterador.
        hash_iter_avanzar(iter);
    }

    // Se guardo todo bien.
    return true;
}

hash_t *diccionario_medias(char *colores, size_t n) {
    // Creo un diccionario para las medias.
    hash_t *diccionario_medias;

    if ((diccionario_medias = hash_crear(NULL)) == NULL)
        return NULL;

    // Corroboracion de que se hayan guardado bien las medias.
    bool guardadas = guardar_medias(diccionario_medias, colores, n);
    if (!guardado)
        return NULL;

    // Creo el diccionario en donde voy a guardar los pares de medias encontrados
    hash_t *diccionario_pares_medias;

    if ((diccionario_pares_medias = hash_crear(NULL)) == NULL)
        return NULL;

    // Creo el iterador para iterar el diccionario de medias
    hash_iter_t *iter;

    if ((iter = hash_iter_crear(diccionario_medias)) == NULL)
        return NULL;

    // Corroboracion de que se hayan guardado los pares bien.
    bool contado = guardar_pares(diccionario_pares_medias, iter);
    if (!contado)
        return NULL;

    // Destruyo hash e iterador.
    hash_destruir(diccionario_medias);
    hash_iter_destruir(iter);

    return diccionario_pares_medias;
}

/*
    La complejidad de la funcion es O(n) ya que el loop mas complejo es el que
    recorre la lista de medias, como se pide en la consigna. Los demas loop
    son O(k) siendo k la cantidad de colores. Solo cuando la cantidad de colores
    iguala a la cantidad de medias los guardados se vuelven O(n).
*/