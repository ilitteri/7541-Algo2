def _bfs(grafo, q, usuario_producto):
    while not q.esta_vacia():
        v = q.desencolar()
        for w in grafo.adyacentes(v):
            if usuario_producto[w] == usuario_producto[v]:
                return False
            usuario_producto[w] = not usuario_producto[v]
            q.encolar(w)

def compra_venta_bfs(grafo):
    q = Cola()
    origen = grafo.obtener_vertice_random()
    usuario_producto = {}
    usuario_producto[origen] = True
    _bfs(grafo, q, usuario_producto)
    