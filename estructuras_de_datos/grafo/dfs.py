def _dfs(grafo, v, padres: dict, orden: dict, visitados: set):
    visitados.add(v)
    for w in grafo.adyacentes(v):
        if w not in visitados:
            padres[w] = v
            orden[W] = orden[v] + 1
            dfs(grafo, w, visitados, padres, orden)

def dfs(grafo):
    visitados = set()
    padres = {}
    orden = {}
    for v in grafo:
        if v not in visitados:
            padres[v] = None
            orden[v] = 0
            _dfs(grafo, v, padres, orden)
    
    return padres, orden, visitados
