CC = gcc
CFLAGS = -Wall -g
LDLIBS = -lm

.PHONY: clean

rpn: main
	mv main rpn

main: $(addsuffix .o, $(basename $(wildcard *.c)))

clean:
	$(RM) rpn *.o
