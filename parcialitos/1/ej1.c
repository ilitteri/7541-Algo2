/*
Implementar una función float min_distancia(float arr[], size_t n) (n ≥ 2) y devuelva en O(n log n) cuál es la
distancia minima entre todos los elementos del arreglo arr. Por ejemplo, la distancia mínima en el arreglo [1.0, 7.5,
3.4, 9.2, 13.1, 6.9] es 0.6 (la distancia entre 7.5 y 6.9). Indicar y justificar adecuadamente la complejidad de la
función implementada. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(float arr[], float arr_ord[], size_t inicio, size_t medio, size_t fin) {
   size_t i, j, k;

    for(i = inicio, j = medio + 1, k = inicio; i <= medio && j <= fin; k++) {
        if(arr[i] <= arr[j])
            arr_ord[k] = arr[i++];
        else
            arr_ord[k] = arr[j++];
    }
   
    while(i <= medio)    
        arr_ord[k++] = arr[i++];

    while(j <= fin)   
        arr_ord[k++] = arr[j++];

    for(k = inicio; k <= fin; k++)
        arr[k] = arr_ord[k];
}

void ordenar(float arr[], float arr_ord[], size_t inicio, size_t fin) {
    size_t medio;
   
    if(inicio < fin) {
        medio = (inicio + fin) / 2;
        ordenar(arr, arr_ord, inicio, medio);
        ordenar(arr, arr_ord, medio+1, fin);
        merge(arr, arr_ord, inicio, medio, fin);
    } 

    return;
}

float calcular_min_distancia(float arr[], size_t inicio, size_t fin) {
    if ((fin - inicio) == 1)
        return arr[inicio] > arr[fin] ? arr[inicio] - arr[fin] : arr[fin] - arr[inicio];
    
    size_t medio = (inicio + fin) / 2;
    float min_izq = calcular_min_distancia(arr, inicio, medio);
    float min_der = calcular_min_distancia(arr, medio, fin);

    return min_izq < min_der ? min_izq : min_der;  
}

float obtener_min_distancia(float arr[], size_t n) {
    if (n == 2)
        return arr[0] > arr[1] ? arr[0] - arr[1] : arr[1] - arr[0];

    float arr_ord[n];
    float min = -1.0;

    ordenar(arr, arr_ord, 0, n-1);

    return calcular_min_distancia(arr, 0, n);
}

int main() {
    float arr[] = {1.0, 7.5, 3.4, 9.2, 13.1, 6.9};

    printf("%.1f\n", obtener_min_distancia(arr, 6));

    return 0;
}