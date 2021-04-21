l = [1, 2, 90, 5, 6, 7]

def elemento_desordenado_dyc(l, start, end):
    if (end - start == 1):
        return start if l[start] > l[end] else None
    
    mid = (start + end) // 2
  
    return elemento_desordenado_dyc(l, start, mid) or elemento_desordenado_dyc(l, mid, end)


print(l[elemento_desordenado_dyc(l, 0, len(l)-1)])
