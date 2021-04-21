#include "main.h" // No borrar

bool _arreglo_ordenado(int arr[], size_t inicio, size_t fin) {
    if (fin - inicio == 1)
        return arr[fin] >= arr[inicio];

    size_t medio = (inicio + fin) / 2;

    return _arreglo_ordenado(arr, inicio, medio) && _arreglo_ordenado(arr, medio, fin);
}

bool arreglo_ordenado(int arr[], size_t n) {
    return n <= 1 ? true : _arreglo_ordenado(arr, 0, n-1);
}