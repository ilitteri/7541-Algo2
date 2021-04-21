def es_diccionario_padres_bfs(d, origen):
    origen_es_padre = False
    for v in d:
        # Si v es el origen,
        if v == origen:
            # y v no es None.
            if d[v] != None:
                return False
            # y es None.
            continue
        # Si un padre no es None y no se encuentra entre los vertices.
        if d[v] != None and d[v] not in d:
            return False
        # Si hay algun vertice distinto del origen en None.
        if d[v] == None and v != origen:
            return False
        # Si el origen es padre de al menos uno.
        if d[v] == origen:
            origen_es_padre = True
            
    return origen_es_padre

''' Complejidad
    La complejidad de esta funcion es O(V) ya que solo itero el diccionario de
vertices que me dan, las operaciones internas son constantes.
'''