Implementar en C el TDA ComposiciónFunciones que emula la composición de funciones (i.e. f(g(h(x))). Se debe definir la estructura del TDA, y las siguientes primitivas:
```
composicion_t* composicion_crear();
void composicion_destruir(composicion_t*);
bool composicion_agregar_funcion(composicion_t*, double (*f)(double));
double composicion_aplicar(composicion_t*, double);
```

Considerar que primero se irán agregando las funciones como se leen, pero tener en cuenta el correcto orden de aplicación. Por ejemplo: para emular f(g(x)), se debe hacer:

```
composicion_agregar_funcion(composicion, f);
composicion_agregar_funcion(composicion, g);
composicion_aplicar(composicion, x);
```

Indicar el orden de las primitivas.