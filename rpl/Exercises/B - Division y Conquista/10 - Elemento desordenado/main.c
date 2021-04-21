#include "main.h" // No borrar

int elemento_desordenado_dyc(int arr[], size_t inicio, size_t fin) {
    if (fin - inicio == 1)
        return arr[inicio] > arr[fin] ? (int)inicio : NULL;

    size_t medio = (inicio + fin) / 2; 

    int izq = elemento_desordenado_dyc(arr, inicio, medio);

    return izq ? izq : elemento_desordenado_dyc(arr, medio, fin);
}

int elemento_desordenado(int arr[], size_t n) {
    return arr[elemento_desordenado_dyc(arr, 0, n-1)];
}