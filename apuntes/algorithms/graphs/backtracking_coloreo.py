def es_compatible(grafo, v, colores):
    for w in grafo.adyacentes(v):
        if w in colores and colores[w] == colores[v]:
            return False
    return True

def coloreo(grafo, v, colores, color, k):
    colores[v] = color
    if len(colores) == len(grafo):
        if es_compativle(grafo, v, colores):
            return True
        else:
            colores.remove(v)
            return False
    if not es_compatible(grafo, v, colores):
        colores.remove(v)
        return False
    for w in grafo.adyacentes(v):
        if w in colores:
            continue
        for color_opcion in range(n):
            if coloreo(grafo, w, colores, color_opcion, k):
                return True

    colores.remove(v)
    return False