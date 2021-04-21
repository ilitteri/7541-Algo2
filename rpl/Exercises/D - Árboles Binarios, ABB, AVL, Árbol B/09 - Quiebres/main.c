#include "ab.h"

/* viborita */

enum familia {PADRE, HIJO_IZQ, HIJO_DER};

size_t _ab_quiebres(const ab_t *ab, enum familia miembro) {
    if (ab == NULL)
        return 0;
    
    if (ab->der != NULL && ab->izq == NULL && miembro == HIJO_IZQ)
        return _ab_quiebres(ab->der, HIJO_DER) + 1;

    else if (ab->izq != NULL && ab->der == NULL && miembro == HIJO_DER)
        return _ab_quiebres(ab->izq, HIJO_IZQ) + 1;
    
    return _ab_quiebres(ab->izq, HIJO_IZQ) + _ab_quiebres(ab->der, HIJO_DER);
}

size_t ab_quiebres(const ab_t* ab) {
    if (ab == NULL)
        return 0;

    return _ab_quiebres(ab, PADRE);
}