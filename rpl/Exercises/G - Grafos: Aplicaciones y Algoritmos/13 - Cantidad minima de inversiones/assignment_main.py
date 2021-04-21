from grafo import Grafo

def dijkstra(grafo, inicio, fin):
    padre = {}
    distancias = {v:float('inf') for v in grafo}
    padre[inicio] = None
    distancias[inicio] = 0
    q = []
    q.append((distancias[inicio], inicio))
    while q:
        _, v = q.pop(0)
        for w in grafo.adyacentes(v):
            if distancias[v] + grafo.peso_arista(v, w) < distancias[w]:
                distancias[w] = distancias[v] + grafo.peso_arista(v, w)
                padre[w] = v
                q.append((distancias[w], w))
    return distancias[fin]
    

def minimas_inversiones(grafo, s, t):
    aux = Grafo(es_dirigido=True)
    for v in grafo:
        if v not in aux:
            aux.agregar_vertice(v)
        for w in grafo.adyacentes(v):
            if w not in aux:
                aux.agregar_vertice(w)
            aux.agregar_arista(v, w, 0)
            if not grafo.estan_unidos(w, v):
                aux.agregar_arista(w, v, 1)

    return dijkstra(aux, s, t)