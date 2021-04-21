def colorear(grafo, n):
    vertices_coloreados = {v:None for v in grafo}
    
    for v in grafo:
        for color in range(n):
            coloreable = True
            for w in grafo.adyacentes(v):
                if vertices_coloreados[w] == color:
                    coloreable = False
                    break
            if coloreable: 
                vertices_coloreados[v] = color
                break
    for k, v in vertices_coloreados.items():
        if v == None:
            return False
    return True