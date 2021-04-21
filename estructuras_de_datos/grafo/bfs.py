def bfs(grafo, origen):
    visitados = set()
    padres = {}
    orden = {}
    q = Cola()
    visitados.add(origen)
    padres[origen] = None
    orden[origen] = 0
    q.encolar(origen)
    while not q.esta_vacia():
        v = q.desencolar()
        for w in grafo.adyacentes(v):
            visitados.add(w)
            padres[w] = v
            orden[w] = orden[v] + 1
            q.encolar(w)
    
    return padres, orden, visitados

