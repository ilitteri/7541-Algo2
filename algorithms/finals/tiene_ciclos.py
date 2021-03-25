def dfs(grafo, origen, v, visitados: set):
    visitados.add(v)
    for w in grafo.adyacentes(v):
        if w not in visitados:
            return dfs(grafo, origen, w, visitados)
        if origen == w:
            return True
    return False

def tiene_ciclos(grafo):
    for v in grafo:
        if dfs(grafo, v, v, set()):
            return True
    return False