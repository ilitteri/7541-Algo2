#ifndef AB_H
#define AB_H

#include <stddef.h>

typedef struct ab ab_t;

struct ab {
    ab_t* izq;
    ab_t* der;
    int dato;
};

ab_t* ab_crear(int dato);

// A implementar
void ab_invertir(ab_t* ab);

void ab_destruir(ab_t* ab);

#endif