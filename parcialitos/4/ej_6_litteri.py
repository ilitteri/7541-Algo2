def _camino_simple_k(grafo, v, w, k, camino) -> bool:
    if v == w and len(camino) == k:
        return True
    
    for x in grafo.adyacentes(v):
        if x not in camino:
            camino += [x]
            camino_simple_k(grafo, x, w, k, camino)
        if w in camino and len(camino) == k:
                return True
        else: continue
    
    return False

def camino_simple_k(grafo, v, w, k) -> bool:
    return _camino_simple_k(grafo, v, w, k, [])