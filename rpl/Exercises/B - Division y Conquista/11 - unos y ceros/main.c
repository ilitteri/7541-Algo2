#include "main.h" // No borrar

#define medio(inicio, fin) (int)(inicio + fin) / 2

int _primer_cero(int arr[], size_t inicio, size_t fin) {
    return !arr[medio(inicio, fin)] ? arr[medio(inicio, fin)-1] ? medio(inicio, fin) : _primer_cero(arr, inicio, medio(inicio, fin)) : _primer_cero(arr, medio(inicio, fin)+1, fin);
}

int primer_cero(int arr[], size_t n) {
    return arr[n-1] ? -1 : !arr[0] ? 0 : _primer_cero(arr, 0, n-1);
}

// #include "main.h" // No borrar

// int _primer_cero(int arr[], size_t inicio, size_t fin) {
//     if (fin == inicio) 
//         return !arr[inicio] ? arr[inicio] : -1;

//     size_t medio = (inicio + fin) / 2;

//     if (!arr[medio])
//         return arr[medio-1] ? (int)medio : _primer_cero(arr, inicio, medio);

//     return _primer_cero(arr, medio+1, fin);
// }

// int primer_cero(int arr[], size_t n) {
//     if (arr[n-1] == 1)
//         return -1;
//     if (!arr[0])
//         return 0;
//     return _primer_cero(arr, 0, n-1);
// }

// #include "main.h" // No borrar

// int _primer_cero(int arr[], size_t inicio, size_t fin)
// {
//     if (inicio == fin)
//     {
//         return arr[inicio] == 0 ? 0 : -1;
//     }

//     size_t mid = (inicio + fin) / 2;

//     if (arr[mid] == 0 && arr[mid-1] == 1)
//     {
//         return (int)mid;
//     }

//     else if (arr[mid] == 0 && arr[mid-1] == 0)
//     {
//         return _primer_cero(arr, inicio, mid);
//     }

//     else if (arr[mid] == 1 && arr[mid+1] == 0)
//     {
//         return (int)mid+1;
//     }

//     else if(arr[mid] == 1 && arr[mid+1] == 1)
//     {
//         return _primer_cero(arr, mid+1, fin);
//     }
// }

// int primer_cero(int arr[], size_t n) {
//     return _primer_cero(arr, 0, n-1);
// }