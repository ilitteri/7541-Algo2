#include "tp0.h"

/* *****************************************************************
 *                     FUNCIONES A COMPLETAR                       *
 *         (ver en tp0.h la documentación de cada función)         *
 * *****************************************************************/

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}


int maximo(int vector[], int n) {
    if (!n || n == 1)
        return --n;

    int max = vector[--n];
    int max_i = n;

    for (; n >= 0; n--) {
        if (vector[n] >= max) {
            max = vector[n];
            max_i = n;
        }
    }
    return max_i;
}


int comparar(int vector1[], int n1, int vector2[], int n2) {
    int i, min_i = (n1 > n2) ? n2 : n1;
    
    for (i = 0; i < min_i; i++) {
        if (vector1[i] > vector2[i])
            return 1;
        if (vector1[i] < vector2[i])
            return -1;
    }
    
    return (n1 > n2) ? 1 : (n1 < n2) ? -1 : 0;
}

void seleccion(int vector[], int n) { 
    int i, max_i;

    for (i = n-1; i >= 0; i--) {
        max_i = maximo(vector, i+1);
        if (max_i != i) 
            swap(&vector[i], &vector[max_i]);
    }
}
