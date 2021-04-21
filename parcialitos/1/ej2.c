/*
Implementar una función bool ingresados_mismo_orden(cola_t* cola, pila_t* pila) que reciba una cola y una pila
y determine si sus elementos fueron ingresados (encolados y apilados, respectivamente) en el mismo orden. Considerar
que los elementos de ambas estructuras podrían ser diferentes, o tener diferente cantidad (en cuyos casos debería devolverse
false). Indicar y justificar la complejidad de la función implementada. Considerar que dos punteros guardados son iguales
si apuntan a la misma dirección de memoria.
*/

#include "pila.h"
#include "cola.h"

#include <stdio.h>

bool ingresados_mismo_orden(cola_t *cola, pila_t *pila) {
    pila_t *pilaAux = pila_crear(); // O(1)

    while(!pila_esta_vacia(pila)) // O(n)
        pila_apilar(pilaAux, pila_desapilar(pila)); // O(1)
    
    while(!pila_esta_vacia(pilaAux) || !cola_esta_vacia(cola)) // O(n+m) donde n es la longitud de la pila u O(m) donde m es la longitud de la cola
        if (pila_desapilar(pilaAux) != cola_desencolar(cola))  // O(1)
            return false;  // O(1)
    
    pila_destruir(pilaAux); // O(1)

    return true;  // O(1)
}

/*
La complejidad de este algoritmo es O(n+m) al final donde n es la cantidad de
elementos apilados u encolados (el que mas posea), en el caso ideal n es
igual para ambos.
*/