Implementar un algoritmo que, dado un grafo dirigido, un vértice _s_ y otro _t_ determine la cantidad mínima de aristas que deberían cambiar de sentido en el grafo para que exista un camino de _s_ a _t_.

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