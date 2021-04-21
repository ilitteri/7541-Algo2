# TDA Grafo

Permiten resolver y modelar muchos problemas que podemos encontrarnos.

## ¿Qué son?

- Vertices: entidades del problema que estamos modelando.
- Aristas: que son las relaciones  entre las entidades.

## Características (de las relaciones)

- Ser dirigido o no dirigido.
- Pesado o no pesado (si esas relaciones tienen algún tipo de peso, información adicional o ponderación).
- Simple o compuesto (si es que permitimos que haya mas de una arista entre dos vertices, es decir si *a* se relaciona con *b* multiples veces)
- ¿Admite bucles? (si se admite que un vertice se relacione consigo mismo).

## Ejemplos de aplicaciones

- Redes sociales: 
    - Facebook (no pesado, no dirigido, no simple, no admite bucle), 
    - Twitter (no pesado, es dirigido, no simple, no admite bucle), 
    - Instagram (es dirigido, no pesado no simple no admite bucle).
- Red de actores.
- Secuencia de estados (juego).
- Sistemas de recomendación.
- Internet.
- Mapa de ciudad para transporte.
- Mapa de ciudad.
- Estructuras enlazadas que vimos hasta ahora.
- Garbage Collector.
- Representación de cambios de monedas (si hacer cambios nos puede generar mas dinero con el que empezamos).

## Operaciones

- Crear y destruir.
- Agregar y sacar vértices.
- Agregar y sacar aristas.
- Ver si dos vértices estan unidos (y poder obtener el peso de dicha unión).
- Ver si existe un vértice con un id.
- Obtener todos los vértices.
- Obtener los adyacentes (vecinos) a un vértice.
- Iterar sobre los vértices (sin un orden específico).

## Definiciones

- **Ciclo**: es cualquier camino de por lo menos dos aristas que empiece y termine en un mismo lugar.
- **Camino (simple)**: es un camino qe empieza en un vertice y termina en otro, y pasa por cada vertice a lo sumo una vez.
- **Componente conexa**: es una definicion para grafos no dirigidos nada mas, son todos los vertices a los que llegamos desde cualquiera.
- **Grado**: es cuantas aristas entran a un vertice (grado de entrada). Cuantas aristas salen de un vertice (grado desalida).

## Orden topologico (no comparativo, orden parcial)

Queremos ordenar, pero no hay una relación de orden total, sino que existen algunas relaciones de precedencia. Ejemplos:

- Tareas a realizar en general (algunas deben hacerse antes que otras).
- Makefile: unas cosas deben compilarse antes que otras.
- Plan de estudios: hay materias que deben hacerse antes que otras.
- Películas.

---

# Parte 2

# Camino Mínimo en Grafos

## BFS

Sirve cuando el grafo es no pesado (o todos los pesos son iguales).

Podemos obtener el camino a un destino específico o hacia todos los vértices.

## Dijkstra

Una modificación sobre un algoritmo similar a BFS

Vamos a usar un Heap de mínimos + actualizar distancias.

```python
def dijkstra(grafo, origen):
    dist = {} #distancias
    padre = {} # caminos minimos
    for v in grafo: # O(v)
        distancia[v] = float("inf")
    dist[origen] = 0
    padre[origen] = None
    q = heap_crear()
    q.encolar((origen, 0))
    while not q.esta_vacia(): # O(e log v)
        v = q.desencolar()[0]
        for w in grafo.adyacentes(v):
            if dist[v] + grafo.peso_arista(v, w) < dist[w]:
                dist[w] = dist[v] + grafo.peso_arista(v, w)
                padre[w] = v
                q.encolar((w, dist[w]))
    
    return padre, distancia
```

### Complejidad

**O(E log V)** u **O(V log V)** si en lugar de encolar disponemos de una primitiva que actualice el heap.

Para grafos con pesos distintos conviene hacer BFS ya que su complejidad es de **O(E + V)**.


### ¿Si el grafo es no conexo?

No conexo y no dirigido. Nos queda en infinito la distancia ya qye no hay forma de llegar a todos los vertices.


### ¿Si

### ¿Si tenemos pesos negativos?

- Si el grafo es no dirigido, no existe solución (queda en loop).
- Si el grafo es dirigido, puede existir solución siempre y cuando no haya ciclos negativos (queda en loop).
- Este algoritmo ya no funciona bien, en estos casos se usa el algoritmo de Bellman-Ford, que lo que hace es encontrar ciclos negativos, y funcionar bien en casos de aristas con peso negativa.