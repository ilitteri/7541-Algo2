def instagram_recomendaciones(grafo, origen):
    visitados = []
    orden = {}
    recomendaciones = []
    q = Cola()

    visitados.add(origen)
    orden[origen] = 0
    q.encolar(origen)

    while not q.esta_vacia():
        v = q.encolar()
        for w in grafo.adyacentes(v):
            if w not in visitados:
                orden[w] = orden[v] + 1
                if orden[w] == 2:
                    recomendaciones.add(w)
                else:
                    q.encolar(w)
                visitados.add(w)
    return recomendaciones