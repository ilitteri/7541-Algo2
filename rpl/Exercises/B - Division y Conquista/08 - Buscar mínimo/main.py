l = [1, 2, 3, 3, 5, 7]

def a(l, n):
    if n >= 0:
        return True if l[n] == n else a(l, n-1)
    return False

print(not a(l, len(l) - 1))