Escribir una primitiva con la firma `void ab_invertir(ab_t* arbol)` que invierta el árbol binario pasado por parámetro, de manera tal que los hijos izquierdos de cada nodo se conviertan en hijos derechos.

La estructura arbol_t respeta la siguiente definición:

```c
    typedef struct ab {
        struct ab* izq;
        struct ab* der;
        int dato;
    } ab_t;
```

Indicar el orden de complejidad de la función implementada.