def _lista_cc_dfs(grafo, v, componente_conexa, visitados):
    visitados.add(v)
    componente_conexa.append(v)
    for w in grafo.adyacentes(v):
        if w not in visitados:
            _lista_cc_dfs(grafo, w, componente_conexa, visitados)

def lista_cc(grafo):
    visitados = set()
    componentes_conexas = []
    for v in grafo:
        if v not in visitados:
            componente_conexa = []
            _lista_cc_dfs(grafo, v, componente_conexa, visitados)
            componentes_conexas.append(componente_conexa)
    
    return componentes_conexas