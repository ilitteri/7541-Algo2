#include "ab.h"

int ab_suma(const ab_t* ab) {
    if(!ab) return 0;
    int suma_izq = ab_suma(ab->izq);
    int suma_der = ab_suma(ab->der);
    return suma_izq + suma_der + ab->dato;
}