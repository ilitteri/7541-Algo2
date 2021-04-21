Implementar una primitiva para el AB que reciba dos arreglos (o listas) de cadenas. El primer arreglo corresponde al preorder de un árbol binario. El segundo al inorder del mismo árbol (ambos arreglos tienen los mismos elementos, sin repetidos). La función debe devolver un árbol binario que tenga dicho preorder e inorder. Indicar y justificar el orden de la primitiva (tener cuidado con este punto). Considerar que la estructura del árbol binario es:

```cpp
    typedef struct arbol {
        struct arbol* izq;
        struct arbol* der;
        char* dato;
    } ab_t;
```
