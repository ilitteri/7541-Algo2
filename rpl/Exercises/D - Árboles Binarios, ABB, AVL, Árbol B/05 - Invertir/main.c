#include "ab.h"

/* viborita */

ab_t *invertir(ab_t *ab) {
    if (ab == NULL)
        return NULL;
    
    ab_t *temp = invertir(ab->izq);
    ab->izq = invertir(ab->der);
    ab->der = temp;

    return ab;
}

void ab_invertir(ab_t* ab) {
    invertir(ab);
}