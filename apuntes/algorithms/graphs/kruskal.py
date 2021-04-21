def obtener_aristas(grafo):
    aristas = []
    visitados = set()
    for v in grafo.obtener_vertices():
        visitados.add(v)
        for w in grafo.adyacentes(v):
            if w not in visitados:
                aristas.append((v, w))
    return aristas

def mst_kruskal(grafo):
    # Creamos los conjuntos.
    conjuntos = UnionFind(grafo.obtener_vertices())
    # Ordenamos las aristas de menor a mayor
    aristas = sorted(obtener_aristas(grafo))
    arbol = grafo_crear(grafo.obtener_vertices())
    # Por cada arista (en ese orden),
    for a in aristas:
        v, w, peso = a
        # Si son iguales, salteamos.
        # Agregar esta arista generaria un ciclo.
        if conjuntos.find(v) == conjuntos.find(w):
            continue
        # Sino, agregamos la arista.
        arbol.agregar_arista(v, w, peso)
        # Unimos los conjuntos.
        conjuntos.union(v, w)
    return arbol