from typing import Any

class Queue:
    '''Estructura de cola'''
    def __init__(self):
        self.__data = []
        self.__count = 0
        
    def push(self, data: Any):
        self.__data.append(data)
        self.__count += 1

    def pop(self):
        self.__count -= 1
        data = self.__data.pop(0)
        return data

    def esta_vacia(self):
        return self.__count == 0