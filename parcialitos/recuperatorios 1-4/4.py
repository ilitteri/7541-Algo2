def _todos_los_caminos(grafo, v, w, visitados, camino, caminos) -> None:
    if len(visitados) == len(grafo):
        return

    visitados[v]= True
    camino.append(v) 

    if v == w: 
        caminos.append(camino)
    else:
        for x in grafo.adyacentes[v]: 
            if visitados[x] == False: 
                _todos_los_caminos(grafo, x, w, visitados, camino)
    camino.pop() 
    visitados[v]= False

def todos_los_caminos(grafo, v, w) -> int:
    caminos =  []
    _todos_los_caminos(grafo, v, w, {}, [], caminos)
    return len(caminos)