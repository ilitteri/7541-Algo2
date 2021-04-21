Sabiendo que la firma del iterador interno de la lista enlazada es:
```cpp
void lista_iterar(lista_t* lista,
                  bool (*visitar)(void* dato, void* extra),
                  void* extra);
```
Se tiene una lista en donde todos los elementos son punteros a números enteros. Implementar la función visitar para que calcule la suma de todos los números pares.

