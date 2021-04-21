#include "main.h" // No borrar

/* viborita */

bool arreglo_magico(int arr[], size_t inicio, size_t fin) {
    if (fin == inicio)
        return arr[inicio] == inicio;

    size_t medio = (inicio + fin) / 2;

    if (arr[medio] == medio)
        return true;
    
    return arr[medio] < medio ? arreglo_magico(arr, medio+1, fin) : arreglo_magico(arr, inicio, medio);
}

bool arreglo_es_magico(int arr[], size_t n) {
    return arreglo_magico(arr, 0, n-1);
}