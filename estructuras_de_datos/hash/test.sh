cc -g -O2 -std=gnu18 -Wall -pedantic -Wformat=2 -Wshadow -Wpointer-arith -Wunreachable-code -Wconversion -Wno-sign-conversion -Wbad-function-cast --coverage -Werror -DTDA=hash   -c -o testing.o testing.c
cc -g -O2 -std=gnu18 -Wall -pedantic -Wformat=2 -Wshadow -Wpointer-arith -Wunreachable-code -Wconversion -Wno-sign-conversion -Wbad-function-cast --coverage -Werror -DTDA=hash   -c -o main.o main.c
cc -g -O2 -std=gnu18 -Wall -pedantic -Wformat=2 -Wshadow -Wpointer-arith -Wunreachable-code -Wconversion -Wno-sign-conversion -Wbad-function-cast --coverage -Werror -DTDA=hash   -c -o hash.o hash.c
cc -g -O2 -std=gnu18 -Wall -pedantic -Wformat=2 -Wshadow -Wpointer-arith -Wunreachable-code -Wconversion -Wno-sign-conversion -Wbad-function-cast --coverage -Werror -DTDA=hash   -c -o hash_pruebas.o hash_pruebas.c
cc -g -O2 -std=gnu18 -Wall -pedantic -Wformat=2 -Wshadow -Wpointer-arith -Wunreachable-code -Wconversion -Wno-sign-conversion -Wbad-function-cast -DCORRECTOR -DTDA=hash    testing.c main.c hash.c hash_pruebas.c -o pruebas_cat