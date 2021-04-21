#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "testing.h"

#include "lista.h"
#include "pila.h"

#define VOLUMEN 10000
#define LARGO_VECTOR 5

static void prueba_lista_vacia(void) {
    printf("INICIO DE PRUEBAS DE LISTA VACIA\n");

    /* Creo una lista */
    lista_t *lista = lista_crear();

    int valor0 = 3;

    /* Inicio Pruebas */

    /* Pruebo que la lista se crea vacia */
    print_test("La lista esta vacia (es true)", lista_esta_vacia(lista) == true);

    /* Inserto un elemento al principio para probar que la lista ya no esta vacia */
    print_test("Inserto un elemento...", lista_insertar_primero(lista, &valor0) == true);
    print_test("La lista esta vacia (es false)", lista_esta_vacia(lista) == false);
    /* Borro el elemento del principio para probar que la lista esta vacia nuevamente */
    print_test("Borro el elemento insertado...", lista_borrar_primero(lista) == &valor0);
    print_test("La lista esta nuevamente vacia (es true)", lista_esta_vacia(lista) == true);

    /* Destruyo la lista */
    lista_destruir(lista, NULL);
    print_test("Destruyo la lista", true);
}

static void pruebas_unitarias(void) {
    printf("INICIO PRUEBAS UNITARIAS\n");

    /* Creo una lista */
    lista_t *lista = lista_crear();

    /* Creo los valores a usar */
    int valor0 = 0;
    int valor1 = 16;
    int valor2 = 24;
    int valor3 = 32;
    int valor4 = 48;

    /* Inicio Pruebas */

    /* Pruebo que la lista se crea vacia */
    print_test("La lista esta vacia (es true)", lista_esta_vacia(lista) == true);
    print_test("El largo de la lista es 0", lista_largo(lista) == 0);

    /* Insertar un elemento
    1) Inserto un elemento desde el principio.
    2) Compruebo que sea el primero y el ultimo-
    3) Compruebo el largo de la lista.
    4) Borro un elemento desde el princio.
    5) Repito 1, 2, y 3 pero desde el ultimo.
    */

    print_test("Inserto un elemento desde el principio", lista_insertar_primero(lista, &valor0) == true);
    print_test("El elemento insertado es el primero y el ultimo", lista_ver_primero(lista) == &valor0 && lista_ver_ultimo(lista) == &valor0);
    print_test("El largo de la lista es 1", lista_largo(lista) == 1);
    print_test("Borro el elemento del principio...", lista_borrar_primero(lista) == &valor0);
    print_test("El largo de la lista es 0", lista_largo(lista) == 0);
    print_test("La lista esta vacia", lista_esta_vacia(lista) == true);
    print_test("Inserto un elemento desde el final", lista_insertar_ultimo(lista, &valor1) == true);
    print_test("El elemento insertado es el primero y el ultimo", lista_ver_primero(lista) == &valor1 && lista_ver_ultimo(lista) == &valor1);
    print_test("El largo de la lista es 1", lista_largo(lista) == 1);
    print_test("Borro el elemento del principio...", lista_borrar_primero(lista) == &valor1);
    print_test("El largo de la lista es 0", lista_largo(lista) == 0);
    print_test("La lista esta vacia", lista_esta_vacia(lista) == true);

    /* Insertar varios elementos desde el principio y luego borrar uno por uno
    1) Inserto un elemento desde el principio.
    2) Compruebo que el primero y el ultimo.
    3) Compruebo el largo de la lista.
    4) Repito 1, 2, y 3 varias veces.
    5) Borro uno por uno desde el principio.
    */

    /* Inserto valor0 desde el principio */ 
    print_test("Inserto valor0 desde el principio", lista_insertar_primero(lista, &valor0) == true);
    print_test("El elemento insertado es el primero y el ultimo", lista_ver_primero(lista) == &valor0 && lista_ver_ultimo(lista) == &valor0);
    print_test("El largo de la lista es 1", lista_largo(lista) == 1);
    /* Inserto valor1 desde el principio */ 
    print_test("Inserto valor1 desde el principio", lista_insertar_primero(lista, &valor1) == true);
    print_test("Valor1 es el primer elemento", lista_ver_primero(lista) == &valor1);
    print_test("Valor0 es el ultimo elemento", lista_ver_ultimo(lista) == &valor0);
    print_test("El largo de la lista es 2", lista_largo(lista) == 2);
    /* Inserto valor2 desde el principio */ 
    print_test("Inserto valor2 desde el principio", lista_insertar_primero(lista, &valor2) == true);
    print_test("Valor2 es el primer elemento", lista_ver_primero(lista) == &valor2);
    print_test("Valor0 es el ultimo elemento", lista_ver_ultimo(lista) == &valor0);
    print_test("El largo de la lista es 3", lista_largo(lista) == 3);
    /* Inserto valor3 desde el principio */ 
    print_test("Inserto valor3 desde el principio", lista_insertar_primero(lista, &valor3) == true);
    print_test("Valor3 es el primer elemento", lista_ver_primero(lista) == &valor3);
    print_test("Valor0 es el ultimo elemento", lista_ver_ultimo(lista) == &valor0);
    print_test("El largo de la lista es 4", lista_largo(lista) == 4);
    /* Inserto valor1 desde el principio */ 
    print_test("Inserto valor4 desde el principio", lista_insertar_primero(lista, &valor4) == true);
    print_test("Valor4 es el primer elemento", lista_ver_primero(lista) == &valor4);
    print_test("Valor0 es el ultimo elemento", lista_ver_ultimo(lista) == &valor0);
    print_test("El largo de la lista es 5", lista_largo(lista) == 5);

    /* Borro a los elementos uno por uno desde el principio */
    print_test("Borro un elemento desde el principio", lista_borrar_primero(lista) == &valor4);
    print_test("Valor3 es el primer elemento", lista_ver_primero(lista) == &valor3);
    print_test("Valor0 es el ultimo elemento", lista_ver_ultimo(lista) == &valor0);
    print_test("El largo de la lista es 4", lista_largo(lista) == 4);
    /* Borro un elemento desde el principio */
    print_test("Borro un elemento desde el principio", lista_borrar_primero(lista) == &valor3);
    print_test("Valor2 es el primer elemento", lista_ver_primero(lista) == &valor2);
    print_test("Valor0 es el ultimo elemento", lista_ver_ultimo(lista) == &valor0);
    print_test("El largo de la lista es 3", lista_largo(lista) == 3);
    /* Borro un elemento desde el principio */
    print_test("Borro un elemento desde el principio", lista_borrar_primero(lista) == &valor2);
    print_test("Valor1 es el primer elemento", lista_ver_primero(lista) == &valor1);
    print_test("Valor0 es el ultimo elemento", lista_ver_ultimo(lista) == &valor0);
    print_test("El largo de la lista es 2", lista_largo(lista) == 2);
    /* Borro un elemento desde el principio */
    print_test("Borro un elemento desde el principio", lista_borrar_primero(lista) == &valor1);
    print_test("Valor0 es el primero y el ultimo", lista_ver_primero(lista) == &valor0 && lista_ver_ultimo(lista) == &valor0);
    print_test("El largo de la lista es 1", lista_largo(lista) == 1);
    /* Borro un elemento desde el principio */
    print_test("Borro un elemento desde el principio", lista_borrar_primero(lista) == &valor0);
    print_test("La lista esta vacia", lista_esta_vacia(lista) == true);
    print_test("El largo de la lista es 0", lista_largo(lista) == 0);

    /* Insertar varios elementos desde el final y luego borrar uno por uno
    1) Inserto un elemento desde el final.
    2) Compruebo que el primero y el ultimo.
    3) Compruebo el largo de la lista.
    4) Repito 1, 2, y 3 varias veces.
    5) Borro uno por uno desde el final.
    */

    /* Inserto valor0 desde el final */ 
    print_test("Inserto valor0 desde el final", lista_insertar_ultimo(lista, &valor0) == true);
    print_test("El elemento insertado es el primero y el ultimo", lista_ver_primero(lista) == &valor0 && lista_ver_ultimo(lista) == &valor0);
    print_test("El largo de la lista es 1", lista_largo(lista) == 1);
    /* Inserto valor1 desde el final */ 
    print_test("Inserto valor1 desde el final", lista_insertar_ultimo(lista, &valor1) == true);
    print_test("Valor1 es el ultimo elemento", lista_ver_ultimo(lista) == &valor1);
    print_test("Valor0 es el primero", lista_ver_primero(lista) == &valor0);
    print_test("El largo de la lista es 2", lista_largo(lista) == 2);
    /* Inserto valor2 desde el final */ 
    print_test("Inserto valor2 desde el final", lista_insertar_ultimo(lista, &valor2) == true);
    print_test("Valor2 es el ultimo elemento", lista_ver_ultimo(lista) == &valor2);
    print_test("Valor0 es el primero", lista_ver_primero(lista) == &valor0);
    print_test("El largo de la lista es 3", lista_largo(lista) == 3);
    /* Inserto valor3 desde el final */ 
    print_test("Inserto valor3 desde el final", lista_insertar_ultimo(lista, &valor3) == true);
    print_test("Valor3 es el ultimo elemento", lista_ver_ultimo(lista) == &valor3);
    print_test("Valor0 es el primero", lista_ver_primero(lista) == &valor0);
    print_test("El largo de la lista es 4", lista_largo(lista) == 4);
    /* Inserto valor1 desde el final */ 
    print_test("Inserto valor4 desde el final", lista_insertar_ultimo(lista, &valor4) == true);
    print_test("Valor4 es el ultimo elemento", lista_ver_ultimo(lista) == &valor4);
    print_test("Valor0 es el primero", lista_ver_primero(lista) == &valor0);
    print_test("El largo de la lista es 5", lista_largo(lista) == 5);

    /* Borro a los elementos uno por uno desde el principio */
    print_test("Borro un elemento desde el principio", lista_borrar_primero(lista) == &valor0);
    print_test("Valor4 es el ultimo elemento", lista_ver_ultimo(lista) == &valor4);
    print_test("Valor1 es el primero", lista_ver_primero(lista) == &valor1);
    print_test("El largo de la lista es 4", lista_largo(lista) == 4);
    /* Borro un elemento desde el principio */
    print_test("Borro un elemento desde el principio", lista_borrar_primero(lista) == &valor1);
    print_test("Valor4 es el ultimo elemento", lista_ver_ultimo(lista) == &valor4);
    print_test("Valor2 es el primero", lista_ver_primero(lista) == &valor2);
    print_test("El largo de la lista es 3", lista_largo(lista) == 3);
    /* Borro un elemento desde el principio */
    print_test("Borro un elemento desde el principio", lista_borrar_primero(lista) == &valor2);
    print_test("Valor4 es el ultimo elemento", lista_ver_ultimo(lista) == &valor4);
    print_test("Valor3 es el primero", lista_ver_primero(lista) == &valor3);
    print_test("El largo de la lista es 2", lista_largo(lista) == 2);
    /* Borro un elemento desde el principio */
    print_test("Borro un elemento desde el principio", lista_borrar_primero(lista) == &valor3);
    print_test("Valor4 es el primero y el ultimo", lista_ver_primero(lista) == &valor4 && lista_ver_ultimo(lista) == &valor4);
    print_test("El largo de la lista es 1", lista_largo(lista) == 1);
    /* Borro un elemento desde el principio */
    print_test("Borro un elemento desde el principio", lista_borrar_primero(lista) == &valor4);
    print_test("La lista esta vacia", lista_esta_vacia(lista) == true);
    print_test("El largo de la lista es 0", lista_largo(lista) == 0);

    lista_destruir(lista, NULL);
    print_test("Destruyo la lista", true);
    
}

static void prueba_insertar_arrays(void) {
    printf("INICIO PRUEBAS DE ARRAYS\n");

    /* Creo una lista */
    lista_t *lista = lista_crear();

    /* Creo un vector de caracteres (string) */
    char vec[] = "prueba de que la lista inserta correctamente un string";
    size_t largo = strlen(vec);

    /* Inicio Pruebas */

    /* La lista se crea vacia */
    print_test("La lista no esta vacia (es false)", !lista_esta_vacia(lista) == false);

    /* Inserto desde el principio los elementos del array */
    bool insertado = true;
    for (int i = 0; vec[i] != '\0'; insertado &= lista_insertar_primero(lista, &vec[i++]));
    print_test("Cargo el string en la lista", insertado == true && !lista_esta_vacia(lista) == true);
    /* Pruebo que el primer elemento agregado no es el caracter nulo ('\0') */
    print_test("El primer y ultimo elemento agregado no es \'\\0\'", *(char *)lista_ver_ultimo(lista) != '\0' && *(char *)lista_ver_primero(lista) != '\0');
    /* Pruebo que el primer elemento agregado es el primer elemento del array */
    print_test("El arreglo quedo al reves", lista_ver_ultimo(lista) == &vec[0] && lista_ver_primero(lista) == &vec[lista_largo(lista)-1]);
    /* Borro el array entero y pruebo que cada valor se haya insertado en orden */
    bool borrado = true;
    for (size_t i = 0; i < largo; i++) 
        borrado &= lista_borrar_primero(lista) == &vec[largo-1-i];
    print_test("Borro el string", borrado == true && lista_esta_vacia(lista) == true);

    /* Inserto desde el final los elementos del array */
    for (int i = 0; vec[i] != '\0'; insertado &= lista_insertar_ultimo(lista, &vec[i++]));
    print_test("Cargo el string en la lista", insertado == true && !lista_esta_vacia(lista) == true);
    /* Pruebo que el primer elemento agregado no es el caracter nulo ('\0') */
    print_test("El primer y ultimo elemento agregado no es \'\\0\'", *(char *)lista_ver_ultimo(lista) != '\0' && *(char *)lista_ver_primero(lista) != '\0');
    /* Pruebo que el primer elemento agregado es el primer elemento del array */
    print_test("El arreglo quedo en orden", lista_ver_primero(lista) == &vec[0] && lista_ver_ultimo(lista) == &vec[lista_largo(lista)-1]);
    /* Borro el array entero y pruebo que cada valor se haya insertado en orden */
    for (size_t i = 0; i < largo; i++) 
        borrado &= lista_borrar_primero(lista) == &vec[i];
    print_test("Borro el string", borrado == true && lista_esta_vacia(lista) == true);

    /* Destruyo la lista */
    lista_destruir(lista, NULL);
    print_test("Destruyo la lista", true);
}

static void prueba_casos_null(void) {
    printf("INICIO PRUEBAS DE CASOS DE NULL\n");

    /* Creo una lista */
    lista_t *lista = lista_crear();

    /* Inicio Pruebas */

    /* La lista se crea vacia */
    print_test("La lista esta vacia (es true)", lista_esta_vacia(lista) == true);

    /* Pruebo que no puedo borrar el primer elemento de una lista vacia */
    print_test("Borro el primero en lista vacia (es NULL)", lista_borrar_primero(lista) == NULL);

    /* Pruebo que no puedo ver el primero de una lista vacia */
    print_test("Veo el primero lista vacia (es NULL)", lista_ver_primero(lista) == NULL);

    /* Inserto NULL desde el principio */
    print_test("Inserto NULL al principio", lista_insertar_primero(lista, NULL) == true);
    print_test("NULL es el primero y el ultimo", lista_ver_primero(lista) == NULL && lista_ver_ultimo(lista) == NULL);
    print_test("La lista no esta vacia (es true)", !lista_esta_vacia(lista) == true);
    print_test("Borro el primero lista (es NULL)", lista_borrar_primero(lista) == NULL);
    print_test("La lista esta vacia", lista_esta_vacia(lista) == true);

    /* Inserto NULL desde el final */
    print_test("Inserto NULL al final", lista_insertar_ultimo(lista, NULL) == true);
    print_test("NULL es el primero y el ultimo", lista_ver_primero(lista) == NULL && lista_ver_ultimo(lista) == NULL);
    print_test("La lista no esta vacia (es true)", !lista_esta_vacia(lista) == true);
    print_test("Borro el primero lista (es NULL)", lista_borrar_primero(lista) == NULL);
    print_test("La lista esta vacia", lista_esta_vacia(lista) == true);

    /* Destruyo la lista */
    lista_destruir(lista, NULL);
    print_test("Destruyo la lista", true);

    lista_t *lista1 = lista_crear();

    print_test("Agrego un NULL", lista_insertar_primero(lista1, NULL) == true);
    lista_destruir(lista1, NULL);
    print_test("Destruyo la lista con un dato NULL", true);
}

size_t avanzar_hasta(lista_iter_t *iter, size_t pos) {
    size_t i = 0;
    while (i++ < pos) 
        lista_iter_avanzar(iter);
    
    return i-1;
}

static void pruebas_iterador_externo(void) {
    printf("INICIO PRUEBAS CON ITERADOR EXTERNO\n");

    /* Creo una lista */
    lista_t *lista = lista_crear();

    /* Creo un iterador */
    lista_iter_t *iter = lista_iter_crear(lista);

    /* Creo los valores a usar */
    int vec[LARGO_VECTOR] = {12, 45, 7666, 2323534, 3};

    int valor0 = 2;
    int valor1 = 8;

    /* Inicio pruebas */

    /* Pruebo que la lista esta vacia */
    print_test("La lista esta vacia", lista_esta_vacia(lista));
    /* Pruebo que los iteradores estan al principio de la lista que itera */
    print_test("El iterador esta en el principio de la lista", lista_iter_ver_actual(iter) == lista_ver_primero(lista));
    /* Pruebo que los iteradores estan al final de la lista que itera */
    print_test("El iterador esta en el final", lista_iter_ver_actual(iter) == lista_ver_ultimo(lista) && lista_iter_al_final(iter));
    
    /* Pruebas de insersion:
    1) Inserto algunos elementos desde el principio de la lista
    2) Inserto en el medio.
    3) Inserto al final.
    */

    /* Inserto elementos */
    /* Inserto valor0 */
    print_test("Inserto vec[0]", lista_iter_insertar(iter, &vec[0]) == true);
    print_test("vec[0] es el primer elemento de la lista", lista_ver_primero(lista) == &vec[0]);
    print_test("El iterador apunta a vec[0]", lista_iter_ver_actual(iter) == &vec[0]);
    /* Inserto vec[1] */
    print_test("Inserto vec[1]", lista_iter_insertar(iter, &vec[1]) == true);
    print_test("vec[1] es el primer elemento de la lista", lista_ver_primero(lista) == &vec[1]);
    print_test("El iterador apunta a vec[1]", lista_iter_ver_actual(iter) == &vec[1]);
    /* Inserto vec[2] */
    print_test("Inserto vec[2]", lista_iter_insertar(iter, &vec[2]) == true);
    print_test("vec[2] es el primer elemento de la lista", lista_ver_primero(lista) == &vec[2]);
    print_test("El iterador apunta a vec[2]", lista_iter_ver_actual(iter) == &vec[2]);
    /* Inserto vec[3] */
    print_test("Inserto vec[3]", lista_iter_insertar(iter, &vec[3]) == true);
    print_test("vec[3] es el primer elemento de la lista", lista_ver_primero(lista) == &vec[3]);
    print_test("El iterador apunta a vec[3]", lista_iter_ver_actual(iter) == &vec[3]);
    /* Inserto vec[4] */
    print_test("Inserto vec[4]", lista_iter_insertar(iter, &vec[4]) == true);
    print_test("vec[4] es el primer elemento de la lista", lista_ver_primero(lista) == &vec[4]);
    print_test("El iterador apunta a vec[4]", lista_iter_ver_actual(iter) == &vec[4]);
    /* Compruebo el largo de la lista */
    print_test("El largo de la lista es 5", lista_largo(lista) == 5);

    /* Itero por la lista comprobando que los elementos esten en orden */
    size_t i = LARGO_VECTOR;
    while (!lista_iter_al_final(iter)) {
        bool ingreso_ordenado = true;
        ingreso_ordenado &= lista_iter_ver_actual(iter) == &vec[i--];
        print_test("Avanzo el iterador0", lista_iter_avanzar(iter) == true);
    }
    print_test("El iterador0 esta al final de la lista", lista_iter_al_final(iter) == true && lista_iter_ver_actual(iter) == NULL);

    /* Inserto un elemento desde el final para probar que se inserto efectivamente en el final */
    print_test("Inserto un elemento en el final y efectivamente esta en el ultimo lugar", lista_iter_insertar(iter, &valor0) == true && lista_iter_ver_actual(iter) == &valor0 && lista_ver_ultimo(lista) == &valor0);

    /* Destruyo el iterador */
    lista_iter_destruir(iter);
    print_test("Destruyo el iterador", true);

    /* Creo otro iterador para avanzar hasta el medio e insertar un elemento desde ahi */
    lista_iter_t *iter1 = lista_iter_crear(lista);

    print_test("Elimino el primer elemento de la lista", lista_iter_ver_actual(iter1) == lista_ver_primero(lista) && lista_ver_primero(lista) == lista_iter_borrar(iter1));
    print_test("El iterador apunta al nuevo primero de la lista", lista_iter_ver_actual(iter1) == lista_ver_primero(lista));

    /* Pruebo que la lista no esta vacia */
    print_test("La lista no esta vacia", !lista_esta_vacia(lista) == true);
    /* Pruebo que los iteradores estan al principio de la lista que itera */
    print_test("El iterador esta en el principio de la lista", lista_iter_ver_actual(iter1) == lista_ver_primero(lista));
    /* Pruebo que los iteradores estan al final de la lista que itera */
    print_test("El iterador no esta en el final", lista_iter_ver_actual(iter1) != lista_ver_ultimo(lista) && !lista_iter_al_final(iter1));

    size_t indice_alcanzado = avanzar_hasta(iter1, lista_largo(lista) / 2);
    print_test("Avanzo el iterador hasta la mitad de la lista", indice_alcanzado == lista_largo(lista) / 2);
    print_test("Inserto un elemento en el medio de la lista", lista_iter_insertar(iter1, &valor1));

    /* Destruyo el iterador */
    lista_iter_destruir(iter1);
    print_test("Destruyo el iterador", true);

    /* Creo otro iterador para avanzar hasta la posicion llegada anteriormente para confirmar que se inserto correctamente en el medio */
    lista_iter_t *iter2 = lista_iter_crear(lista);

    /* Pruebo que se agrega un elemento en el medio, y luego pruebo que si borro el elemento del medio, se borra correctamente */
    size_t nuevo_indice_alcanzado = avanzar_hasta(iter2, indice_alcanzado);
    print_test("Avanzo el iterador hasta la mitad de la lista", indice_alcanzado == nuevo_indice_alcanzado);
    print_test("El elemento insertado anteriormente se inserto efectivamente en el medio", lista_iter_ver_actual(iter2) == &valor1);
    print_test("El largo de la lista es 6", lista_largo(lista) == 6);
    void *elemento_del_medio = lista_iter_borrar(iter2);
    print_test("Borro el elemento del medio", lista_iter_ver_actual(iter2) != elemento_del_medio);
    print_test("El largo de la lista es 5", lista_largo(lista) == 5);

    /* Avanzo hasta el ultimo elemento para borrarlo y comprobar que hay un nuevo ultimo */
    while(lista_iter_ver_actual(iter2) != lista_ver_ultimo(lista))
        lista_iter_avanzar(iter2);
    
    print_test("El iterador esta en el ultimo elemento de la lista", lista_iter_ver_actual(iter2) == lista_ver_ultimo(lista));
    print_test("Elimino el ultimo elemento de la lista", lista_ver_ultimo(lista) == lista_iter_borrar(iter2));
    print_test("Hay 4 elementos en la lista", lista_largo(lista) == 4);
    print_test("El iterador ahora apunta al final de la lista y el ultimo valor de la lista cambio", lista_iter_al_final(iter2) == true && lista_ver_ultimo(lista) != &valor0);
    print_test("Valor0 ya no es el ultimo elemento de la lista", lista_ver_ultimo(lista) != &valor0);

    /* Destruyo el iterador */
    lista_iter_destruir(iter2);
    print_test("Destruyo el iterador2", true);

    /* Creo un iterador para probar que el elemento del medio ya no esta en la lista */
    lista_iter_t *iter3 = lista_iter_crear(lista);
    print_test("Creo el iterador3", true);

    /* Avanzo hasta el final comprobando que no este el elemento eliminado */
    bool eliminado = true;
    while(lista_iter_ver_actual(iter3) != lista_ver_ultimo(lista)) {
        eliminado &= lista_iter_ver_actual(iter3) != elemento_del_medio;
        lista_iter_avanzar(iter3);
    }
    print_test("El elemento del medio ya no forma parte de la lista", eliminado);

    /* Destruyo el iterador */
    lista_iter_destruir(iter3);
    print_test("Destruyo el iterador3", true);

    /* Destruyo la lista */
    lista_destruir(lista, NULL);
    print_test("Destruyo la lista", true);
}

/* Creo una funcion auxiliar para que funcione el codigo */
void _pila_destruir(void *pila) {
    pila_destruir((pila_t *) pila);
}

bool visitar_suma_pares(void *dato, void *extra) {
    if (*(int *) dato % 2 == 0) 
        *(int *) extra += *(int *) dato;
    return true;
}

bool visitar_sumar_todos(void *dato, void *extra) {
    *(int *) extra += *(int *) dato;
    return true;
}

static void pruebas_iterador_interno(void) {
    /* Creo una lista */
    lista_t *lista = lista_crear();

    /* Creo los datos a usar */
    int vec[LARGO_VECTOR] = {43, 2, 644, 876, 0};

    bool insertado = true;
    for (size_t i = 0; i < LARGO_VECTOR; i++) 
        insertado &= lista_insertar_primero(lista, &vec[i]);
    
    print_test("Creo una lista", true);
    print_test("Inserto varios elementos", insertado == true);

    int suma = 0;
    lista_iterar(lista, visitar_sumar_todos, &suma);
    print_test("Itero con la funcion visitar que suma los numeros", true);
    print_test("Sumo todos los elementos de la lista", suma == (vec[0] + vec[1] + vec[2] + vec[3] + vec[4]));

    int suma_pares = 0;
    lista_iterar(lista, visitar_suma_pares, &suma_pares);
    print_test("Itero con la funcion visitar que suma los numeros pares", true);
    print_test("Sumo todos los elementos de la lista", suma_pares == (vec[1] + vec[2] + vec[3] + vec[4]));

    int extra = 0;
    lista_iterar(lista, NULL, &extra);
    print_test("Itero con la funcion visitar en NULL (no deberia pasar nada)", true);
    print_test("No pasa nada", extra == 0);

    /* Destruyo la lista */
    lista_destruir(lista, NULL);
    print_test("Destruyo la lista", true);
}

static void pruebas_condiciones_borde(void) {
    printf("INICIO PRUEBAS DE CASOS BORDE\n");

    /* Creo una lista */
    lista_t *lista = lista_crear();

    /* Creo los datos a usar */
    int vec[LARGO_VECTOR] = {43, 2, 644, 876, 0};

    /* Pruebo condiciones borde en lista vacia */
    print_test("La lista esta vacia", lista_esta_vacia(lista) && lista_largo(lista) == 0);
    print_test("No puedo eliminar el primer elemento de una lista vacia", lista_borrar_primero(lista) == NULL);
    print_test("La lista sigue vacia", lista_esta_vacia(lista) && lista_largo(lista) == 0);
    int extra = 0;
    lista_iterar(lista, visitar_suma_pares, &extra);
    print_test("Iterar una lista vacia no hace nada", extra == 0);

    /* Pruebo condiciones borde al insertar un elemento desde el principio de la lista */
    print_test("Inserto un elemeto con la lista (al principio)", lista_insertar_primero(lista, &vec[0]) == true);
    print_test("La lista tiene un elemento", !lista_esta_vacia(lista) && lista_largo(lista) == 1);
    print_test("El primer elemento de la lista es vec[0]", lista_ver_primero(lista) == &vec[0]);
    print_test("El ultimo elemento de la lista es vec[0]", lista_ver_ultimo(lista) == &vec[0]);
    print_test("Borro el primer elemento", lista_borrar_primero(lista) == &vec[0]);
    print_test("No puedo borrar otro elemento", lista_borrar_primero(lista) == NULL);
    /* Compruebo las condiciones borde en la lista vacia nuevamente */
    print_test("La lista esta vacia", lista_esta_vacia(lista) && lista_largo(lista) == 0);
    print_test("No puedo eliminar el primer elemento de una lista vacia", lista_borrar_primero(lista) == NULL);
    print_test("La lista sigue vacia", lista_esta_vacia(lista) && lista_largo(lista) == 0);
    /* Pruebo condiciones borde al insertar un elemento desde el principio de la lista */
    print_test("Inserto un elemeto con la lista (al final)", lista_insertar_ultimo(lista, &vec[0]) == true);
    print_test("La lista tiene un elemento", !lista_esta_vacia(lista) && lista_largo(lista) == 1);
    print_test("El primer elemento de la lista es vec[0]", lista_ver_primero(lista) == &vec[0]);
    print_test("El ultimo elemento de la lista es vec[0]", lista_ver_ultimo(lista) == &vec[0]);
    print_test("Borro el primer elemento", lista_borrar_primero(lista) == &vec[0]);
    print_test("No puedo borrar otro elemento", lista_borrar_primero(lista) == NULL);
    /* Compruebo las condiciones borde en la lista vacia nuevamente */
    print_test("La lista esta vacia", lista_esta_vacia(lista) && lista_largo(lista) == 0);
    print_test("No puedo eliminar el primer elemento de una lista vacia", lista_borrar_primero(lista) == NULL);
    print_test("La lista sigue vacia", lista_esta_vacia(lista) && lista_largo(lista) == 0);

    /* Inserto elementos intercalando el principio y el final */
    print_test("Inserto vec[0] con la lista (al principio)", lista_insertar_primero(lista, &vec[0]) == true);
    print_test("Vec[0] es el primer y ultimo elemento", lista_ver_primero(lista) == &vec[0] && lista_ver_ultimo(lista) == &vec[0]);
    print_test("Inserto vec[1] con la lista (al final)", lista_insertar_ultimo(lista, &vec[1]) == true);
    print_test("Vec[1] no es el primer y si el ultimo elemento", lista_ver_primero(lista) != &vec[1] && lista_ver_ultimo(lista) == &vec[1]);
    print_test("Inserto vec[2] con la lista (al principio)", lista_insertar_primero(lista, &vec[2]) == true);
    print_test("Vec[2] es el primer y no el ultimo elemento", lista_ver_primero(lista) == &vec[2] && lista_ver_ultimo(lista) != &vec[2]);
    print_test("Inserto vec[3] con la lista (al final)", lista_insertar_ultimo(lista, &vec[3]) == true);
    print_test("Vec[3] no es el primer y si el ultimo elemento", lista_ver_primero(lista) != &vec[3] && lista_ver_ultimo(lista) == &vec[3]);
    print_test("Inserto vec[4] con la lista (al principio)", lista_insertar_primero(lista, &vec[4]) == true);
    print_test("Vec[4] es el primer y no el ultimo elemento", lista_ver_primero(lista) == &vec[4] && lista_ver_ultimo(lista) != &vec[4]);

    /* Destruyo la lista */
    lista_destruir(lista, NULL);
    print_test("Destruyo la lista con elementos", true);

    /* Creo otra lista */
    lista_t *lista1 = lista_crear();

    /* Creo un iterador externo */
    lista_iter_t *iter = lista_iter_crear(lista1);

    /* Pruebo condiciones borde de un iterador sobre una lista vacia */
    print_test("El iterador apunta al primero de la lista", lista_iter_ver_actual(iter) == lista_ver_primero(lista1));
    print_test("El iterador apunta al ultimo de la lista", lista_iter_ver_actual(iter) == lista_ver_ultimo(lista1));
    print_test("El iterador esta al final de la lista", lista_iter_al_final(iter) == true);
    print_test("No puedo avanzar sobre una lista vacia", lista_iter_avanzar(iter) == false);
    print_test("No puedo borrar un elemento de una lista vacia", lista_iter_borrar(iter) == NULL);
    /* Pruebo insertar un elemento en una lista vacia con iterador */
    print_test("Inserto un primer elemento en una lista vacia", lista_iter_insertar(iter, &vec[0]) == true);
    print_test("La lista tiene un elemento", !lista_esta_vacia(lista1) && lista_largo(lista1) == 1);
    print_test("El primer elemento de la lista es vec[0]", lista_ver_primero(lista1) == &vec[0]);
    print_test("El ultimo elemento de la lista es vec[0]", lista_ver_ultimo(lista1) == &vec[0]);
    print_test("El iterador ya no esta al final", lista_iter_al_final(iter) == false);
    /* Inserto un elemento mas desde el principio de la lista para probar que cambia el final */
    print_test("Inserto un elemento desde el principio de la lista", lista_iter_insertar(iter, &vec[1]));
    print_test("La lista tiene 2 elementos", lista_largo(lista1) == 2);
    print_test("vec[1] esta en el principio de la lista y no al final", lista_ver_primero(lista1) == &vec[1] && lista_ver_ultimo(lista1) != &vec[1]);
    print_test("vec[0] es el ultimo", lista_ver_ultimo(lista1) == &vec[0]);
    /* Inserto otro elemento al principio y luego lo elimino */
    print_test("Inserto un elemento desde el principio de la lista", lista_iter_insertar(iter, &vec[2]));
    print_test("La lista tiene 3 elementos", lista_largo(lista1) == 3);
    print_test("vec[2] esta en el principio de la lista y no al final", lista_ver_primero(lista1) == &vec[2] && lista_ver_primero(lista1) != &vec[1] && lista_ver_ultimo(lista1) != &vec[2]);
    print_test("vec[0] es el ultimo", lista_ver_ultimo(lista1) == &vec[0]);
    print_test("Elimino vec[2]", lista_iter_borrar(iter) == &vec[2]);
    print_test("La lista tiene 2 elementos", lista_largo(lista1) == 2);
    print_test("vec[1] esta en el principio de la lista y no al final", lista_ver_primero(lista1) == &vec[1] && lista_ver_ultimo(lista1) != &vec[1]);
    print_test("vec[0] es el ultimo", lista_ver_ultimo(lista1) == &vec[0]);
    /* Avanzo al final e inserto un elemento desde el final */
    while (!lista_iter_al_final(iter)) lista_iter_avanzar(iter);
    print_test("Estoy viendo el final de la lista", lista_iter_ver_actual(iter) == NULL && lista_iter_al_final(iter) == true);
    print_test("Inserto un elemento desde el final de la lista", lista_iter_insertar(iter, &vec[2]));
    print_test("La lista tiene 3 elementos", lista_largo(lista1) == 3);
    print_test("vec[2] esta en el final de la lista y no al principio", lista_ver_primero(lista1) != &vec[2] && lista_ver_ultimo(lista1) == &vec[2]);
    print_test("vec[0] no es el ultimo", lista_ver_ultimo(lista1) != &vec[0]);
    print_test("Elimino vec[2]", lista_iter_borrar(iter) == &vec[2]);
    print_test("La lista tiene 2 elementos", lista_largo(lista1) == 2);
    print_test("vec[1] esta en el principio de la lista y no al final", lista_ver_primero(lista1) == &vec[1] && lista_ver_ultimo(lista1) != &vec[1]);
    print_test("vec[0] es el ultimo", lista_ver_ultimo(lista1) == &vec[0]);

    /* Borro todos los elementos */
    while (lista_borrar_primero(lista1) != NULL);
    /* Pruebo condiciones borde de un iterador sobre una lista vacia */
    print_test("El iterador apunta al primero de la lista", lista_iter_ver_actual(iter) == lista_ver_primero(lista1));
    print_test("El iterador apunta al ultimo de la lista", lista_iter_ver_actual(iter) == lista_ver_ultimo(lista1));
    print_test("El iterador esta al final de la lista", lista_iter_al_final(iter) == true);
    print_test("La lista esta vacia", lista_esta_vacia(lista1) == true);

    /* Destruyo el iterador */
    lista_iter_destruir(iter);
    print_test("Destruyo el iterador", true);

    /* Creo las pilas */
    pila_t *pila0 = pila_crear();
    pila_t *pila1 = pila_crear();
    pila_t *pila2 = pila_crear();

    print_test("Inserto pila0", lista_insertar_primero(lista1, pila0) == true);
    print_test("Inserto pila1", lista_insertar_primero(lista1, pila1) == true);
    print_test("Inserto pila2", lista_insertar_primero(lista1, pila2) == true);

    /* Destruyo la lista */
    lista_destruir(lista1, _pila_destruir);
    print_test("Destruyo la lista", true);
}

static void pruebas_volumen(void) {
    printf("INICIO PRUEBAS DE VOLUMEN\n");

    /* Creo una lista */
    lista_t *lista = lista_crear();

    int valor = 32;

    /* Inserto un volumen de elementos desde el principio y pruebo que la lista
    no esta vacia, y que su primero es el ultimo valor que tomo "i" */
    bool insertado = true;
    for (int i = 0; i < VOLUMEN; i++)
        insertado &= lista_insertar_primero(lista, &valor) == true && lista_ver_primero(lista) == &valor;
    print_test("Inserto un volumen de elementos", insertado == true && !lista_esta_vacia(lista) == true);
    print_test("El primero es el ultimo insertado", lista_ver_primero(lista) == &valor);
    print_test("El ultimo es el primer insertado", lista_ver_primero(lista) == &valor);

    /* Borro el volumen de elementos y pruebo que todos tengan el mismo valor */
    bool borrado = true;
    for (int i = 1; i <= VOLUMEN; i++)
        borrado &= lista_borrar_primero(lista) == &valor;
    print_test("Borro el volumen de elementos", borrado == true && lista_esta_vacia(lista) == true);

    /* Inserto un volumen de NULL desde el principio, pruebo que no esta vacia,
    veo el primero, la desencolo y pruebo que luego esta vacia */
    insertado = true;
    for (int i = 0; i < VOLUMEN; i++)
        insertado &= lista_insertar_primero(lista, NULL) == true && lista_ver_primero(lista) == NULL;
    print_test("Inserto un volumen de NULL", insertado == true);
    print_test("La lista no esta vacia (es true)", !lista_esta_vacia(lista) == true);
    print_test("Veo el primero (es NULL)", lista_ver_primero(lista) == NULL);
    print_test("Veo el ultimo (es NULL)", lista_ver_ultimo(lista) == NULL);
    borrado = true;
    for (int i = 0; i < VOLUMEN; i++)
        borrado &= lista_borrar_primero(lista) == NULL;
    print_test("Borro volumen de NULL", lista_esta_vacia(lista) == true);

    /* Inserto un volumen de elementos desde el final y pruebo que la lista
    no esta vacia, y que su primero es el ultimo valor que tomo "i" */
    insertado = true;
    for (int i = 0; i < VOLUMEN; i++)
        insertado &= lista_insertar_ultimo(lista, &valor) == true && lista_ver_ultimo(lista) == &valor;
    print_test("Inserto un volumen de elementos", insertado == true && !lista_esta_vacia(lista) == true);
    print_test("El ultimo elemento es el ultimo insertado", lista_ver_ultimo(lista) == &valor);
    print_test("El primer elemento es el primer insertado", lista_ver_ultimo(lista) == &valor);

    /* Borro el volumen de elementos y pruebo que todos tengan el mismo valor */
    borrado = true;
    for (int i = 1; i <= VOLUMEN; i++)
        borrado &= lista_borrar_primero(lista) == &valor;
    print_test("Borro el volumen de elementos", borrado == true && lista_esta_vacia(lista) == true);

    /* Inserto un volumen de NULL desde el final, pruebo que no esta vacia,
    veo el primero, la desencolo y pruebo que luego esta vacia */
    for (int i = 0; i < VOLUMEN; i++)
        insertado &= lista_insertar_ultimo(lista, NULL) == true && lista_ver_ultimo(lista) == NULL;
    print_test("Inserto un volumen de NULL", insertado == true);
    print_test("La lista no esta vacia (es true)", !lista_esta_vacia(lista) == true);
    print_test("Veo el primero (es NULL)", lista_ver_primero(lista) == NULL);
    print_test("Veo el ultimo (es NULL)", lista_ver_ultimo(lista) == NULL);
    for (int i = 0; i < VOLUMEN; i++)
        borrado &= lista_borrar_primero(lista) == NULL;
    print_test("Borro volumen de NULL", lista_esta_vacia(lista) == true);

    /* Destruyo la lista */
    lista_destruir(lista, NULL);
    print_test("Destruyo la lista", true);
}


void pruebas_lista_estudiante() {
    prueba_lista_vacia();
    pruebas_unitarias();
    prueba_insertar_arrays();
    prueba_casos_null();
    pruebas_iterador_externo();
    pruebas_iterador_interno();
    pruebas_condiciones_borde();
    pruebas_volumen();
}

#ifndef CORRECTOR  // Para que no dé conflicto con el main() del corrector.

int main(void) {
    pruebas_lista_estudiante();
    return failure_count() > 0;  // Indica si falló alguna prueba.
}

#endif
