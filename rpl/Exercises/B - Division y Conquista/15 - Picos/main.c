#include "main.h" // No borrar

/* viborita */

size_t posicion_pico(int v[], size_t ini, size_t fin) {
    
    size_t med = (ini + fin) / 2;

    if (v[med] > v[med-1] && v[med] > v[med+1])
        return med;
        
    return (v[med] < v[ini]) ? posicion_pico(v, ini, med-1) : posicion_pico(v, med+1, fin);
}