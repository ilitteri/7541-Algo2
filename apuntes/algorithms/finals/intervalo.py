def procesar_entrada(lista):
    d = {}
    i = 1
    for e in lista:
        d[e] = i
        i += 1
    return d

def contar_intervalo(entrada, a, b):
    d = procesar_entrada(entrada)
    return abs(d[a] - d[b])

def main():
    # f = [6, 1, 41, 3, 1, 2, 0]
    # counting_sort(f)
    f = [0, 1, 1, 2, 3, 6, 41]
    d =procesar_entrada(f)

if __name__ == '__main__':
    main()