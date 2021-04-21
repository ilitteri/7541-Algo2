#include "ab.h"

/* viborita */

size_t ab_2_hijos(const ab_t* ab) {
    if (ab == NULL)
        return 0;

    if (ab->izq != NULL && ab->der != NULL)
        return ab_2_hijos(ab->izq) + ab_2_hijos(ab->der) + 1;

    return ab_2_hijos(ab->izq) + ab_2_hijos(ab->der);
}