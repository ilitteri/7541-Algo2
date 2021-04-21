import cola
import grafo

def _bfs(grafo, q, visitados, padres):
    while not q.esta_vacia():
        v = q.desencolar()
        for w in grafo.adyacentes(v):
            visitados.add(w)
            padres[w] = v
            q.encolar(w)

def bfs(grafo, origen):
    visitados = set()
    padres = {}
    q = Cola()
    # en C a esta altura si salio mal la creacion, causaria un error.
    visitados.add(origen)
    padres[origen] = None
    q.encolar(origen)
    _bfs(grafo, q, visitados, padres)
    # en C a esta altura destruiria con la correspondiente funcion de
    # destruccion de dato, la cola creada y destruiria el diccionario
    # de visitados.
    return padres

def H(objetivo, grafo):
    # Obtiene los padres e hijos con un recorrido bfs
    padres = bfs(grafo, objetivo)
    
    # Declaro una etiqueda menor a cero (inicialmente)
    maxima_etiqueta = -1

    # El vertice solicitado no tiene hijos
    if len(padres) == 1:
        return objetivo
    
    # Itero el diccionario de padres, guardo la mayor etiqueta a la que llega
    # el vertice deseado.
    for hijo, padre in padres:
        if objetivo == padre and hijo > maxima_etiqueta:
            maxima_etiqueta = hijo
    
    # en este punto, destruiria el diccionario de padres.
    
    return maxima_etiqueta

# La complejidad del algoritmo es O(V + E) debido al recorrido BFD, donde
# V: #vertices y E: #aristas, en el peor de los casos, ya que si se busca,
# por ejemplo un vertice sin hijos, es <.