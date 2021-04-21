El diámetro de una red es el máximo de las distancias mínimas entre todos los vértices de la misma. Implementar un algoritmo que permita obtener el diámetro de una red, para el caso de un grafo no dirigido y no pesado. Indicar el orden del algoritmo propuesto.

### Métodos del grafo:
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