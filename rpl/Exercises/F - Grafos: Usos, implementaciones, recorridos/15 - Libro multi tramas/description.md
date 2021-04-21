Un autor decidió escribir un libro con varias tramas que se puede leer de forma no lineal. Es decir, por ejemplo, después del capítulo 1 puede leer el 2 o el 73; pero la historia no tiene sentido si se abordan estos últimos antes que el 1.

Siendo un aficionado de la computación, el autor ahora necesita un orden para publicar su obra, y decidió modelar este problema como un grafo dirigido, en dónde los capítulos son los vértices y sus dependencias las aristas. Así existen, por ejemplo, las aristas (v1, v2) y (v1, v73).

Escribir un algoritmo que devuelva un orden en el que se puede leer la historia sin obviar ningún capítulo. Indicar la complejidad del algoritmo.

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