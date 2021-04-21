from grafo import Grafo

def no_adyacentes(grafo, n):
    vertices = set(grafo.obtener_vertices())
    for v in grafo:
        no_adyacentes = vertices - set(grafo.adyacentes(v)) - set(v)
        if len(no_adyacentes) == n:
            return True
    return False