/* Ejercicio 1
Una nueva actualización de Tinder permite encontrar el Match perfecto. 
Para aquellos que se inscriban a este nuevo feature, sus perfiles serán 
categorizados (automáticamente) para luego encontrar un Match perfecto con otra 
persona que tenga igual categoría. Hasta ahora se cuenta con un hash que tiene 
como clave el ID del usuario (cadena), y como valor asociado un código 
(también cadena) que responde a la categorización del perfil. Implementar una 
función en C que reciba dicho diccionario y que devuelva true si fue posible 
encontrarle pareja a todos los que participaron en esta actualización, false si
por lo menos alguno quedó solo. Indicar y justificar el orden de la función.
Aclaración: los Match perfectos son para parejas. Aún no se permite armar 
tríos o poliamor.
*/

static bool *agrupar_especialidades(hash_t *cuentas_y_categorias, hash_t *categorias)
{
    hash_iter_t *cuentas_y_categorias_iter = hash_iter_crear(cuentas_y_categorias);

    if (cuentas_y_categorias_iter == NULL)
    {
        return false;
    }

    while (!hash_iter_al_final(cuentas_y_categorias_iter))
    {
        char *id_actual = hash_iter_ver_actual(cuentas_y_categorias_iter); // O(1)
        char *categoria_actual = hash_obtener(cuentas_y_categorias, id_actual); // O(1)
        bool pertenece = hash_obtener(categorias, categoria_actual) != NULL; // O(1)
        if(!hash_guardar(categorias, categoria_actual, pertenece ? *(size_t *)hash_obtener(categorias, categoria_actual)+1 : 1))
        {
            hash_iter_destruir(cuentas_y_categorias_iter); // O(1)
            return false;
        } // O(1)
        hash_iter_avanzar(cuentas_y_categorias_iter); // O(1)
    } // O(n)
    hash_iter_destruir(cuentas_y_categorias_iter); // O(1)
    return true;
}

static bool verificar_parejas(hash_t *categorias)
{
    hash_iter_t *verificador_parejas = hash_iter_crear(categorias);

    bool parejas = true;
    while (!hash_iter_al_final(verificador_parejas))
    {
        char *categoria_actual = hash_iter_ver_actual(verificador_parejas); // O(1)
        parejas &= *(size_t *)hash_obtener(categorias, categoria_actual) % 2 == 0; // O(1)
        if (!parejas)
        {
            break;
        }
        hash_iter_avanzar(verificador_parejas); // O(1)
    } // O(k)
    hash_iter_destruir(verificador_parejas);

    return parejas;
}

bool todos_felices(hash_t *cuentas_y_categorias)
{
    hash_t *categorias = hash_crear(NULL);

    if (categorias == NULL)
    {
        return false;
    }

    if (!agrupar_especialidades(cuentas_y_categorias, categorias))
    {
        hash_destruir(categorias);
        return false;
    } // O(n)

    if (!verificar_parejas(categorias))
    {
        hash_destruir(categorias);
        return false;
    } // O(k)

    hash_destruir(categorias);

    return true;
}

/* Complejidad ejercicio 1
    La función principal bool todos_felices(hash_t *cuentas_y_categorias)
llama a la función agrupar_especialidades que cuesta O(n) siendo n la cantidad de
usuarios en el diccionario original (porque crea un iterador para iterar al
mismo y va incrementando un contador que significa la cantidad de usuarios
pertenecientes a una categoría, en el diccionario de categorías creado por mi);
Luego llama a la función verificar_parejas que cuesta O(k) siendo k la cantidad
de categorías, además k es menor o igual a n (cantidad de usuarios, peor de los
casos todos categorías distintas).
    Como conclusión, la complejidad total es:
    O(n) + O(k) = O(n+k) (O(2n) = O(n) si k = n).
*/

/*****************************************************************************/

/* Ejercicio 2
Implementar en C una primitiva para el ABB que nos permita obtener la segunda 
máxima clave del ABB, con firma const char* abb_segundo_maximo(const abb_t*). 
En caso de tener menos de dos elementos, devolver NULL. La primitiva debe
ejecutar en O(log n). Justificar el orden del algoritmo propuesto.
   O       O
  /         \
 O           O
*/

static abb_nodo_t *buscar_maximo(abb_nodo_t *actual)
{
    if (actual->der == NULL)
    {
        return actual;
    }
    return buscar_maximo(actual->der); // O(log n)
}

static char *_abb_segundo_maximo(abb_nodo_t *actual) 
{ 
    if (actual->der == NULL && actual->izq != NULL) 
    {  
        return buscar_maximo(actual->izq)->clave; // O(log n)
    } // O(log n)
    if (actual->der != NULL && actual->der->izq == NULL && actual->der->der == NULL) 
    {  
        return actual->clave;
    }

    return _abb_segundo_maximo(actual->der); // O(log n)
}

const char* abb_segundo_maximo(const abb_t*)
{
    if (abb == NULL || abb->cantidad < 2)
    {
        return NULL;
    }
    return _abb_segundo_maximo(abb->raiz); // O(log n)
}

/* Complejidad ejercicio 2
    La complejidad de esta función al final es O(log n), porque lo que hace es
en el fondo una búsqueda binaria. 
    La función wrapper se basa en dos casos base. El primero, si no tengo hijo
derecho, pero si tengo hijo izquierdo, entonces hay 2 casos, o el segundo 
mayor es mi hizo izquierdo, o es el mayor desde mi hijo
izquierdo; el segundo caso base es, si tengo hijo derecho, ya no me preocupo por
el subárbol izquierdo, allí no voy a encontrar un segundo máximo, entonces
pregunto por los "nietos" del actual, si no tiene, entonces significa que el hijo
derecho del actual es el máximo, por lo tanto el actual el segundo máximo.
    El primer caso, hace una llamada a una función wrapper que busca el mayor,
esta búsqueda también es O(log n) porque por el Teorema Maestro, A = 1 (una
llamada recursiva), B = 2 (busco en un subárbol), C =(aprox.) 0 (por despeje de O(1)),
entonces O(log n).
    En el peor de los casos es O(log n) + O(log n) = O(2log n) = O(log n) siendo
n la cantidad de nodos del árbol.
*/

/*****************************************************************************/

/* Ejercicio 3
Realizar un seguimiento de aplicar RadixSort para ordenar el siguiente arreglo 
de fechas en formato DDMM, donde deben quedar primero ordenado por mes, y 
dentro del mismo mes, por día:
1806 - 2711 - 0707 - 1110 - 3004 - 3103 - 0107 - 1004 - 3003 - 1911
*/

// Se ordena el arreglo teniendo en cuenta el primer valor menos 
// significativo que en este caso son los primeros dos dígitos (día)

// 0107 - 0707 - 1004 - 1110 - 1806 - 1911 - 2711 - 3003 - 3004 - 3103

// Se ordena el arreglo teniendo en cuenta el valor más significativo, que
// corresponde al tercer y cuarto dígito (mes):

// 3003 - 3103 - 1004 - 3004 - 0107 - 0707 - 1110 -  1811  - 1911 - 2711

// Y asi queda ordenado primero por mes y despues por dia.