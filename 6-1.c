#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
#define NKEYS (sizeof keytab / sizeof keytab[0])

struct key {
	char *word;
	int count;
} keytab[] = {
	{ "auto", 0 },
	{ "break", 0 },
	{ "case", 0 },
	{ "char", 0 },
	{ "const", 0 },
	{ "continue", 0 },
	{ "default", 0 },
	{ "#define", 0 },
	/* ... */
	{ "unsigned", 0 },
	{ "void", 0 },
	{ "volatile", 0 },
	{ "while", 0 }
};

int gettoken(char *, int);
int binsearch(char *, struct key *, int);
int isvalid(char firstletter);
int getch(void);
void ungetch(int c);

/* count C keywords */
int main()
{
	int n;
	char word[MAXWORD];

	while (gettoken(word, MAXWORD) != EOF)
		if ((n = binsearch(word, keytab, NKEYS)) >= 0)
			keytab[n].count++;
	for (n = 0; n < NKEYS; n++)
		if (keytab[n].count > 0)
			printf("%4d %s\n",
					keytab[n].count, keytab[n].word);
	return 0;
}

int binsearch(char *word, struct key tab[], int n)
{
	int cond;
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low+high) / 2;
		if ((cond = strcmp(word, tab[mid].word)) < 0)
			high = mid - 1;
		else if (cond > 0)
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}

int gettoken(char *word, int lim)
{
	int c;
	char *w = word;

	while (isspace(c = getch()))
		;
	if (c != EOF)
		*w++ = c;
	switch (c) {
		case '\'':
			*w++ = '\'';
			while ((c = getch()) != '\'') ;
			break;
		case '#':
			*w++ = '#';
			while (!isspace(c = getch())) ;
			break;
		case '/':
			if ((c = getch()) == '*') {
				*w++ = '/';
				*w++ = '*';
				while ((c = getch()) != EOF) 
					if (c == '*') {
						if ((c = getch()) == '/')
							break;
						else ungetch(c);
					}
				break;
			} else ungetch(c);
		default:
			for ( ; 
					--lim > 0 && !isspace(*w = getch()) && 
					*w != ';' && 
					*w  != '(' &&
					*w != '[';
					w++)
				;
	}
	if (!isalpha(c)) {
		*w = '\0';
		return word[0];
	}
	for ( ; --lim > 0; w++)
		if (!isalnum(*w = getch())) {
			ungetch(*w);
			break;
		}
	*w = '\0';
	return word[0];
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
