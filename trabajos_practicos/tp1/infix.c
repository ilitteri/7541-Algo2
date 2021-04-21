#define  _POSIX_C_SOURCE 200809L // para getline

// Librerias generales

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Librerias locales a usar

#include "calc_helper.h"
#include "strutil.h"

// Estructuras a usar

#include "pila.h"
#include "cola.h"

// Prototipo de funciones internas infix.c

bool shunting_yard(char **tokens);
char get_operator(struct calc_token *token); 
void classify_tokens(struct calc_token *token);
void print_reverse_polish_notation(cola_t *out);

int main() {
    char *line = NULL;
    size_t size;

    while (getline(&line, &size, stdin) != -1) {
        // Separo las palabras de la linea.
        char **tokens = infix_split(line);

        // Si no se pudo reservar suficiente memoria, devuelvo false.
        if (tokens == NULL)
            continue;
        
        // Si el algoritmo de shunting yard sale bien, imprimo la salida.
        if (!shunting_yard(tokens))
            printf("ERROR\n");
    }
    free(line);
    return 0;
}

/* Algoritmo shunting_yard, parsea ecuaciones de notacion infija, si lo
anterior sale bien, imprime la salida */
bool shunting_yard(char **tokens) {
    // Crea la cola de salida.
    cola_t *out = cola_crear();
    // Si no se pudo reservar suficiente memoria, devuelvo false.
    if (out == NULL)
        return false;
    // Crea la pila de operadores.
    pila_t *operators = pila_crear();
    // Si no se pudo reservar suficiente memoria, destruyo la cola
    // y devuelvo false.
    if (operators == NULL) {
        cola_destruir(out, NULL);
        return false;
    }

    bool ok = true;
    for (size_t i = 0; tokens[i] != NULL; i++) {
        // Reservo memoria para el parseo del token
        struct calc_token *parsed = malloc(sizeof(struct calc_token));

        // Si no se pudo reservar suficiente memoria, devuelvo NULL
        if (parsed == NULL)
            return false;

        if (!calc_parse(tokens[i], parsed)) {
            // Si el parseo sale mal la variable booleana va a hacer saltar
            // un error y, llegado ese momento la pila estara vacia y
            // destruida, entonces solo se vaciara la cola de salida.
            ok = false;
            free(parsed);
        }

        else if (parsed->type == TOK_NUM)
            // Si el parsed es un numero entonces lo encolo en la cola de
            // salida.
            ok &= cola_encolar(out, parsed);

        else if (parsed->type == TOK_OPER) {
            // Si el parsed es un operador entonces:
            // Mientras haya otro operador en el tope de la pila de 
            // operadores, excluyendo a los parentesis, y el parsed es 
            // asociativo izquierdo y su precedencia es menor o igual que 
            // la precedencia la del operador del tope de la pila, ó el 
            // parsed es asociativo derecho y su precedencia es menor que la
            // del operador del topo de lapila, desapilo la pila en la cola
            // de salida.
            struct calc_token *tail;
            while (!pila_esta_vacia(operators) && 
                (tail = pila_ver_tope(operators))->type == TOK_OPER && 
                ((parsed->oper.asociatividad == ASSOC_LEFT && parsed->oper.precedencia <= tail->oper.precedencia) || 
                (parsed->oper.asociatividad == ASSOC_RIGHT && parsed->oper.precedencia < tail->oper.precedencia)))
                ok &= cola_encolar(out, pila_desapilar(operators));
            ok &= pila_apilar(operators, parsed);
        }

        else if (parsed->type == TOK_LPAREN)
            // Si el parsed es un parentesis abierto, entonces lo encolo en
            // la cola de salida.
            ok &= pila_apilar(operators, parsed);

        else if (parsed->type == TOK_RPAREN) {
            // Si el parsed es un parentesis cerrado, desapilo los operadores
            // en la cola de salida hasta que me encuentre con el otro
            // parentesis.
            while (((struct calc_token *)pila_ver_tope(operators))->type != TOK_LPAREN)
                ok &= cola_encolar(out, pila_desapilar(operators));
            // Libero el parentesis cerrado
            free(parsed);
            // Desapilo el parentesis restante
            free(pila_desapilar(operators));
        }
        else
            // El token es de tipo erroneo.
            ok = false;
    }
    // Libero el arreglo dinamico de tokens
    free_strv(tokens);

    // Desapilo operadores restantes en la cola de salida en caso de existir
    while(!pila_esta_vacia(operators))
        ok &= cola_encolar(out, pila_desapilar(operators));

    // Destruyo la pila
    pila_destruir(operators);

    // Si algun movimiento de estructuras salio mal, se desencola lo encolado,
    // se destruye la cola y se retorna un false que imprimira un error.
    // Si sale todo bien, se imprime la salida esperada.
    if (!ok)
        // Si no se encolaron los tokens correctamente, imprimo un error.
        cola_destruir(out, free);

    else 
        print_reverse_polish_notation(out);

    return ok;
}

/* Imprime los operadores en la salida */
char get_operator(struct calc_token *token) {
    switch (token->oper.op) {
        case OP_ADD: return('+');
        case OP_SUB: return('-');
        case OP_MUL: return('*');
        case OP_DIV: return('/');
        case OP_POW: return('^');
        default:
            return '\0';
    }
}

/* Clasifica los tokens en la salida */
void classify_tokens(struct calc_token *token) {
    // Imprime el token, sea de tipo numero o tipo opeardor

    if (token->type == TOK_NUM)
        // Si el token es de tipo numero, imprime su valor
        printf("%ld ", token->value);
    else
        // Si el token es de tipo operador, imprime su simbolo
        printf("%c ", get_operator(token));
    //Libero el token
    free(token);
}

/* Imprime la salida */
void print_reverse_polish_notation(cola_t *out) {
    // Imprime la cola de salida

    while (!cola_esta_vacia(out))
        // Mientras la cola de salida no esta vacia, imprime el token
        classify_tokens(cola_desencolar(out));
    putchar('\n');
    // Destruye la cola vacia
    cola_destruir(out, NULL);
}