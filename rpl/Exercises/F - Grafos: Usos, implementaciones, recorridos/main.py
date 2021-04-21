connected_graph = {
                    "A": ["B"], 
                    "B": ["A", "C"], 
                    "C":["B"], 
                    "D": ["E", "C"], 
                    "E": ["D"]
                }

disconnected_graph = {
                    "A": ["B"], 
                    "B": ["A", "C"], 
                    "C":["B"], 
                    "D": ["E"], "E": ["D"]
                }

aconnected_graph = {
                    "A": ["X"], 
                    "X":["U", "A"], 
                    "B": ["U"], 
                    "U":["X", "B"], 
                }









def bfs(grafo):
    visitados = set()
    espera = []

    origen = grafo.obtener_vertices()[0]
    visitados.add(origen)

    espera.append(origen)
    while len(espera) != 0:
        v = espera.pop(0)
        for adyacente in grafo.adyacentes(v):
            if not adyacente in visitados:
                visitados.add(adyacente)
                espera.append(adyacente)
    
    return visitados



def is_connected(graph: dict) -> bool:
    vertex = graph.keys()
    connected_set = set()
    for v in vertex:
        if len(connected_set) == 0:
            connected_set.add(v)
        aux_set = set(v)
        for ad in graph[v]:
            aux_set.add(ad)
        if connected_set.isdisjoint(aux_set):
            return False 
        connected_set |= aux_set

    return True

def main():
    print(is_connected(aconnected_graph))

if __name__ == '__main__':
    main()