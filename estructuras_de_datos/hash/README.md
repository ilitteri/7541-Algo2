# TDA Hash
 - [Millares Faustino](https://github.com/FaustinoMillares) 106366
 - [Litteri Ivan](https://github.com/ilitteri) 106223

## Implementación de Tabla de Hash Cerrado

### Primitivas del hash

```c
typedef struct hash hash_t;
typedef struct hash_iter hash_iter_t;
typedef void (*hash_destruir_dato_t)(void *);

hash_t *hash_crear(hash_destruir_dato_t destruir_dato);
bool hash_guardar(hash_t *hash, const char *clave, void *dato);
void *hash_borrar(hash_t *hash, const char *clave);
void *hash_obtener(const hash_t *hash, const char *clave);
bool hash_pertenece(const hash_t *hash, const char *clave);
size_t hash_cantidad(const hash_t *hash);
void hash_destruir(hash_t *hash);
```

### Primitivas del iterador

```c
hash_iter_t *hash_iter_crear(const hash_t *hash);
bool hash_iter_avanzar(hash_iter_t *iter);
const char *hash_iter_ver_actual(const hash_iter_t *iter);
bool hash_iter_al_final(const hash_iter_t *iter);
void hash_iter_destruir(hash_iter_t* iter);
```

### Funcion de hash utilizada

#### [Jenking Hash](https://en.wikipedia.org/wiki/Jenkins_hash_function)

```c
size_t f_hash(const char* clave) {
  size_t i = 0;
  size_t hash = 0;

  while (clave[i] != '\0') {
    hash += (uint8_t)clave[i++];
    hash += hash << 10;
    hash ^= hash >> 6;
  }

  hash += hash << 3;
  hash ^= hash >> 11;
  hash += hash << 15;

  return hash;
}
```

### Tiempos de inserción en volúmen y memoria consumida

```shell
12500 elementos - Tardó: 0.03s - Consumió: 4040 KiB
25000 elementos - Tardó: 0.04s - Consumió: 6400 KiB
50000 elementos - Tardó: 0.08s - Consumió: 11708 KiB
100000 elementos - Tardó: 0.16s - Consumió: 21628 KiB
200000 elementos - Tardó: 0.42s - Consumió: 42200 KiB
400000 elementos - Tardó: 0.97s - Consumió: 82620 KiB
800000 elementos - Tardó: 1.75s - Consumió: 163792 KiB
1000000 elementos - Tardó: 2.01s - Consumió: 179912 KiB
```