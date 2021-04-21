l = [9, 9, 9, 9, 9, 9, 9, 9]

def mas_de_mitad(l, inicio, fin, len):
    contador = 0
    j = inicio
    elem = l[j]
    mitad = len // 2

    while j <= fin:
        if elem == l[j]:
            contador += 1
        j += 1
    
    if contador > mitad:
        return True
    elif (inicio != fin):
        return mas_de_mitad(l, inicio+1, len-1, len)
    else:
        return False

print(mas_de_mitad(l, 0, len(l)-1, len(l)))
