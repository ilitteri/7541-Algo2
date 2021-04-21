#include "testing.h"
#include "strutil.h"

char *splitted_example[] = {
    "String", " de", " prueba", " para", " la", " funcion", " split", NULL
};

char *null_joined_example[] = {
    "hola", "como", "estas", NULL
};

char *zero_elements[] = {NULL};

char *joined_example = "String, de, prueba, para, la, funcion, split";

static void pruebas_substr() {
    printf("INICIO PRUEBAS DE SUBSTR\n");

    char *str0 = "String de prueba para la funcion substr";
    char *sub_string;

    sub_string = substr(str0, 6);
    print_test("substr(str0, 6) es \"String\"", strcmp(sub_string, "String") == 0);
    free(sub_string);

    sub_string = substr(str0, 21);
    print_test("substr(str0, 21) es \"String de prueba para\"", strcmp(sub_string, "String de prueba para") == 0);
    free(sub_string);

    sub_string = substr(str0 + 7, 9);
    print_test("substr(str0 + 7, 9) es \"de prueba\"", strcmp(sub_string, "de prueba") == 0);
    free(sub_string);

    sub_string = substr("", 9);
    print_test("substr(\"\", 9) es \"\"", strcmp(sub_string, "") == 0);
    free(sub_string);

    sub_string = substr("Chau", 0);
    print_test("substr(\"Chau\", 0) es \"\"", strcmp(sub_string, "") == 0);
    free(sub_string);
}


static void pruebas_split() {

    char **splitted;

    print_test("La salida no es NULL", (splitted = split(joined_example, ',')) != NULL);

    bool separado = true;
    for (size_t i = 0; splitted[i] != NULL; i++)
        separado &= strcmp(splitted[i], splitted_example[i]) == 0;

    print_test("El string se separo correctamente", separado);

    free_strv(splitted);
}

static void pruebas_join() {
    char *joined;
    print_test("El llamado a la funcion no dio NULL", (joined = join(splitted_example, ',')) != NULL);
    printf("%s\n", joined);
    print_test("Une correctamente los strings por ','", strcmp(joined, joined_example) == 0);
    free(joined);

    char *joineado;
    joineado = join(null_joined_example, '\0');
    print_test("Ok", strcmp(joineado, "holacomoestas") == 0);
    free(joineado);

    char *joinea2;
    joinea2 = join(zero_elements, ',');
    print_test("Ok", strcmp(joinea2, "") == 0);
    free(joinea2);
}

void pruebas_strutil() {
    pruebas_substr();
    pruebas_split();
    pruebas_join();
}

int main(void) {
    pruebas_strutil();
    return 0;  // Indica si falló alguna prueba.
}