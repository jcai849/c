#include <stdio.h>
#include <ctype.h>

#define SIZE	20

int getch(void);
void ungetch(int);
int getint(int *);

int main()
{
	int n, array[SIZE];

	for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
		;
	while (n-- > 0)
		printf("%d\n", array[n]);
	return 0;
}

int getint(int *pn)
{
	int c, d, sign;

	while (isspace(c = getch()))
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-') {
		c = getch();
		if (!isdigit(c)) {
			ungetch(c);
			return EOF;
		}
	}
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	return c;
}

#define BUFSIZE 100
int buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
