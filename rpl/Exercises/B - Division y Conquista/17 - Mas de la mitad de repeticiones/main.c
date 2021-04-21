#include "main.h" // No borrar

bool _mas_de_mitad(int *arr, size_t inicio, size_t fin, size_t n, int *contador) {

    if (*contador > n / 2)
        return true;

    int elem = arr[inicio];

    while (inicio <= fin) {
        if (elem == arr[inicio])
            *contador++;
        inicio++;
    }

    size_t medio = (inicio + fin) / 2;

    return _mas_de_mitad(arr, inicio, medio, (medio - inicio) + 1, &contador) && _mas_de_mitad(arr, medio, fin, (fin - medio) + 1, &contador);
}

bool mas_de_mitad(int* arr, size_t n) {
    if (n == 1)
        return true;

    int *contador = 0;
    
    return _mas_de_mitad(arr, 0, n-1, n, &contador);
}