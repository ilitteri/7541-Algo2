#include "testing.h"

#include <stdio.h>
#include <stdlib.h>

void pruebas_heap_catedra(void);
void pruebas_heap_estudiante(void);
void pruebas_heap_volumen_catedra(size_t, bool);

/* ******************************************************************
 *                        PROGRAMA PRINCIPAL
 * *****************************************************************/

#ifndef CORRECTOR //COMENTAR PARA PROBAR
int main(int argc, char *argv[]) {
    if (argc > 1) { //COMENTAR PARA PROBAR
        // Asumimos que nos están pidiendo pruebas de volumen.
        long largo = strtol(argv[1], NULL, 10); //COMENTAR PARA PROBAR
        pruebas_heap_volumen_catedra((size_t) largo, false); //COMENTAR PARA PROBAR
        return 0; //COMENTAR PARA PROBAR
    } //COMENTAR PARA PROBAR
    printf("~~~ PRUEBAS ESTUDIANTE ~~~\n");
    pruebas_heap_estudiante();
    printf("\n~~~ PRUEBAS CÁTEDRA ~~~\n"); //COMENTAR PARA PROBAR
    pruebas_heap_catedra(); //COMENTAR PARA PROBAR

    return failure_count() > 0;
}
#endif //COMENTAR PARA PROBAR
