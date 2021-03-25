from typing import Any

class Heap:
    def __init__(self) -> None:
        self.__data = []
        self.__count = 0
    
    def __get_parent(pos) -> int:
        return (pos - 1) / 2
    
    def __get_left_child(pos) -> int:
        return pos * 2 + 1

    
    def __get_left_child(pos) -> int:
        return pos * 2 + 2
    
    def __upheap(self, pos: int) -> None:
        if pos == 0:
            return
        father_pos = self.__get_parent(pos)
        if self.__data[pos] > self.__data[father_pos]:
            self.__data[pos], self.__data[father_pos] = self.__data[father_pos], self.__data[pos]
            self.__upheap(father_pos)
    
    def __downheap(self, current: int, count: int) -> None:
        if current >= count:
            return

        left_child_pos = self.__get_left_child(current)
        right_child_pos = self.__get_right_child(current)
        greater = current

        if right_child_pos < count and self.__data[greater] < self.__data[right_child_pos]:
            greater = right_child_pos
        
        if left_child_pos < count and self.__data[greater] < self.__data[left_child_pos]:
            greater = left_child_pos
        
        if greater != current:
            self.__data[current], self.__data[greater] = self.__data[greater], self.__data[current]
            self.__downheap(current, count)
        
    def heapify(self, arr: list):
        n = len(arr)
        pos = n / 2
        while pos > 0:
            self.__downheap(n, pos)
            pos -= 1
    
    def heap_sort(self, arr: list, count: int) -> None:
        if len(arr) == 0 or count == 0:
            return
        
        self.heapify(arr)

        while count > 0:
            arr[0], arr[count] = arr[count], arr[0]
            self.__downheap(0, count)
            count -= 1
        
    def count(self):
        return self.__count
    
    def enqueue(self, data: Any) -> None:
        self.__data.append(data)
        self.__upheap(self.__count)
        self.__count += 1
    
    def dequeue(self) -> Any:
        if self.is_empty():
            return None
        data = self.__data[0]
        self.__data[0], self.__data[-1] = self.__data[-1], self.__data[0]
        self.__downheap(0, self.__count)
        self.__count -= 1
        return data
        