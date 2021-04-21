def orden_topologico_bfs(grafo):
    vertices = grafo.obtener_vetices()
    grados = {v:0 for v in vertices}
    for v in vertices:
        for w in grafo.adyacentes(v):
            grados[w] += 1
    q = Cola()
    for v in vertices:
        if grados[v] == 0:
            q.encolar(v)
    resultado = []
    while not q.esta_vacia():
        v = q.desencolar()
        resultado.append(v)
        for w in grafo.adyacentes(v):
            grados[w] -= 1
            if grados[w] == 0:
                q.encolar(w)
    
    return resultado if len(resultado) == len(grafo) else None

def _orden_topologico_dfs(grafo, v, s, visitados):
    visitados.add(v)
    for w in grafo.adyacentes(v):
        if w not in visitados:
            _orden_topologico_dfs(grafo, w, s, visitados)
    s.apilar(v)

def orden_topologico_dfs(grafo):
    visitados = set()
    s = Pila()
    for v in grafo.obtener_vetices():
        if v not in visitados:
            _orden_topologico_dfs(grafo, v, s, visitados)