LDLIBS := -lm
LDFLAGS := -g
CFLAGS := -g -std=c11 -Wall -Wconversion -Wtype-limits -pedantic -Werror

all: main

clean:
	rm -f -- *.o main

rebuild: clean all

.PHONY: all clean rebuild

include deps.mk