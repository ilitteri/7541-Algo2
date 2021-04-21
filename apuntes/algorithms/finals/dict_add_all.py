class Dict:
    def __init__(self):
        self.me = {}
        self.engania_pichanga = 0

    def add_all(self, y):
        self.engania_pichanga += y
    
    def obtener(self, x):
        return self.me[x] += self.engania_pichanga
    
    def borrar(self, x):
        if x in self.me:
            del(self.me[x])
        
    def insertar(self, x, y):
        self.me[x] = y

    def add(self, x, y):
        self.me[x] += y