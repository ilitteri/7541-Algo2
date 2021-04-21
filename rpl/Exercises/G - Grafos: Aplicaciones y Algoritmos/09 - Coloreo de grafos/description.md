Implementar un algoritmo que reciba un grafo y un número nn que, utilizando backtracking, indique si es posible pintar cada vértice con nn colores de tal forma que no hayan dos vértices adyacentes con el mismo color.

### Métodos del grafo
- agregar_vertice(self, v)
- borrar_vertice(self, v)
- agregar_arista(self, v, w, peso = 1)
    - el resultado será  `v <--> w`
- borrar_arista(self, v, w)
- estan_unidos(self, v, w)
- peso_arista(self, v, w)
- obtener_vertices(self)
    - Devuelve una lista con todos los vértices del grafo
- vertice_aleatorio(self)
- adyacentes(self, v)
- __str__