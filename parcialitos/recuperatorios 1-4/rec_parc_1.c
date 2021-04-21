/*
Escribir en C una función que dada una cola y una función cuya firma es 
void* transformar(void*), devuelva una nueva cola cuyos elementos sean los 
resultantes de aplicarle la función transformar a cada elemento de la cola original.
Los elementos en la nueva cola deben tener el orden que tenían en la cola 
original, y la cola original debe quedar en el mismo estado al inicial 
(si bien puede ser modificada durante la ejecución de la función). Indicar y 
justificar la complejidad de la función implementada. La firma de la función 
debe ser cola_t* transformar_cola(cola_t* original, void*(*transformar)(void*)).
Por ejemplo, para la cola [ 1, 2, 3, 6, 2 ] (primero es el número 1), y la 
función sumar_uno (que devuelve la suma entre el número 1 y el número recibido), 
la cola resultante debe ser [ 2, 3, 4, 7, 3 ] (el primero es el número 2).
*/

cola_t* transformar_cola(cola_t* original, void*(*transformar)(void*))
{
    cola_t *aux = cola_crear();

    if (aux == NULL)
    {
        return NULL;
    }

    cola_t *transformada = cola_crear();

    if (transformada == NULL)
    {
        cola_destruir(aux); // O(1)
        return NULL;
    } // O(n)

    while (!cola_esta_vacia(original))
    {
        cola_encolar(aux, cola_desencolar(original));
    } // O(n)

    while (!cola_esta_vacia(aux))
    {
        void *dato = cola_desencolar(aux);
        cola_encolar(original, dato); // O(1)
        cola_encolar(transformada, transformar(dato)); // O(1)
    } // O(n)

    cola_destruir(aux);

    return transformada;
}

/* Complejidad ejercicio 1

Desencolar la cola original en la cola auxiliar para luego poder encolar los
datos transformados en la cola de transformados y además reencolar los datos
originales en la cola original cuesta O(n) siendo n la cantidad de elementos
de la cola original.
Luego desencolar la cola auxiliar para enco lar el dato original en la cola
original y el dato transformado en la cola de transformados es O(n) siendo n
la cantidad de elementos de la cola auxiliar, que coincide con la cantidad de
elementos de la cola original (ya que son los mismos).

Entonces la complejidad es O(n) + O(n) = O(2n) = O(n) siendo n la cantidad de
elementos en la cola original.

*/

/*****************************************************************************/

/* Ejercicio 2
Implementar una primitiva void cola_invertir(cola_t* cola) para una 
Cola Dinámica/Circular, que invierta el orden de sus elementos, sin utilizar 
estructuras auxiliares (i.e.en espacio constante). Indicar y justificar la 
complejidad de la primitiva. La estructura interna de la cola es la siguiente:
*/
typedef struct cola 
{
    void** datos;
    size_t capacidad, cantidad;
    size_t inicio, fin;
} cola_t;

void swap(void *a, void *b)
{
    void *temp = a; // O(1)
    *a = *b; // O(1)
    *b = temp; // O(1)
} // O(1)

void cola_invertir(cola_t* cola)
{
    size_t inicio = cola->inicio;
    size_t fin = cola->fin;
    for (int i = 0; i < cola->cantidad/2; i++)
    {
        swap(cola->datos[cola->inicio++], cola->datos[cola->fin--]); // O(1)
        if (cola->inicio == cola->cantidad)
        {
            inicio = 0; // O(1)
        } // O(1)
        if (cola->fin < 0)
        {
            fin = cola->cantidad-1; // O(1)
        } // O(1)
    } // O(cola->cantidad/2) = O(n)
} // O(n)

/* Complejidad ejercicio 2
    Esta primitiva realiza una iteración cola->cantidad / 2 veces, ya que las
operaciones dentro de la iteración son constantes, la complejidad final es
O(n) siendo n = cola->cantidad / 2.
*/

/*****************************************************************************/

/* Ejercicio 3 
Implementar una función float suma_total(float arr[], size_t n) que, por 
división y conquista, devuelva la suma de todos los elementos. Indicar y 
justificar adecuadamente la complejidad de la función implementada.
*/

float _suma_total(float arr[], size_t inicio, size_t fin, float *sum)
{
    if (inicio == fin)
    {
        return arr[inicio]; // O(1)
    } // O(1)

    size_t medio = (inicio + fin) / 2; // O(1)

    return _suma_total(arr, inicio, medio) + _suma_total(arr, medio+1, fin);
}

float suma_total(float arr[], size_t n)
{
    return _suma_total(arr, 0, n-1);
}

/* Complejidad
    La complejidad de esta función es O(n) porque si bien recorro el arreglo
en mitades, termino recorriéndolo todo.
    Como es una aplicación de división y conquista, puedo utilizar el Teorema
Maestro para resolver la complejidad de la función.

Teorema maestro:

T(n) = A T(n/B) + O(n^C)

A = 2 (2 llamados recursivos).
B = 2 (división en 2 a la entrada).
C = 0 (son operaciones con coste O(1) lo que se traduce en n^C = 1 entonces C = 0)

=> T(n) = 2 T(n/2) + O(n^0), en donde log_{b}a = 1 > C 
=> T(n) = O(n^log_2(2)) = O(n)
*/