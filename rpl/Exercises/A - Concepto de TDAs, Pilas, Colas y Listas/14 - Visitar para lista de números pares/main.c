#include "lista.h"

bool visitar_suma_pares(void* dato, void* extra) {
    if (*(int *) dato % 2 == 0) {
        *(int *) extra += *(int *) dato;
        return true;
    }

    return false;
}