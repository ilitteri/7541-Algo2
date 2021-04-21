Escribir una función bool `es_bipartito(grafo)` que dado un grafo no dirigido devuelva `true` o `false` de acuerdo a si es bipartito o no. Indicar y justificar el orden del algoritmo. ¿Qué tipo de recorrido utiliza?

### Métodos del grafo no dirigido:
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