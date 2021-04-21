def dijkstra(grafo, origen):
    dist = {} #distancias
    padre = {} # caminos minimos
    for v in grafo:
        dist[v] = float("inf")
    dist[origen] = 0
    padre[origen] = None
    q = []
    q.append((origen, 0))
    while q:
        v = q.pop(0)[0]
        for w in grafo.adyacentes(v):
            if dist[v] + grafo.peso_arista(v, w) < dist[w]:
                dist[w] = dist[v] + grafo.peso_arista(v, w)
                padre[w] = v
                q.append((w, dist[w]))
    
    return dist

def diametro(grafo):
    if len(grafo) == 0:
        return 0
    distancias_minimas = [dijkstra(grafo, v) for v in grafo]
    return max(max(distancia.values()) for distancia in distancias_minimas)