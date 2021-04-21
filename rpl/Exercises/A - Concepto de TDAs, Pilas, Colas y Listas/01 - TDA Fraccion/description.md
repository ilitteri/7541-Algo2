Implementar el TDA Fracción. Dicho TDA debe tener las siguientes primitivas, cuya documentación puede encontrarse en `fraccion.h`:

```
fraccion_t* fraccion_crear(int numerador, int denominador);
fraccion_t* fraccion_sumar(fraccion_t* f1, fraccion_t* f2);
fraccion_t* fraccion_mul(fraccion_t* f1, fraccion_t* f2);
char* fraccion_representacion(fraccion_t* fraccion);
int fraccion_parte_entera(fraccion_t* fraccion);
void fraccion_destruir(fraccion_t* fraccion);
```

Nota: considerar que se puede utilizar la función sprintf para generar la representación de la fracción. Por ejemplo: sprintf(buffer, "%d/%d", num1, num2).