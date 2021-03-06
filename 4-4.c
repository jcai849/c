#include <stdio.h>
#include <stdlib.h>

#define MAXOP	100	/* max size of operand or operator */
#define NUMBER	'0'	/* signal that a number was found */
#define COMM	1
#define EXPR	0

int getop(char[]);
void push(double);
double pop(void);
void print(void);
void duplicate(void);
void swap(void);
void clear(void);

/* reverse Polish calculator 
 * P: print top
 * D: duplicate top
 * S: swap top two elements
 * C: clear stack */
int main()
{
	int type, state;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch (type) {
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

	head = pop();
	if (sp > 0) {
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

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char s[])
{
	int i, c, d;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.' || c == '-' || c == '+') {
		if (c == '-' || c == '+') {
			d = getch(); /* peek at the next char */
			ungetch(d);
			if (!isdigit(d) && d != '.') { /* NaN? */
				return c; 
			}
		} else return c;
	}
	i = 0;
	if (isdigit(c) || c == '-' || c == '+')	/* collect integer part */
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')		/* collect fraction part */
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}

#define BUFSIZE	100

char buf[BUFSIZE];	/* buffer for ungetch */
int bufp = 0;		/* next free position in buf */

int getch(void) /*get a (possibly pushed back) character */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
