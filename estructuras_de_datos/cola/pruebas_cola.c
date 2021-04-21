#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "testing.h"

#include "cola.h"
#include "pila.h"

#define VOLUMEN 10000

static void prueba_cola_vacia(void) {
    printf("INICIO DE PRUEBAS DE cola VACIA\n");

    /* Creo una cola */
    cola_t *cola = cola_crear();

    int valor0 = 9;


    /* Inicio Pruebas */

    /* Pruebo que la cola se crea vacia */
    print_test("La cola esta vacia (es true)", cola_esta_vacia(cola) == true);

    /* Encolo elementos para probar que siempre que agregue elementos es false */
    print_test("Encolo valor0", cola_encolar(cola, &valor0) == true);
    print_test("La cola esta vacia (es false)", cola_esta_vacia(cola) == false);
    print_test("La cola esta no vacia (es true)", !cola_esta_vacia(cola) == true);

    /* Desencolo el unico elemento para probar que si la cola se queda sin
    elementos, esta vacia siempre */
    print_test("Desencolo valor0", cola_desencolar(cola) == &valor0);
    print_test("La cola esta vacia (es true)", cola_esta_vacia(cola) == true);
    print_test("La cola no esta vacia (es false)", !cola_esta_vacia(cola) == false);

    /* Destruyo la cola */
    cola_destruir(cola, NULL);
    printf("Destruyo la cola\n");
}

static void pruebas_unitarias(void) {
    printf("INICIO PRUEBAS UNITARIAS");

    /* Creo una cola */
    cola_t *cola = cola_crear();

    /* Creo los valores a usar */
    int valor0 = 9;
    int valor1 = 87;
    int valor2 = 54;
    int valor3 = 167;
    int valor4 = 897;

    /* Inicio Pruebas */

    /* Acolaciones y desacolaciones intercaladas */
    print_test("La cola esta vacia", cola_esta_vacia(cola) == true);
    /* Encolo valor0, lo veo, y luego lo desencolo */
    print_test("Encolo valor0", cola_encolar(cola, &valor0) == true);
    print_test("La cola no esta vacia", !cola_esta_vacia(cola) == true);
    print_test("Valor0 es el primero", cola_ver_primero(cola) == &valor0);
    print_test("Desencolo valor0", cola_desencolar(cola) == &valor0);
    print_test("La cola esta vacia", cola_esta_vacia(cola) == true);
    /* Encolo valor1, lo veo, y luego lo desencolo */
    print_test("Encolo valor1", cola_encolar(cola, &valor1) == true);
    print_test("La cola no esta vacia", !cola_esta_vacia(cola) == true);
    print_test("Valor1 es el primero", cola_ver_primero(cola) == &valor1);
    print_test("Desencolo valor1", cola_desencolar(cola) == &valor1);
    print_test("La cola esta vacia", cola_esta_vacia(cola) == true);
    /* Encolo valor2, lo veo, y luego lo desencolo */
    print_test("Encolo valor2", cola_encolar(cola, &valor2) == true);
    print_test("La cola no esta vacia", !cola_esta_vacia(cola) == true);
    print_test("Valor2 es el primero", cola_ver_primero(cola) == &valor2);
    print_test("Desencolo valor2", cola_desencolar(cola) == &valor2);
    print_test("La cola esta vacia", cola_esta_vacia(cola) == true);
    /* Encolo valor3, lo veo, y luego lo desencolo */
    print_test("Encolo valor3", cola_encolar(cola, &valor3) == true);
    print_test("La cola no esta vacia", !cola_esta_vacia(cola) == true);
    print_test("Valor3 es el primero", cola_ver_primero(cola) == &valor3);
    print_test("Desencolo valor3", cola_desencolar(cola) == &valor3);
    print_test("La cola esta vacia", cola_esta_vacia(cola) == true);
    /* Encolo valor4, lo veo, y luego lo desencolo */
    print_test("Encolo valor4", cola_encolar(cola, &valor4) == true);
    print_test("La cola no esta vacia", !cola_esta_vacia(cola) == true);
    print_test("Valor4 es el primero", cola_ver_primero(cola) == &valor4);
    print_test("Desencolo valor4", cola_desencolar(cola) == &valor4);
    print_test("La cola esta vacia", cola_esta_vacia(cola) == true);

    /* Acolaciones seguidas y desacolaciones seguidas */
    print_test("La cola esta vacia", cola_esta_vacia(cola) == true);
    /* Encolo valor0, valor1, valor2, valor3, valor4 uno atras de otro */
    /* Encolo valor0 */
    print_test("Encolo valor0", cola_encolar(cola, &valor0) == true);
    print_test("La cola no esta vacia", !cola_esta_vacia(cola) == true);
    print_test("Valor0 es el primero", cola_ver_primero(cola) == &valor0);
    /* Encolo valor1 */
    print_test("Encolo valor1", cola_encolar(cola, &valor1) == true);
    print_test("La cola no esta vacia", !cola_esta_vacia(cola) == true);
    print_test("Valor0 es el primero", cola_ver_primero(cola) == &valor0);
    /* Encolo valor2 */
    print_test("Encolo valor2", cola_encolar(cola, &valor2) == true);
    print_test("La cola no esta vacia", !cola_esta_vacia(cola) == true);
    print_test("Valor0 es el primero", cola_ver_primero(cola) == &valor0);
    /* Encolo valor3 */
    print_test("Encolo valor3", cola_encolar(cola, &valor3) == true);
    print_test("La cola no esta vacia", !cola_esta_vacia(cola) == true);
    print_test("Valor0 es el primero", cola_ver_primero(cola) == &valor0);
    /* Encolo valor4 */
    print_test("Encolo valor4", cola_encolar(cola, &valor4) == true);
    print_test("La cola no esta vacia", !cola_esta_vacia(cola) == true);
    print_test("Valor0 es el primero", cola_ver_primero(cola) == &valor0);

    /* Desencolo valor0, valor1, valor2, valor3, valor4 uno atras de otro */
    /* Desencolo valor0 */
    print_test("Desencolo valor0", cola_desencolar(cola) == &valor0);
    print_test("La cola no esta vacia", !cola_esta_vacia(cola) == true);
    print_test("Valor1 es el primero", cola_ver_primero(cola) == &valor1);
    /* Desencolo valor1 */
    print_test("Desencolo valor1", cola_desencolar(cola) == &valor1);
    print_test("La cola no esta vacia", !cola_esta_vacia(cola) == true);
    print_test("Valor2 es el primero", cola_ver_primero(cola) == &valor2);
    /* Desencolo valor2 */
    print_test("Desencolo valor2", cola_desencolar(cola) == &valor2);
    print_test("La cola no esta vacia", !cola_esta_vacia(cola) == true);
    print_test("Valor3 es el primero", cola_ver_primero(cola) == &valor3);
    /* Desencolo valor3 */
    print_test("Desencolo valor3", cola_desencolar(cola) == &valor3);
    print_test("La cola no esta vacia", !cola_esta_vacia(cola) == true);
    print_test("Valor4 es el primero", cola_ver_primero(cola) == &valor4);
    /* Desencolo valor4 */
    print_test("Desencolo valor4", cola_desencolar(cola) == &valor4);
    print_test("La cola esta vacia", cola_esta_vacia(cola) == true);
    print_test("No hay primero", cola_ver_primero(cola) == NULL);

    /* Destruyo la cola */
    cola_destruir(cola, NULL);
    printf("Destruyo la cola\n");
}

static void prueba_encolar_arrays(void) {
    printf("INICIO PRUEBAS DE ENCOLAR ARRAYS\n");

    /* Creo una cola */
    cola_t *cola = cola_crear();

    /* Creo un vector de caracteres (string) */
    char vec[] = "prueba de que la cola encola correctamente un string";
    size_t largo = strlen(vec);

    /* Inicio Pruebas */

    /* La cola se crea vacia */
    print_test("La cola no esta vacia (es false)", !cola_esta_vacia(cola) == false);

    /* Encolo los elementos del array */
    bool encolado = true;
    for (int i = 0; vec[i] != '\0'; encolado &= cola_encolar(cola, &vec[i++]));
    print_test("Cargo el string en la cola", encolado == true && !cola_esta_vacia(cola) == true);
    /* Pruebo que el primer elemento agregado no es el caracter nulo ('\0') */
    print_test("El primer elemento agregado no es \'\\0\'", *(char *)cola_ver_primero(cola) != '\0');
    /* Pruebo que el primer elemento agregado es el primer elemento del array */
    print_test("El primer elemento agregado es el primer elemento del array", cola_ver_primero(cola) == &vec[0]);
    /* Desencolo el array entero y pruebo que cada valor se haya encolado en orden */
    bool desencolado = true;
    for (size_t i = 0; i < largo; i++)
        desencolado &= cola_ver_primero(cola) == &vec[i] && cola_desencolar(cola) == &vec[i];
    print_test("Desencolo el string", desencolado == true && cola_esta_vacia(cola) == true);

    /* Destruyo la cola */
    cola_destruir(cola, NULL);
    printf("Destruyo la cola\n");
}

static void prueba_casos_null(void) {
    printf("INICIO PRUEBAS DE CASOS DE NULL\n");

    /* Creo una cola */
    cola_t *cola = cola_crear();

    /* Inicio Pruebas */

    /* La cola se crea vacia */
    print_test("La cola esta vacia (es true)", cola_esta_vacia(cola) == true);
    print_test("La cola no esta vacia (es false)", !cola_esta_vacia(cola) == false);

    /* Pruebo que no puedo desencolar un elemento de una cola vacia */
    print_test("Desencolo cola vacia (es NULL)", cola_desencolar(cola) == NULL);

    /* Pruebo que no puedo ver el primero de una cola vacia */
    print_test("Veo el primero de cola vacia (es NULL)", cola_ver_primero(cola) == NULL);

    /* Encolo NULL, pruebo que no esta vacia, veo el primero, la desencolo y pruebo
    que luego esta vacia */
    print_test("Encolo NULL", cola_encolar(cola, NULL) == true);
    print_test("Cola no esta vacia (es true)", !cola_esta_vacia(cola) == true);
    print_test("Ver primero (es NULL)", cola_ver_primero(cola) == NULL);
    print_test("Desencolar cola (es NULL)", cola_desencolar(cola) == NULL);
    print_test("Cola esta vacia", cola_esta_vacia(cola) == true);

    /* Destruyo la cola */
    cola_destruir(cola, NULL);
    printf("Destruyo la cola\n");
}

/* Creo una funcion auxiliar para que funcione el codigo */
void _pila_destruir(void *pila) {
    pila_destruir((pila_t *) pila);
}

static void pruebas_condiciones_borde(void) {
    printf("INICIO PRUEBAS DE CONDICIONES BORDE\n");

    /* Creo una cola */
    cola_t *cola = cola_crear();

    /* Creo los valores a usar */
    int valor1 = 87;
    int valor2 = 54;
    int valor3 = 167;
    int valor4 = 897;

    /* Compruebo que la acción de esta_vacía en una cola recién creada es verdadero.*/
    print_test("La cola recien creada esta vacia", cola_esta_vacia(cola) == true);

    /* Compruebo que las acciones de desencolar y ver_primero en una cola recién
     creada son inválidas.*/
    print_test("No puedo desencolar una cola recien creada", cola_desencolar(cola) == NULL);
    print_test("No puedo ver el primero de una cola recien creada", cola_ver_primero(cola) == NULL);

    /* Encolo y desencolo valores */
    print_test("Encolo valor1", cola_encolar(cola, &valor1) == true);
    print_test("Valor1 es el primero", cola_ver_primero(cola) == &valor1);
    print_test("Desencolo valor1", cola_desencolar(cola) == &valor1);
    print_test("No hay mas primero", cola_ver_primero(cola) == NULL);
    print_test("Encolo valor3", cola_encolar(cola, &valor3) == true);
    print_test("Valor3 es el primero", cola_ver_primero(cola) == &valor3);
    print_test("Desencolo valor3", cola_desencolar(cola) == &valor3);
    print_test("No hay mas primero", cola_ver_primero(cola) == NULL);
    print_test("Encolo valor2", cola_encolar(cola, &valor2) == true);
    print_test("Valor2 es el primero", cola_ver_primero(cola) == &valor2);
    print_test("Encolo valor4", cola_encolar(cola, &valor4) == true);
    print_test("Valor2 es el primero", cola_ver_primero(cola) == &valor2);
    print_test("Desencolo valor2", cola_desencolar(cola) == &valor2);
    print_test("Valor2 no es mas el primero", cola_ver_primero(cola) != &valor2);
    print_test("Valor4 es ahora el primero", cola_ver_primero(cola) == &valor4);
    print_test("Desencolo valor4", cola_desencolar(cola) == &valor4);
    print_test("No hay mas primero", cola_ver_primero(cola) == NULL);
    print_test("Ahora la cola se comporta como recien creada", cola_desencolar(cola) == NULL && cola_ver_primero(cola) == NULL);
    
    /* Destruyo la cola */
    cola_destruir(cola, NULL);
    printf("Destruyo la cola\n");


    /* Repito lo anterior, pero sin desencolar, para luego destruir con la funcion destruir_dato */

    /* Creo una nueva cola */
    cola_t *cola2 = cola_crear();

    /* Compruebo que las acciones de desencolar y ver_primero en una cola recién
     creada son inválidas.*/
    print_test("No puedo desencolar una cola recien creada", cola_desencolar(cola2) == NULL);
    print_test("No puedo ver el primero de una cola recien creada", cola_ver_primero(cola2) == NULL);

    /* Encolo valores */
    print_test("Encolo valor1", cola_encolar(cola2, &valor1) == true);
    print_test("Valor1 es el primero", cola_ver_primero(cola2) == &valor1);
    print_test("Encolo valor3", cola_encolar(cola2, &valor3) == true);
    print_test("Valor1 es el primero", cola_ver_primero(cola2) == &valor1);
    print_test("Encolo valor2", cola_encolar(cola2, &valor2) == true);
    print_test("Valor1 es el primero", cola_ver_primero(cola2) == &valor1);
    print_test("Encolo valor4", cola_encolar(cola2, &valor4) == true);
    print_test("Valor1 es el primero", cola_ver_primero(cola2) == &valor1);

    /* Destruyo la cola con datos */
    cola_destruir(cola2, NULL);
    printf("Destruyo la cola y los datos\n");

    /* Creo una nueva cola, esta vez para encolarle pilas y probar una nueva funcion destruir dato */
    cola_t *cola3 = cola_crear();

    /* Creo las pilas */
    pila_t *pila0 = pila_crear();
    pila_t *pila1 = pila_crear();
    pila_t *pila2 = pila_crear();


    /* Compruebo que las acciones de desencolar y ver_primero en una cola recién
    creada son inválidas.*/
    print_test("No puedo desencolar una cola recien creada", cola_desencolar(cola3) == NULL);
    print_test("No puedo ver el primero de una cola recien creada", cola_ver_primero(cola3) == NULL);

    /* Encolo las pilas*/
    print_test("Encolo pila0", cola_encolar(cola3, pila0) == true && !cola_esta_vacia(cola3));
    print_test("Pila0 es el primer elemento", cola_ver_primero(cola3) == pila0);
    print_test("Encolo pila1", cola_encolar(cola3, pila1) == true && !cola_esta_vacia(cola3));
    print_test("Encolo pila2", cola_encolar(cola3, pila2) == true && !cola_esta_vacia(cola3));

    cola_destruir(cola3, _pila_destruir);
    printf("Destruyo cola de pilas\n");

}

static void pruebas_volumen(void) {
    printf("INICIO PRUEBAS DE VOLUMEN\n");

    /* Creo una cola */
    cola_t *cola = cola_crear();

    int valor = 32;

    /* Encolo volumen elementos y pruebo que la cola no esta vacia, y que su primero
    es el ultimo valor que tomo "i" */
    bool encolado = true;
    for (int i = 0; i < VOLUMEN; i++)
        encolado &= cola_encolar(cola, &valor) == true && cola_ver_primero(cola) == &valor;
    print_test("Encolo volumen", encolado == true && !cola_esta_vacia(cola) == true);
    print_test("El primero es 1023", cola_ver_primero(cola) == &valor);

    /* Desencolo volumen y pruebo que todos tengan el mismo valor*/
    bool desencolado = true;
    for (int i = 1; i <= VOLUMEN; i++)
        desencolado &= cola_ver_primero(cola) == &valor && cola_desencolar(cola) == &valor;
    print_test("Desencolo volumen", desencolado == true && cola_esta_vacia(cola) == true);

    /* Encolo volumen de NULL, pruebo que no esta vacia, veo el primero, la desencolo y
    pruebo que luego esta vacia */
    for (int i = 0; i < VOLUMEN; i++)
        encolado &= cola_encolar(cola, NULL) == true && cola_ver_primero(cola) == NULL;
    print_test("Encolo volumen de NULL", encolado == true);
    print_test("cola no esta vacia (es true)", !cola_esta_vacia(cola) == true);
    print_test("Ver primero (es NULL)", cola_ver_primero(cola) == NULL);
    for (int i = 0; i < VOLUMEN; i++)
        desencolado &= cola_ver_primero(cola) == NULL && cola_desencolar(cola) == NULL;
    print_test("Desencolar volumen de NULL", cola_esta_vacia(cola) == true);

    /* Destruyo la cola */
    cola_destruir(cola, NULL);
    printf("Destruyo la cola\n");
}

void pruebas_cola_estudiante() {
    prueba_cola_vacia();
    pruebas_unitarias();
    prueba_encolar_arrays();
    prueba_casos_null();
    pruebas_condiciones_borde();
    pruebas_volumen();
}

#ifndef CORRECTOR  // Para que no dé conflicto con el main() del corrector.

int main(void) {
    pruebas_cola_estudiante();
    return failure_count() > 0;  // Indica si falló alguna prueba.
}

#endif
