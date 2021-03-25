def mst_prim(grafo):
    # Elijo un vertice aleatorio
    v = grafo.vertice_aleatorio()
    # Creamos el conjunto de visitados
    visitados = set()
    visitados.add(v)
    # Creamos un heap
    q = Heap()
    # Creamos un arbol (mst)
    arbol = grafo_crear(grafo.obtener_vertices())
    # Por cada arista del origen, la encolamos.
    for w in grafo.adyacentes(v):
        q.encolar((v, w), grafo.peso_arista(v, w))
    # Mientras no este vacia la cola,
    while not q.esta_vacia():
        # desencolamos.
        v, w = q.desencolar()
        # Si el adyacente fue visitado, continuamos.
        if w in visitados:
            continue
        # Sino agregamos la arista al arbol.
        arbol.agregar_arista(v, w, grafo.peso_arista(v, w))
        visitados.add(w)
        # Encolamos los adyacentes al nuevo visitado.
        for u in grafo.adyacentes(w):
            if u not in visitados:
                q.encolar((w, u), grafo.peso_arista(w, u))
    
    return arbol