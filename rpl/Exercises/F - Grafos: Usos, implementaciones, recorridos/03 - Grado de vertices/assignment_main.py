''' Viborita '''

def grado_vertices(grafo): # a
    return {vertice:len(grafo.adyacentes(vertice)) for vertice in grafo.obtener_vertices()}

def grado_salida(grafo): # b
    return grado_vertices(grafo)

def grado_entrada(grafo): # c
    vertices = grafo.obtener_vertices()
    grados = {vertice:0 for vertice in vertices}
    for vertice in vertices:
        for adyacente in grafo.adyacentes(vertice):
            grados[adyacente] += 1
    return grados