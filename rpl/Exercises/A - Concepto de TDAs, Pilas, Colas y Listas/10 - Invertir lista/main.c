#include "lista.h"
#include "lista_struct.h"

void lista_invertir(lista_t* lista) {
	nodo_t *prev = NULL;
	nodo_t *actual = lista->primero;   

	while (actual != NULL) {
		nodo_t *prox = actual->prox;

		actual->prox = prev;

		prev = actual;
		actual = prox;
	}

	lista->primero = prev;
}