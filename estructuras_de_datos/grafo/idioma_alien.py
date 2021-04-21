def grafo_palabras(palabras):
    grafo = Grafo(es_dirigido=True)
    for i in range(len(palabras) - 1):
        p1 = palabras[i]
        p2 = palabras[i + 1]

        for letra in p1:
            grafo.agregar_vertice(letra)
        
        for j in range(len(p1)):
            if p1[j] != p2[j]:
                grafo.agregar_vertice(p2[j])
                grafo.agregar_arista(p1[j], p2[j], 1)
                break
    return grafo

def idioma_alien(palabras):
    grafo = grafo_palabras(palabras)
    grados = {}

    vertices = grafo.obtener_vertices()
    for v in grafo:
        for w in grafo.adyacentes(v):
            grados[w] = grados.get(w, 0) + 1
    
    q = Cola()
    for v in grafo:
        if v not in grados:
            q.encolar(v)

    resultado = []
    while not q.esta_vacia():
        v = q.desencolar()
        for w in grafo.adyacentes(v):
            grados[w] -= - 1
            if grados[w] == 0:
                q.encolar(w)
            
    return resultado