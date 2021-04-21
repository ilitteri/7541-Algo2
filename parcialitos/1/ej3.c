/*
Implementar una primitiva void pila_invertir(pila_t* pila) para una Pila Enlazada, que invierta el orden de sus
elementos, sin utilizar estructuras auxiliares (i.e.en espacio constante). Indicar y justificar la complejidad de la primitiva. La
estructura interna de la pila es la siguiente:
*/

#include "pila.h"

#include <stdlib.h>

typedef struct nodo_pila {
    void *dato;
    struct nodo_pila *anterior;
} nodo_pila_t;

typedef struct pila {
    nodo_pila_t *tope;
} pila_t;

// Invierte una pila
// Pre: la pila fue creada.
// Post: la pila fue invertida (en caso de que haya tenido elementos apilados)
// Complejidad: O(n) donde n es el numero de elementos apilados en la pila, ya
//              que las demas operaciones son constantes.
//
// T(n) = O(1) + O(1) + O(1) + O(1) + O(n) * 4 * O(1) + O(1)
//      = O(n)
void pila_invertir(pila_t *pila) {
    if (pila_esta_vacia(pila)) // O(1)
        return; // O(1)

    nodo_pila_t *actual = pila->tope; // O(1)
    nodo_pila_t *anterior = actual != NULL ? actual->anterior : NULL; // O(1)
    nodo_pila_t *siguiente = NULL; // O(1)

    while (actual != NULL) {
        actual->anterior = siguiente; // O(1)
        siguiente = actual; // O(1)
        actual = anterior; // O(1)
        anterior = actual != NULL ? actual->anterior : NULL; // O(1)
    } // O(n) * 4 O(1)

    pila->tope = siguiente; // O(1)
}