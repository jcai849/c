objects = main.o stack.o getop.o getch.o

rpn: $(objects)
	cc -o rpn $(objects) -lm

$(objects): calc.h

.PHONY: clean
clean:
	-rm rpn $(objects)
