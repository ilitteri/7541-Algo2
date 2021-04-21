LDLIBS := -lm
LDFLAGS := -g
CFLAGS := -g -std=c11 -Wall -Wconversion -Wtype-limits -pedantic -Werror

all: infix dc

clean:
	rm -f -- *.o infix dc

rebuild: clean all

.PHONY: all clean rebuild

include deps.mk