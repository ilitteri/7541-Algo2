from graph import Graph

def dfs(graph, start, end, path: list = [], shortest: list = None) -> list:
    #DFS
    path += [start]
    if start == end:
        return path
    for w in graph.adjacents(start):
        if w not in path: # evita ciclos
            if shortest == None or len(path) < len(shortest):
                newPath = dfs(graph, w, end, path, shortest)
                if newPath != None:
                    shortest = newPath
    return shortest

def shortestPath(graph, start, end) -> list:
    return dfs(graph, start, end, [], None)