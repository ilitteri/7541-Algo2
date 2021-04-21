Dar una implementación en C de cómo podría ser la primitiva `hash_guardar` para el caso de un hash cerrado con Cuckoo Hashing con dos funciones de hashing (suponer que se llaman `h1` y `h2`). Si la clave ya se encontraba en el hash simplemente devolver `false` (no es necesario hacer un reemplazo del dato).
Se puede asumir que la estructura no se redimensiona: en caso de toparse con una situación de un ciclo, debe devolver `false`. 
La estructura del Hash es:

```cpp
typedef struct hash {                   typedef struct campo_hash {
    campo_hash_t* tabla;                    char* clave;
    size_t cantidad;                        void* dato;
    size_t tam_tabla;                       int num_fhash;
} hash_t;                               } campo_hash_t;
```