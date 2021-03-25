def bfs_shortest_path(graph: Graph, origin: str, destination: str) -> list:
    visited = set()
    vertices = Queue()
    vertices.enqueue(origin)
    visited.add(origin)
    paths = []
    path = [origin]
    while not vertices.is_empty():
        v = vertices.dequeue()
        if v == destination: 
            break
        for w in graph.adjacents(v):
            if w not in visited:
                path.append(w)
                visited.add(w)
                vertices.enqueue(w)
    
    return path

def caminos_minimos_mst(mst: Graph, v: str) -> list:
    return [bfs_shortest_path(mst, v, w) for w in mst]