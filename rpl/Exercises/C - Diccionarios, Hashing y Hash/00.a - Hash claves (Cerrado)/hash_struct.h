#ifndef HASH_STRUCT_H
#define HASH_STRUCT_H

typedef enum estado {
    VACIO, OCUPADO, BORRADO
} estado_t;

// tipo de función para destruir dato
typedef void (*hash_destruir_dato_t)(void *);

typedef struct campo{
  char* clave;
  void* valor;
  estado_t estado;
} campo_t;

typedef struct hash{
  size_t capacidad;
  size_t cantidad;
  hash_destruir_dato_t funcion_destruccion;
  campo_t* tabla;
} hash_t;

typedef struct hash_iter{
  const hash_t* hash;
  campo_t campo_act;
  size_t posicion;
} hash_iter_t;



#endif