#include <stdio.h>
#include "calc.h"
#define MAXVAL	100	/* maximum depth of val stack */

int sp = 0;		/* next free stack position */
double val[MAXVAL];	/* value stack */

/* push: push f onto value stack */
void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

void print(void)
{
	double head;
	int presp;

	presp = sp;
	head = pop();
	if (presp > 0) {
		printf("\t%.8g\n", head);
		push(head);
	}
}

void duplicate(void)
{
	double head;

	head = pop();
	if (sp > 0) {
		push(head);
		push(head);
	}
}

void swap(void)
{
	double head, neck;

	head = pop();
	neck = pop();
	if (sp > 0) {
		push(head);
		push(neck);
	}
}

void clear(void)
{
	sp = 0;
}

double vars[26];

void assign(double val, char var)
{
	vars[var - 'a'] = val;
}

void get(char var)
{
	push(vars[var - 'a']);
}
