#include <stdlib.h>
#include <stdio.h> // sprintf
#include "fraccion.h"

typedef struct fraccion {
    int numerador;
    int denominador;
}fraccion_t;

fraccion_t* fraccion_crear(int numerador, int denominador) {
    fraccion_t *fraccion = malloc(sizeof(fraccion_t));

    if (fraccion == NULL || !denominador)
        return NULL;

    fraccion->numerador = numerador;
    fraccion->denominador = denominador;

    return fraccion;
}

void fraccion_destruir(fraccion_t* fraccion) {
    free(fraccion);
}

fraccion_t* fraccion_sumar(fraccion_t* f1, fraccion_t* f2) {
    int numerador = (f1->numerador * f2->denominador) + (f2->numerador * f1->denominador);
    int denominador = f1->denominador * f2->denominador;

    return fraccion_crear(numerador, denominador);
}

fraccion_t* fraccion_mul(fraccion_t* f1, fraccion_t* f2) {
    int numerador = f1->numerador * f2->numerador;
    int denominador = f1->denominador * f2->denominador;

    return fraccion_crear(numerador, denominador);
}

int fraccion_parte_entera(fraccion_t* fraccion) {
    return (int)(fraccion->numerador / fraccion->denominador);
}

char* fraccion_representacion(fraccion_t* fraccion) {
    char *buffer = malloc(10 * sizeof(char));
    if (fraccion->numerador % fraccion->denominador == 0){
        sprintf(buffer, "%d", fraccion->numerador / fraccion->denominador);
        return buffer;
    }
    for (int i = 2; i <= fraccion->numerador / 2 && i <= fraccion->denominador / 2; i++) {
        if (fraccion->numerador % i == 0 && fraccion->denominador % i == 0) {
            sprintf(buffer, "%d/%d", fraccion->numerador / i, fraccion->denominador / i);
            return buffer;
        }
    }
    sprintf(buffer, "%d/%d", fraccion->numerador, fraccion->denominador);
    return buffer;
}