Problema del viajante (TSP): Dada una lista de ciudades y la distancia entre cada par de ellas, ¿Cuál es el peso de la ruta más corta posible que visita cada ciudad exactamente una vez y al finalizar regresa a la ciudad de origen?

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