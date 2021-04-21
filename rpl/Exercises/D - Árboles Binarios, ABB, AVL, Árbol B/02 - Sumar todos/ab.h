#ifndef AB_H
#define AB_H

#include <stddef.h>

typedef struct ab ab_t;

struct ab {
    ab_t* izq;
    ab_t* der;
    int dato;
};

ab_t* ab_crear(int valor);

// A implementar
int ab_suma(const ab_t* ab);

void ab_destruir(ab_t* ab);

#endif