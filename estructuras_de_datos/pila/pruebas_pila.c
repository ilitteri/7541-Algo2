#include "pila.h"
#include "testing.h"
#include <stdio.h>
#include <string.h>

#define VOLUMEN 10000

static void prueba_pila_vacia(void) {
    printf("INICIO DE PRUEBAS DE PILA VACIA\n");

    /* Creo una pila */
    pila_t *pila = pila_crear();

    int valor0 = 9;


    /* Inicio Pruebas */

    /* Pruebo que la pila se crea vacia */
    print_test("La pila esta vacia (es true)", pila_esta_vacia(pila) == true);
    print_test("La pila no esta vacia (es false)", !pila_esta_vacia(pila) == false);

    /* Apilo elementos para probar que siempre que agregue elementos es false */
    print_test("Apilo valor0", pila_apilar(pila, &valor0) == true);
    print_test("La pila esta vacia (es false)", pila_esta_vacia(pila) == false);
    print_test("La pila esta no vacia (es true)", !pila_esta_vacia(pila) == true);

    /* Desapilo el unico elemento para probar que si la pila se queda sin
    elementos, esta vacia siempre */
    print_test("Desapilo valor0", pila_desapilar(pila) == &valor0);
    print_test("La pila esta vacia (es true)", pila_esta_vacia(pila) == true);
    print_test("La pila no esta vacia (es false)", !pila_esta_vacia(pila) == false);

    /* Destruyo la pila */
    pila_destruir(pila);
    printf("Destruyo la pila\n");
}

static void pruebas_unitarias(void) {
    printf("INICIO PRUEBAS UNITARIAS");

    /* Creo una pila */
    pila_t *pila = pila_crear();

    /* Creo los valores a usar */
    int valor0 = 9;
    int valor1 = 87;
    int valor2 = 54;
    int valor3 = 167;
    int valor4 = 897;

    /* Inicio Pruebas */

    /* Apilaciones y desapilaciones intercaladas */
    print_test("La pila esta vacia", pila_esta_vacia(pila) == true);
    /* Apilo valor0, lo veo, y luego lo desapilo */
    print_test("Apilo valor0", pila_apilar(pila, &valor0) == true);
    print_test("La pila no esta vacia", !pila_esta_vacia(pila) == true);
    print_test("Valor0 es el tope", pila_ver_tope(pila) == &valor0);
    print_test("Desapilo valor0", pila_desapilar(pila) == &valor0);
    print_test("La pila esta vacia", pila_esta_vacia(pila) == true);
    /* Apilo valor1, lo veo, y luego lo desapilo */
    print_test("Apilo valor1", pila_apilar(pila, &valor1) == true);
    print_test("La pila no esta vacia", !pila_esta_vacia(pila) == true);
    print_test("Valor1 es el tope", pila_ver_tope(pila) == &valor1);
    print_test("Desapilo valor1", pila_desapilar(pila) == &valor1);
    print_test("La pila esta vacia", pila_esta_vacia(pila) == true);
    /* Apilo valor2, lo veo, y luego lo desapilo */
    print_test("Apilo valor2", pila_apilar(pila, &valor2) == true);
    print_test("La pila no esta vacia", !pila_esta_vacia(pila) == true);
    print_test("Valor2 es el tope", pila_ver_tope(pila) == &valor2);
    print_test("Desapilo valor2", pila_desapilar(pila) == &valor2);
    print_test("La pila esta vacia", pila_esta_vacia(pila) == true);
    /* Apilo valor3, lo veo, y luego lo desapilo */
    print_test("Apilo valor3", pila_apilar(pila, &valor3) == true);
    print_test("La pila no esta vacia", !pila_esta_vacia(pila) == true);
    print_test("Valor3 es el tope", pila_ver_tope(pila) == &valor3);
    print_test("Desapilo valor3", pila_desapilar(pila) == &valor3);
    print_test("La pila esta vacia", pila_esta_vacia(pila) == true);
    /* Apilo valor4, lo veo, y luego lo desapilo */
    print_test("Apilo valor4", pila_apilar(pila, &valor4) == true);
    print_test("La pila no esta vacia", !pila_esta_vacia(pila) == true);
    print_test("Valor4 es el tope", pila_ver_tope(pila) == &valor4);
    print_test("Desapilo valor4", pila_desapilar(pila) == &valor4);
    print_test("La pila esta vacia", pila_esta_vacia(pila) == true);

    /* Apilaciones seguidas y desapilaciones seguidas */
    print_test("La pila esta vacia", pila_esta_vacia(pila) == true);
    /* Apilo valor0, valor1, valor2, valor3, valor4 uno atras de otro */
    /* Apilo valor0 */
    print_test("Apilo valor0", pila_apilar(pila, &valor0) == true);
    print_test("La pila no esta vacia", !pila_esta_vacia(pila) == true);
    print_test("Valor0 es el tope", pila_ver_tope(pila) == &valor0);
    /* Apilo valor1 */
    print_test("Apilo valor1", pila_apilar(pila, &valor1) == true);
    print_test("La pila no esta vacia", !pila_esta_vacia(pila) == true);
    print_test("Valor1 es el tope", pila_ver_tope(pila) == &valor1);
    /* Apilo valor2 */
    print_test("Apilo valor2", pila_apilar(pila, &valor2) == true);
    print_test("La pila no esta vacia", !pila_esta_vacia(pila) == true);
    print_test("Valor2 es el tope", pila_ver_tope(pila) == &valor2);
    /* Apilo valor3 */
    print_test("Apilo valor3", pila_apilar(pila, &valor3) == true);
    print_test("La pila no esta vacia", !pila_esta_vacia(pila) == true);
    print_test("Valor3 es el tope", pila_ver_tope(pila) == &valor3);
    /* Apilo valor4 */
    print_test("Apilo valor4", pila_apilar(pila, &valor4) == true);
    print_test("La pila no esta vacia", !pila_esta_vacia(pila) == true);
    print_test("Valor4 es el tope", pila_ver_tope(pila) == &valor4);

    /* Desapilo valor0, valor1, valor2, valor3, valor4 uno atras de otro */
    /* Desapilo valor4 */
    print_test("Desapilo valor4", pila_desapilar(pila) == &valor4);
    print_test("La pila no esta vacia", !pila_esta_vacia(pila) == true);
    print_test("Valor3 es el tope", pila_ver_tope(pila) == &valor3);
    /* Desapilo valor3 */
    print_test("Desapilo valor3", pila_desapilar(pila) == &valor3);
    print_test("La pila no esta vacia", !pila_esta_vacia(pila) == true);
    print_test("Valor2 es el tope", pila_ver_tope(pila) == &valor2);
    /* Desapilo valor2 */
    print_test("Desapilo valor2", pila_desapilar(pila) == &valor2);
    print_test("La pila no esta vacia", !pila_esta_vacia(pila) == true);
    print_test("Valor1 es el tope", pila_ver_tope(pila) == &valor1);
    /* Desapilo valor1 */
    print_test("Desapilo valor1", pila_desapilar(pila) == &valor1);
    print_test("La pila no esta vacia", !pila_esta_vacia(pila) == true);
    print_test("Valor0 es el tope", pila_ver_tope(pila) == &valor0);
    /* Desapilo valor0 */
    print_test("Desapilo valor0", pila_desapilar(pila) == &valor0);
    print_test("La pila esta vacia", pila_esta_vacia(pila) == true);
    print_test("No hay tope", pila_ver_tope(pila) == NULL);

    /* Destruyo la pila */
    pila_destruir(pila);
    printf("Destruyo la pila\n");
}

static void prueba_apilar_arrays(void) {
    printf("INICIO PRUEBAS DE APILAR ARRAYS\n");

    /* Creo una pila */
    pila_t *pila = pila_crear();

    /* Creo un vector de caracteres (string) */
    char vec[] = "prueba de que la pila apila correctamente un string";
    size_t largo = strlen(vec);

    /* Inicio Pruebas */

    /* La pila se crea vacia */
    print_test("La pila esta vacia (es true)", pila_esta_vacia(pila) == true);
    print_test("La pila no esta vacia (es false)", !pila_esta_vacia(pila) == false);

    /* Apilo los elementos del array */
    bool apilado = true;
    for (int i = 0; vec[i] != '\0'; apilado &= pila_apilar(pila, &vec[i++]));
    print_test("Cargo el string en la pila", apilado == true && !pila_esta_vacia(pila) == true);
    /* Pruebo que el ultimo elemento agregado no es el caracter nulo ('\0') */
    print_test("El ultimo elemento agregado no es \'\\0\'", *(char *)pila_ver_tope(pila) != '\0');
    /* Pruebo que el ultimo elemento agregado es el ultimo elemento del array */
    print_test("El ultimo elemento agregado es el ultimo elemento del array", pila_ver_tope(pila) == &vec[largo-1]);
    /* Desapilo el array entero y pruebo que cada valor se haya apilado en orden */
    bool desapilado = true;
    for (size_t i = 1; i <= largo; i++)
        desapilado &= pila_ver_tope(pila) == &vec[largo-i] && pila_desapilar(pila) == &vec[largo-i];
    print_test("Desapilo el string", desapilado == true && pila_esta_vacia(pila) == true);

    /* Destruyo la pila */
    pila_destruir(pila);
    printf("Destruyo la pila\n");
}

static void prueba_casos_null(void) {
    printf("INICIO PRUEBAS DE CASOS DE NULL\n");

    /* Creo una pila */
    pila_t *pila = pila_crear();

    /* Inicio Pruebas */

    /* La pila se crea vacia */
    print_test("La pila esta vacia (es true)", pila_esta_vacia(pila) == true);
    print_test("La pila no esta vacia (es false)", !pila_esta_vacia(pila) == false);

    /* Pruebo que no puedo desapilar un elemento de una pila vacia */
    print_test("Desapilo pila vacia (es NULL)", pila_desapilar(pila) == NULL);

    /* Pruebo que no puedo ver el tope de una pila vacia */
    print_test("Veo el tope de pila vacia (es NULL)", pila_ver_tope(pila) == NULL);

    /* Apilo NULL, pruebo que no esta vacia, veo el tope, la desapilo y pruebo
    que luego esta vacia */
    print_test("Apilo NULL", pila_apilar(pila, NULL) == true);
    print_test("Pila no esta vacia (es true)", !pila_esta_vacia(pila) == true);
    print_test("Ver tope (es NULL)", pila_ver_tope(pila) == NULL);
    print_test("Desapilar pila (es NULL)", pila_desapilar(pila) == NULL);
    print_test("Pila esta vacia", pila_esta_vacia(pila) == true);

    /* Destruyo la pila */
    pila_destruir(pila);
    printf("Destruyo la pila\n");
}

static void pruebas_condiciones_borde(void) {
    printf("INICIO PRUEBAS DE CONDICIONES BORDE\n");

    /* Creo una pila */
    pila_t *pila = pila_crear();

    /* Creo los valores a usar */
    int valor1 = 87;
    int valor2 = 54;
    int valor3 = 167;
    int valor4 = 897;

    /* Compruebo que la acción de esta_vacía en una pila recién creada es verdadero.*/
    print_test("La pila recien creada esta vacia", pila_esta_vacia(pila) == true);

    /* Compruebo que las acciones de desapilar y ver_tope en una pila recién
     creada son inválidas.*/
     print_test("No puedo desapilar una pila recien creada", pila_desapilar(pila) == NULL);
     print_test("No puedo ver el tope de una pila recien creada", pila_ver_tope(pila) == NULL);

    /* Apilo valores */
    print_test("Apilo valor1", pila_apilar(pila, &valor1) == true);
    print_test("Valor1 es el tope", pila_ver_tope(pila) == &valor1);
    print_test("Desapilo valor1", pila_desapilar(pila) == &valor1);
    print_test("No hay mas tope", pila_ver_tope(pila) == NULL);
    print_test("Apilo valor3", pila_apilar(pila, &valor3) == true);
    print_test("Valor3 es el tope", pila_ver_tope(pila) == &valor3);
    print_test("Desapilo valor3", pila_desapilar(pila) == &valor3);
    print_test("No hay mas tope", pila_ver_tope(pila) == NULL);
    print_test("Apilo valor2", pila_apilar(pila, &valor2) == true);
    print_test("Valor2 es el tope", pila_ver_tope(pila) == &valor2);
    print_test("Apilo valor4", pila_apilar(pila, &valor4) == true);
    print_test("Valor4 es el tope", pila_ver_tope(pila) == &valor4);
    print_test("Desapilo valor4", pila_desapilar(pila) == &valor4);
    print_test("Valor4 no es mas el tope", pila_ver_tope(pila) != &valor4);
    print_test("Valor2 es ahora el tope", pila_ver_tope(pila) == &valor2);
    print_test("Desapilo valor2", pila_desapilar(pila) == &valor2);
    print_test("No hay mas tope", pila_ver_tope(pila) == NULL);
    print_test("Ahora la pila se comporta como recien creada", pila_desapilar(pila) == NULL && pila_ver_tope(pila) == NULL);
    
    /* Destruyo la pila */
    pila_destruir(pila);
    printf("Destruyo la pila\n");

}

static void pruebas_volumen(void) {
    printf("INICIO PRUEBAS DE VOLUMEN\n");

    /* Creo una pila */
    pila_t *pila = pila_crear();

    int valor = 32;

    /* Apilo volumen elementos y pruebo que la pila no esta vacia, y que su tope
    es el ultimo valor que tomo "i" */
    bool apilado = true;
    for (int i = 0; i < VOLUMEN; i++)
        apilado &= pila_apilar(pila, &valor) == true && pila_ver_tope(pila) == &valor;
    print_test("Apilo volumen", apilado == true && !pila_esta_vacia(pila) == true);
    print_test("El tope es 1023", pila_ver_tope(pila) == &valor);

    /* Desapilo volumen y pruebo que todos tengan el mismo valor*/
    bool desapilado = true;
    for (int i = 1; i <= VOLUMEN; i++)
        desapilado &= pila_ver_tope(pila) == &valor && pila_desapilar(pila) == &valor;
    print_test("Desapilo volumen", desapilado == true && pila_esta_vacia(pila) == true);

    /* Apilo volumen de NULL, pruebo que no esta vacia, veo el tope, la desapilo y
    pruebo que luego esta vacia */
    for (int i = 0; i < VOLUMEN; i++)
        apilado &= pila_apilar(pila, NULL) == true && pila_ver_tope(pila) == NULL;
    print_test("Apilo volumen de NULL", apilado == true);
    print_test("Pila no esta vacia (es true)", !pila_esta_vacia(pila) == true);
    print_test("Ver tope (es NULL)", pila_ver_tope(pila) == NULL);
    for (int i = 0; i < VOLUMEN; i++)
        desapilado &= pila_ver_tope(pila) == NULL && pila_desapilar(pila) == NULL;
    print_test("Desapilar volumen de NULL", pila_esta_vacia(pila) == true);

    /* Destruyo la pila */
    pila_destruir(pila);
    printf("Destruyo la pila\n");
}

void pruebas_pila_estudiante() {
    prueba_pila_vacia();
    pruebas_unitarias();
    prueba_apilar_arrays();
    prueba_casos_null();
    pruebas_condiciones_borde();
    pruebas_volumen();
}

/*
 * Función main() que llama a la función de pruebas.
 */

#ifndef CORRECTOR  // Para que no dé conflicto con el main() del corrector.

int main(void) {
    pruebas_pila_estudiante();
    return failure_count() > 0;  // Indica si falló alguna prueba.
}

#endif
