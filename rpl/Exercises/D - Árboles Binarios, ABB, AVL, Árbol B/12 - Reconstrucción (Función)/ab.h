#ifndef AB_H
#define AB_H

#include <stddef.h>
#include "lista.h"

typedef struct ab ab_t;

struct ab {
    ab_t* izq;
    ab_t* der;
    char dato;
};

ab_t* ab_crear(char dato);

void ab_destruir(ab_t* ab);

// Validaciones (Tests)
lista_t* pre_order(const ab_t* ab);
lista_t* in_order(const ab_t* ab);

#endif