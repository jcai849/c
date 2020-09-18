objects := $(addsuffix .o,$(basename $(wildcard *.c)))
.PHONY: all

all: $(objects)

%.o: %.c
	gcc -o $@ $<
