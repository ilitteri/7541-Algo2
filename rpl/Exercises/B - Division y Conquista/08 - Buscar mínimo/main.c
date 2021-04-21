#include "main.h" // No borrar

#define min(a, b) a < b ? a : b;

int _buscar_minimo(int arr[], size_t inicio, size_t fin)
{
    if (inicio == fin)
    {
        return arr[inicio];
    }
    size_t mid = (inicio + fin) / 2;
    return min(_buscar_minimo(arr, 0, mid), _buscar_minimo(arr, mid+1, fin));
}

int buscar_minimo(int arr[], size_t n) 
{
    return _buscar_minimo(arr, 0, n-1);
}