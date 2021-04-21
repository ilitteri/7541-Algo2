#include "ab.h"

/* viborita */

size_t ab_altura(const ab_t* ab) {
    if (ab == NULL)
        return 0;

    size_t altura_izq = ab_altura(ab->izq) + 1;
    size_t altura_der = ab_altura(ab->der) + 1;

    return altura_izq >= altura_der ? altura_izq : altura_der;
}