def dfs(grafo, origen, v, padre, distancia, peso_min_actual):
    for w in grafo.adyacentes(v):
        if w == origen and padre[v] != origen:
            peso_camino = distancia[v] + grafo.peso_arista(v, origen)
            if len(distancia) == len(grafo) and peso_camino < peso_min_actual[0]:
                peso_min_actual[0] = peso_camino
            return
        if w in distancia:
            continue
        distancia[w] = distancia[v] + grafo.peso_arista(v, w)
        padre[w] = v
        dfs(grafo, origen, w, padre, distancia, peso_min_actual)
        distancia.pop(w)
        padre.pop(w)

def viajante(grafo):
    peso_min_actual = [float('inf')]
    for v in grafo:
        dfs(grafo, v, v, {v: None}, {v: 0}, peso_min_actual)
    return peso_min_actual[0]
