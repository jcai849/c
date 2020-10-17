objects := $(addsuffix .o,$(basename $(wildcard *.c)))
.PHONY: all clean

all: $(objects)

%.o: %.c
	gcc -o $@ $< -lm

clean:
	rm *.o
