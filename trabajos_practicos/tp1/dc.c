#define  _POSIX_C_SOURCE 200809L // para getline

// Librerias generales

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Librerias locales

#include "calc_helper.h"
#include "pila.h"
#include "strutil.h"

// Prototipo de funciones internas de dc.c

bool calc(char *line, calc_num *res);
bool do_operation(struct calc_oper operation, calc_num *nums, calc_num *res);
calc_num int_pow(calc_num base, calc_num exp);
calc_num int_log(calc_num num, calc_num base);
calc_num int_sqrt(calc_num num);

int main()
{
    char *line = NULL;
    size_t size;

    while (getline(&line, &size, stdin) != -1) {
        calc_num res;
        if (!calc(line, &res))
            printf("ERROR\n");
        else
            printf("%ld\n", res);
    }
    free(line);

    return 0;
}

/* Calcula la potencia entera */
calc_num int_pow(calc_num base, calc_num exp) {
    double res = pow((double)base, (double)exp);
    return (calc_num)res;
}

/* Calcula el logaritmo entero */
calc_num int_log(calc_num num, calc_num base) {
    return (calc_num)(log((double)num) / log((double)base));
}

/* Calcula la raiz entera */
calc_num int_sqrt(calc_num num) {
    double res = sqrt((double)num);
    return (calc_num)res;
}

/* Realiza las operaciones */
bool do_operation(struct calc_oper operation, calc_num *nums, calc_num *res) {
    switch (operation.op) {
        case OP_ADD:
            *res = nums[0] + nums[1];
            break;
        case OP_SUB:
            *res = nums[0] - nums[1];
            break;
        case OP_MUL:
            *res = nums[0] * nums[1];
            break;
        case OP_DIV:
            // Division por cero, la operacion sale mal.
            if (nums[1] == 0)
                return false;
            *res = nums[0] / nums[1];
            break;
        case OP_POW:
            // Potencia es negativa, la operacion sale mal.
            if (nums[1] < 0)
                return false;
            *res = int_pow(nums[0], nums[1]);
            break;
        case OP_LOG:
            // Base menor a 2, la operacion sale mal.
            if (nums[1] < 2)
                return false;
            *res = int_log(nums[0], nums[1]);
            break;
        case OP_RAIZ:
            // La raiz de un numero negativo hace salir mal la operacion.
            if (nums[0] < 0)
                return false;
            *res = int_sqrt(nums[0]);
            break;
        case OP_TERN:
            *res = nums[0] ? nums[1] : nums[2];
            break;
    }
    return true;
}

/* Parsea la entrada y produce un resultado */
bool calc(char *line, calc_num *res) {
    // Creo la pila de numeros
    pilanum_t *numbers = pilanum_crear();

    // Si no se pudo reservar suficiente memoria, devuelvo false.
    if (numbers == NULL)
        return false;
    
    // Separo las palabras de una linea
    char **tokens = dc_split(line);

    // Si no se pudo reservar suficiente memoria, devuelvo false.
    if (tokens == NULL)
        return false;

    bool operations_ok = true;
    for (int i = 0; tokens[i] != NULL && operations_ok; i++) {
        struct calc_token parsed;

        if (!calc_parse(tokens[i], &parsed))
            // Si el parseo sale mal la variable booleana va a hacer 
            // saltar un error.
            operations_ok = false;

        else if (parsed.type == TOK_NUM)
            // Si el token es un numero entonces lo apilo en la pila de
            // numeros.
            apilar_num(numbers, parsed.value);

        else if (parsed.type == TOK_OPER) {
            // Si el token es un operador, creo un arreglo de numeros
            // en donde ubico los numeros a operar.
            calc_num nums[parsed.oper.num_operandos];

            // Desapilo num_operandos veces los numeros, de esta forma
            // solo se desapilara la cantidad adecuada de numeros.
            bool desapilado_ok = true;
            for (int j = parsed.oper.num_operandos - 1; j >= 0 && desapilado_ok;
                desapilado_ok &= desapilar_num(numbers, &nums[j--]));

            if (desapilado_ok) {
                // Si se desapilo correctamente, se hace la operacion,
                // si la operacion sale bien, se apila el resultado en la
                // pila de numeros, sino se pone en false la variable
                // booleana que va a hacer saltar un error.
                calc_num result;
                if (do_operation(parsed.oper, nums, &result))
                    apilar_num(numbers, result);
                else
                    operations_ok = false;
            } 

            else
                // Si el desapilado salio mal, la variable booleana hace
                // saltar un error.
                operations_ok = false;
        } 
        else
            // El token es de tipo erroneo.
            operations_ok = false;
    }

    // Se libera el arreglo dinamico una vez que no haya mas tokens
    // para leer.
    free_strv(tokens);

    // Si las operaciones salieron bien, y se desapilo un numero mas
    // y ahora la pila esta vacia, la destruyo.
    if (operations_ok && desapilar_num(numbers, res) && pila_esta_vacia(numbers)) {
        pilanum_destruir(numbers);
        return true;
    }

    // Desapilo numeros restantes en caso de existir
    while (!pila_esta_vacia(numbers)) {
        calc_num tmp;
        desapilar_num(numbers, &tmp);
    }

    // Destruyo la pila.
    pilanum_destruir(numbers);

    return false;
}