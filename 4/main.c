#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calc.h"

#define MAXOP	100	/* max size of operand or operator */
#define COMM	1
#define EXPR	0

/* reverse Polish calculator 
 *
 * lower case single char varnames
 *
 * Commands
 * --------
 * P: print top
 * D: duplicate top
 * S: swap top two elements
 * C: clear stack 
 * A: assign
 * G: get
 * 
 * Math
 * ----
 * E: Exponent
 * I: Sin
 * O: Power
 * */
int main()
{
	int type, state;
	double val, var, op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch (type) {
			case 'a': case 'b': case 'c': case 'd':
			case 'e': case 'f': case 'g': case 'h':
			case 'i': case 'j': case 'k': case 'l':
			case 'm': case 'n': case 'o': case 'p':
			case 'q': case 'r': case 's': case 't':
			case 'u': case 'v': case 'w': case 'x':
			case 'y': case 'z': 
				state = EXPR;
				push(type);
				break;
			case 'A':
				state = COMM;
				var = pop();
				assign(val=pop(), var);
				push(val);
				break;
			case 'G':
				state = COMM;
				get(pop());
				break;
			case 'P':
				state = COMM;
				print();
				break;
			case 'D':
				state = COMM;
				duplicate();
				break;
			case 'S':
				state = COMM;
				swap();
				break;
			case 'C':
				state = COMM;
				clear();
				break;
			case 'E':
				state = EXPR;
				push(exp(pop()));
				break;
			case 'I':
				state = EXPR;
				push(sin(pop()));
				break;
			case 'O':
				state = EXPR;
				op2 = pop();
				push(pow(pop(), op2));
				break;
			case NUMBER:
				state = EXPR;
				push(atof(s));
				break;
			case '+':
				state = EXPR;
				push(pop() + pop());
				break;
			case '*':
				state = EXPR;
				push(pop() * pop());
				break;
			case '-':
				state = EXPR;
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				state = EXPR;
				op2 = pop();
				if (op2 != 0.0)
					push(pop() / op2);
				else
					printf("error: zero divisor\n");
				break;
			case '%':
				state = EXPR;
				op2 = pop();
				if (op2 != 0.0)
					push((int) pop() % (int) op2);
				else
					printf("error: zero divisor\n");
				break;
			case '\n':
				if (state == EXPR)
					printf("\t%.8g\n", pop());
				state = EXPR;
				break;
			default:
				printf("error: unknown command %s\n", s);
				break;
		}
	}
	return 0;
}
