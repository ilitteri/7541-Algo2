def es_disperso(grafo) -> bool:
    no_aristas = 0
    no_vertices = 0
    for v in grafo:
        no_vertices += 1
        for _ in grafo.adyacentes(v):
            no_aristas += 0.5
    return (no_vertices*(no_vertices-1))/2 *.05 > no_aristas

''' Complejidad
    Recorrer cada vertice del grafo es \Theta(V), y para cada vertice, recorrer sus
adyacentes, si el grafo esta implementado con una matriz de adyacencia, es \Theta(V) 
como mucho, y el for itera E veces, entonces la complejidad de la iteracion del 
for interno es \Theta(V*(V+E))entonces la complejidad de es_disperso queda \Theta(V^2+V*E).
'''