def aristas(grafo):
    aristas = []
    visitados = set()
    for v in grafo.obtener_vertices():
        visitados.add(v)
        for w in grafo.adyacentes(v):
            if w not in visitados:
                aristas.append((v, w))
    return aristas

def cantidad_aristas(grafo):
    return len(aristas(grafo)) // 2