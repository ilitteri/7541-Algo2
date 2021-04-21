cc -g -O2 -std=gnu18 -Wall -pedantic -Wformat=2 -Wshadow -Wpointer-arith -Wunreachable-code -Wconversion -Wno-sign-conversion -Wbad-function-cast --coverage -Werror -DTDA=pila   -c -o testing.o testing.c
cc -g -O2 -std=gnu18 -Wall -pedantic -Wformat=2 -Wshadow -Wpointer-arith -Wunreachable-code -Wconversion -Wno-sign-conversion -Wbad-function-cast --coverage -Werror -DTDA=pila   -c -o pila.o pila.c
cc -g -O2 -std=gnu18 -Wall -pedantic -Wformat=2 -Wshadow -Wpointer-arith -Wunreachable-code -Wconversion -Wno-sign-conversion -Wbad-function-cast --coverage -Werror -DTDA=pila   -c -o pruebas_pila.o pruebas_pila.c
cc -g -O2 -std=gnu18 -Wall -pedantic -Wformat=2 -Wshadow -Wpointer-arith -Wunreachable-code -Wconversion -Wno-sign-conversion -Wbad-function-cast --coverage -Werror -DTDA=pila    testing.o pila.o pruebas_pila.o -o pruebas_alu
./pruebas_alu

gcovr -r . -f 'pila.c'
gcovr -r . -f 'pila.c' --branches -s
