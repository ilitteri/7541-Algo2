def puntos_articulacion(grafo, v, visitados, es_raiz, orden, mas_bajo, p_art):
    visitados.add(v)
    hijos = 0
    for w in grafo.adyacentes(v):
        if w not in visitados:
            orden[w] = orden[v] + 1
            hijos += 1
            puntos_articulacion(grafo, w, visitados, es_raiz, orden, mas_bajo, p_art)
            if mas_bajo[w] >= orden[v]:
                p_art.add(v)
            mas_bajo[v] = min(mas_bajo[v], mas_bajo[w])
        else:
            mas_bajo[v] = min(mas_bajo[w], orden[w])
    if es_raiz and hijos > 1:
        p_art.add(v)