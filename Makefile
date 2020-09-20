objects := $(addsuffix .o,$(basename $(wildcard *.c)))
.PHONY: all clean

all: $(objects)

%.o: %.c
	gcc -ggdb -o $@ $<

clean:
	rm *.o
