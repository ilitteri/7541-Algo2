Implementar un algoritmo en C que reciba un arreglo de enteros de tamaño nn, ordenado ascendentemente y sin elementos repetidos, y determine en _O(log n)_ si es mágico. Un arreglo es mágico si existe algún valor _i_ tal que 0 <= i y `arr[i] = i`. Justificar el orden del algoritmo.

Ejemplos:

A = [ -3, 0, 1, 3, 7, 9 ] es mágico porque A[3] = 3.

B = [ 1, 2, 4, 6, 7, 9 ] no es mágico porque B[i] != i para todo i.