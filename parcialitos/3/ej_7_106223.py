colores = {"Rojo": True, "Azul": False}

def es_bipartito(grafo):
    if len(grafo) == 0:
        return True
    color = {v:None for v in grafo}
    v_random = grafo.vertice_aleatorio()
    color[v_random] = colores["Rojo"]
    q = []
    q.append(v_random)
    while q:
        v = q.pop(0)
        for w in grafo.adyacentes(v):
            if color[v] == color[w]:
                return False
            if color[w] == None:
                color[w] = not color[v]
                q.append(w)
    return True