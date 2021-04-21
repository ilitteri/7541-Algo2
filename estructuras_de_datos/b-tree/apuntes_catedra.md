# B-Tree

- Es un tipo de árbol binario con características similares al abb pero con menor profundidad.
- Son árboles mas bajos, pero mas anchos.
- Trabaja con datos en disco (no entran en memoria)
- El análisis de la notación Big Oh asume que las operaciones demoran lo mismo siempre (es lo mismo asignar un valor que pedir un valor), lo cual es estrictamente no cierto ya que escribir en memoria cuesta más que leer (a esto se le suma la diferencia de leer en memoria y de leer en disco).

## Para "solucionar" el problema anterior

- Aumentamos la cantidad de ramas -> reducimos la altura del árbol, con esto, la cantidad de accesos al disco van a ser muchas menos.
- Hacemos nodos más grandes: nodos que soportan más de una clave, y tienen varios hijos (Árbol B).
- 