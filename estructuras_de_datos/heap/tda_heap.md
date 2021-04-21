# TDA Cola de Piroridad

- El orden de salida no es el de entrada, sino que está dado por una prioridad. El elemento que salga será el más prioritario.

# Heap

## Primitivas
```c
typedef struct heap heap_t;
typedef int (*cmp_func_t) (const void *a, const void *b);

heap_t *heap_crear(cmp_func_t cmp);
heap_t *heap_crear_arr(void *arreglo[], size_t n, cmp_func_t cmp);
void heap_destruir(heap_t *heap, void destruir_elemento(void *e));

size_t heap_cantidad(const heap_t *heap);
bool heap_esta_vacio(const heap_t *heap);

bool heap_encolar(heap_t *heap, void *elem);
void *heap_ver_max(const heap_t *heap); // -> Deberia ser O(1)
void *heap_desencolar(heap_t *heap);
```

### Encolar O(log n)

- Al encolar, guardamos el elemento al final.
- Aplicamos *Upheap*:
    - Si el elemento es más grande que su padre, entonces se intercambian, y se aplica upheap para el padre.
    - Sino, terminó.
- Upheap cuesta O(log n).

### Desencolar O(log n)

- Llevamos el último elemento al primer lugar (podemos intercambiar).
- Aplicamos *Downheap*:
    - Si alguno de los hijos es más grande que el elemento, entonces intercambiar con el más grande de ellos.
    - Sino, terminó.
- Downheap cuesta O(log n).

## Estructura interna 

```c
typedef struct heap {
    void **datos;
    size_t tam;
    size_t cant;
    heap_comparar_dato_t cmp;
} heap_t;
```

### ¿Si tenemos dos prioridades?

- Se 2 colas, uno para los más prioritarios y otro para los menos prioritarios.

### ¿Si tenemos k prioridades?

##### Opción ABB (o AVL)
- Problema: obtener el maximo no va a ser *O(1)*.
- Puede resolverse eso pero hay que mantenerlo.
- Va a ser menos eficiente.
- Construir un AVL de *n* elementos ya coincidos es *O(n log n)*.
- Es dificil de implementar.
- Nos obliga a saber los "valores de prioridades" de antemano.

### Propiedades de heap (de máximos)

Un AB tiene propiedad de *heap* si la rauz es más grande (o igual) que sus dos hijos, y estos tambien son *heaps*.

### Representación en árbol izquierdista

Un árbol izquierdista es aquel que tiene todos los niveles completos, salvo a lo sumo el último, que debe completarse de izquierda a derecha.

### Representación de arreglos

En un arreglo como si fuera el recorrido por niveles del AB.

Si estoy en la posicion *i*:

- ¿Cuáles son las posiciones de sus hijos (si existen)?

`hijo_izq = 2 * i + hijo_der = 2 * i + 2`

- ¿Cuál es la posición de su padre?

`padre = (i - 1) / 2`

### Actualizar prioridad

- Buscar un elemetno en particular sería *O(n)*. Queremos que sea *O(log n)*.
- Si pudiéramos saber rápido en qué posición se encuentra un elemento, lo actualziamos y aplicamos upheap o downheap (podemos llamar a ambos).
- Solución: usar un hash. Problema: nuestros datos son `void *` entonces nos tienen que psar funcion de hashing y de comparación.

### Heapsort

Si el arreglo tuviera forma de heap, sabemos que el maximo esta en la primera posicion.

Intercambiamos con el ultimo y volvemos a darle forma de Heap aplicando Downheap.

Ejemplo: Tenemos el arreglo [6, 1, 5, 4, 10, 2]

1) Lo transformamos en heap con heapify.

