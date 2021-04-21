def _buscar_cercano_k(a, k, inicio, fin):
    if inicio == fin:
        return a[inicio]

    medio = (inicio + fin) // 2
    
    # k se encuentra en el arreglo.
    if a[medio] == k:
        return a[medio]
    
    # k no esta en el arreglo, y su mas cercano esta en el medio.
    elif a[medio] < k and a[medio+1] > k:
        return a[medio] if k-a[medio] < a[medio+1]-k else a[medio+1]

    return buscar_k(a, k, inicio, medio-1) if k < a[medio] else buscar_k(a, k, medio + 1, fin)

def buscar_cercano_k(a: list, k: int, largo: int):
    if k > a[largo-1]:
        return a[largo-1] # O(1)
    elif k < a[0]:
        return a[0] # O(1)

    return _buscar_cercano_k(a, k, 0, largo, {}) # O(log n)

''' Complejidad
    Si k es mayor a todos los del arreglo o menor a todos los del arreglo,
entonces la complejidad es O(1) (mejor de los casos).
    En el peor de los casos, k esta, o no esta pero su mas cercano esta en el
medio del arreglo. Entonces en ese caso su complejidad por Teorema Maestro es:

A = 1, porque se realiza un llamado recursivo.
B = 2, porque se divide al arreglo original en 2.
C = 0, porque todas las operaciones en la recursividad son constantes.

en donde, log_{B}(A) = C => la complejidad es O(n^{C} * log(n)) = O(log n).
'''