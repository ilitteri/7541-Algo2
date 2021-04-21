Implementar una función (que utilice división y conquista) de orden _O(n logn)_ que dado un arreglo de _n_ números enteros devuelva true o false según si existe algún elemento que aparezca más de la mitad de las veces. Justificar el orden de la solución. Ejemplos:

```
[1, 2, 1, 2, 3] -> false
[1, 1, 2, 3] -> false
[1, 2, 3, 1, 1, 1] -> true
[1] -> true
```

Aclaración: Este ejercicio puede resolverse, casi trivialmente, ordenando el arreglo con un algoritmo eficiente, o incluso se puede realizar más rápido utilizando una tabla de hash. Para hacer interesante el ejercicio, resolver sin ordenar el arreglo, sino puramente división y conquista.