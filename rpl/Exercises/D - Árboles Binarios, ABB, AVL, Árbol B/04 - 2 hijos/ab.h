#ifndef AB_H
#define AB_H

#include <stddef.h>

typedef struct ab ab_t;

struct ab {
    ab_t* izq;
    ab_t* der;
    void* dato;
};

ab_t* ab_crear();

// A implementar
size_t ab_2_hijos(const ab_t* ab);

void ab_destruir(ab_t* ab);

#endif