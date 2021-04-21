''' Viborita '''

def bfs(grafo, vertices) -> set:
    if (len(vertices) == 0):
        return set()

    visitados = set()
    espera = []
    origen = vertices[0]
    visitados.add(origen)

    espera.append(origen)
    while len(espera) != 0:
        v = espera.pop(0)
        for adyacente in grafo.adyacentes(v):
            if not adyacente in visitados:
                visitados.add(adyacente)
                espera.append(adyacente)
    
    return visitados

def es_conexo(grafo):
    vertices = grafo.obtener_vertices()
    return set(vertices) == bfs(grafo, vertices)