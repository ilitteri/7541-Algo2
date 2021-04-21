arr = ["C1", "C2", "D1", "D2"]
# arr = ["C1", "C2", "C3", "C4", "D1", "D2", "D3", "D4"]
n = len(arr)

def foo(arreglo, inicio, fin):
    if inicio == fin - 1:
        return
    
    medio = (inicio + fin) // 2

    medio_primera_mitad = (inicio + medio) // 2
    pos_segunda_mitad = medio + 1

    for i in range(medio_primera_mitad + 1, pos_segunda_mitad):
        arreglo[i], arreglo[pos_segunda_mitad] = arreglo[pos_segunda_mitad], arreglo[i]
        pos_segunda_mitad += 1
    
    foo(arreglo, inicio, medio)
    foo(arreglo, medio+1, fin)

foo(arr, 0, n-1)

print(arr)