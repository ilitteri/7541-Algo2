#!/bin/bash

export LD_LIBRARY_PATH=/usr/local/lib/x86_64-linux-gnu
gcc *.c -o test -lcriterion -g -O2 -std=c99 -Wall -Wformat=2 -Wshadow -Wpointer-arith -Wunreachable-code -Wconversion -Wno-sign-conversion -Wbad-function-cast && ./test
