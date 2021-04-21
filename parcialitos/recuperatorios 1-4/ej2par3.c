// Ej 1
def _obtener_especies_en_peligro(ecosistema: Grafo, v, visitados: set, es_raiz: bool, orden: dict, mas_bajo: dict, especies_en_extincion: list) -> None:
    visitados.add(v)
    hijos = 0
    for w in ecosistema.adyacentes(v):
        if w not in visitados:
            orden[w] = orden[v] + 1
            hijos += 1
            _obtener_especies_en_peligro(ecosistema, w, visitados, False, orden, mas_bajo, especies_en_extincion)
            if mas_bajo[w] >= orden[v]:
                especies_en_extincion.append(v)
            mas_bajo[v] = min(mas_bajo[v], mas_bajo[w])
        else:
            mas_bajo[v] = min(mas_bajo[v], orden[w])
    if es_raiz and hijos > 1:
        especies_en_extincion.append(v)

def copiar_grafo(grafo_original: Grafo) -> Grafo:
    copia = Grafo(es_dirigido=False)

    for v in grafo_orignial:
        copia.agregar_vertice(v)

    for v in grafo_original:
        for w in grafo_original.adycentes(v):
            copia.agregar_arista(v, w)
    
    return copia

def especies_en_peligro_de_extincion(grafo: Grafo) -> list:
    copia_grafo = copiar_grafo(grafo) 
    especies_en_peligro = []
    v = copia_grafo.vertice_aleatorio()
    _obtener_especies_en_peligro(copia_grafo, v, set(), True, {v: 0}, {v: 0}, especies_en_peligro)
    return especies_en_peligro

/* Complejidad
    Copiar el grafo original cuesta O(V + E).
    Y la función que obtiene las especies en peligro de extinción que pueden
llegar a romper el ecosistema, es el algoritmo para encontrar vértices que son
puntos de articulación, y cuesta O(V + E) porque hace un recorrido bfs (que
cuesta O(V + E)).
    Entonces la complejidad de toda la función es O(V + E) + O(V + E) = O(2V + 2E) =
= O(2 (V + E)) = O(V + E).
*/

// Ej 2
int nombre_mas_corto(const void *a, const void *b)
{
    if (a == NULL && b == NULL)
    {
        return 0;
    }

    else if (a == NULL || b == NULL)
    {
        return a == NULL ? 1 : -1;
    }

    size_t largo_a = strlen((char *)a);
    size_t largo_b = strlen((char *)b);

    return largo_a == largo_b ? 0 : largo_a > largo_b ? -1 : 1; 
}

lista_t *pasajeros_habilitados(char **personas, size_t n, size_t m)
{
    heap_t *pasajeros_ordenados;

    if ((pasajeros_ordenados = heap_crear_arr(personas, n, nombre_mas_corto)) == NULL)
    {
        return NULL;
    } // O(n)

    lista_t *pasajeros_habilitados;

    if ((pasajeros_habilitados = lista_crear()) == NULL)
    {
        return NULL;
    }

    while m--
    {
        if (!lista_insertar_ultimo(heap_desencolar(pasajeros_ordenados)))
        {
            heap_destruir(pasajeros_ordenados);
            lista_destruir(pasajeros_habilitados);
            return NULL;
        }
    } // O(m log n) 

    heap_destruir(pasajeros_ordenados);

    return pasajeros_habilitados;
}

/* Complejidad
    Transformar el arreglo en heap cuesta O(n) ya que la primitiva utiliza
heapify y este es O(n) siendo n los elementos dentro del arreglo.
    Desencolar el heap en la lista cuesta O(m log n), porque densencolar del
heap cuesta O(log n) siendo n la cantidad de elementos encolados, e inserto cada
vez que desencolo del heap en la lista, lo cuál lo hago "m" veces, por lo tanto
O(m log n) siendo m la cantidad de personas que entrarán en la nave y "n" la
cantidad de personas encoladas en espera en el heap.
    Finalmente el total de costo de la función es el costo de encolar a todos en
el heap y el de desencolar a "m" del heap en la lista, por lo tanto O(m + m log n).
*/