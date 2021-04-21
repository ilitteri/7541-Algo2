/*
Implementar en C una primitiva para el heap heap_t* heap_diferencia(const heap_t* h1, const heap_t* h2,
cmp_funct_t nueva_cmp) que reciba dos heaps (cuyos datos son cadenas) y devuelva un nuevo heap que tenga la
diferencia de los elementos del primer heap con los del segundo (como en conjuntos, los elementos que se encuentran en h1
pero no en h2). Los heaps pueden tener misma función de comparación, o no, pero el heap resultante deberá usar como
función de comparación pasada por parámetro (nueva_cmp). Se puede asumir que cada heap tiene cada elemento una
única vez. La primitiva debe ejecutar en O(n + m), siendo n la cantidad de elementos de h1 y m la cantidad de elementos
de h2 (no se considerará como bien el ejercicio si no cumple con la complejidad). Justificar la complejidad del algoritmo
implementado.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include "heap.c"

typedef void (*heap_aplicar)(void *);

void heap_recorrer(const heap_t *fuente, heap_t *destino, size_t pos_padre, size_t pos_hijo_izq, size_t pos_hijo_der, size_t n, heap_aplicar func) {
    if (pos_padre >= n)
        return;
    copiar_heap(fuente, destino, pos_hijo_izq, 2 * pos_hijo_izq + 1, 2 * pos_hijo_izq + 2, func);
    func(destino, fuente->datos[pos_padre]);
    copiar_heap(fuente, destino, pos_hijo_der, 2 * pos_hijo_der + 1, 2 * pos_hijo_der + 2, func);
}

heap_t *heap_diferencia(const heap_t* h1, const heap_t* h2, cmp_funct_t nueva_cmp) {
    heap_t *diferencia;

    if ((diferencia = heap_crear(nueva_cmp)) == NULL)
        return NULL;

    size_t n = heap_cantidad(h1);
    for (size_t i = 0; i < n; heap_encolar(diferencia, h1->datos[i++]);

    size_t m = heap_cantidad(h2);
    for (size_t j = 0; j < m; j++) {
        if (nueva_cmp())
    }

    // Hace una copia del h1.
    heap_recorrer(h1, diferencia, 0, 1, 2, heap_cantidad(h1), heap_encolar);
    // 
    heap_recorrer(h2, diferencia, 0, 1, 2, heap_cantidad(h2), heap_desencolar);
    return diferencia;
}