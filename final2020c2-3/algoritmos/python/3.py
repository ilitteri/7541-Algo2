def obtener_aristas(grafo: Grafo, vertices: set) -> list:
    aristas = []
    visitados = set()
    for v in vertices:
        visitados.add(v)
        for w in grafo.adyacentes(v):
            if w not in visitados:
                aristas.append((v, w))
    return aristas

def cantidad_aristas(grafo: Grafo, vertices: set) -> int:
    return len(obtener_aristas(grafo, vertices)) // 2

def es_completo(grafo: Grafo, vertices: set) -> bool:
    n = len(vertices)
    return cantidad_aristas(grafo, vertices) == (n*(n-1)) // 2

def _clique_tamanio_k(grafo: Grafo, v: str, k: int, visitados: set):
    visitados.add(v)

    if len(visitados) == k:
        if es_completo(grafo, visitados):
            return True
        visitados.remove(v)
        return False
    
    for w in grafo.adyacentes(v):
        if w in visitados:
            continue
        if _clique_tamanio_k(grafo, w, k, visitados):
            return True
    
    visitados.remove(v)
    return False

def clique_tamanio_k(grafo: Grafo, k: int):
    if len(grafo.obtener_vertices()) < k:
        return False
    for v in grafo:
        if _clique_tamanio_k(grafo, v, k, set()):
            return True
    return False