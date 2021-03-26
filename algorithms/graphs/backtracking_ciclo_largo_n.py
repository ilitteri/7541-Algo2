def _dfs_ciclo_largo_n(grafo, v, origen, n, visitados, camino_actual):
    # Agrego el origen a visitados.
    visitados.add(v)
    # Caso base.
    if len(camino_actual) == n:
        if origen in grafo.adyacentes(v):
            return camino_actual
        else:
            visitados.remove(v)
            return None
    for w in grafo.adyacentes(v):
        # Descarto vertices visitados.
        if w in visitados:
            continue
        # Si no fue visitado, lo agrego al camino, y lo visito.
        solucion = _dfs_ciclo_largo_n(grafo, w, origen, n, visitados, camino_actual + [w])
        # Si tengo solucion, la devuelvo, sino pruebo con el siguiente.
        if solucion is not None:
            return solucion
    # Si no funciona para ningun vertice, doy un paso atras (backtracking)
    visitados.remove(v)
    return None

def ciclo_largo_n(grafo, origen, n):
    return _dfs_ciclo_largo_n(grafo, origen, origen, n, set(), [origen])