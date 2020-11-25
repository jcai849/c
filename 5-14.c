#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000
#define MAXLEN 1000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void Qsort(void *lineptr[], int left, int right,
		int (*comp)(void *, void *));
int numcmp(char *, char *);
int rnumcmp(char *, char *);
int strCmp(char *s, char *t);
int rstrCmp(char *s, char *t);

int main(int argc, char *argv[])
{
	int nlines, c;
	int numeric = 0, reverse = 0;

	while (argc-- > 1 && (*++argv)[0] == '-')
		while ((c = *++argv[0]))
			switch (c) {
				case 'n':
					numeric = 1;
					break;
				case 'r':
					reverse = 1;
					break;
				default:
					printf("5-14: illegal option %c\n", c);
					return 1;
			}
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		Qsort((void **) lineptr, 0, nlines-1,
				(int (*)(void*,void*))(numeric ? 
					(reverse ? rnumcmp : numcmp) : 
					(reverse ? rstrCmp : strCmp)));
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("input too big to sort\n");
		return 1;
	}
}

void Qsort(void *v[], int left, int right,
		int (*comp)(void *, void *))
{
	int i, last;
	void swap(void *v[], int, int);

	if (left >= right)
		return;
	swap(v, left, (left + right)/2);
	last = left;
	for (i = left+1; i <= right; i++)
		if ((comp)(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	Qsort(v, left, last-1, comp);
	Qsort(v, last+1, right, comp);
}

int numcmp(char *s1, char *s2)
{
	double v1, v2;

	v1 = atof(s1);
	v2 = atof(s2);
	if (v1 < v2)
		return -1;
	else if (v1 > v2)
		return 1;
	else
		return 0;
}

int rnumcmp(char *s1, char *s2)
{
	return -numcmp(s1, s2);
}

int rstrCmp(char *s1, char *s2)
{
	return -strCmp(s1, s2);
}

int strCmp(char *s, char *t)
{
	for ( ; *s == *t; s++, t++)
		if (*s == '\0')
			return 0;
	return *s - *t;
}

void swap(void *v[], int i, int j)
{
	void *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

int getLine(char *, int);
char *alloc(int);

int readlines(char *lineptr[], int maxlines)
{
	int len, nlines;
	char *p, line[MAXLEN];

	nlines = 0;
	while ((len = getLine(line, MAXLEN)) > 0)
		if (nlines >= maxlines || (p = alloc(len)) == NULL)
			return -1;
		else {
			line[len-1] = '\0';
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	return nlines;
}

void writelines(char *lineptr[], int nlines)
{
	while (nlines-- > 0)
		printf("%s\n", *lineptr++);
}

#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n)
{
	if (allocbuf + ALLOCSIZE - allocp >= n) {
		allocp += n;
		return allocp - n;
	} else
		return 0;
}

int getLine(char *line, int max)
{
	if (fgets(line, max, stdin) == NULL)
		return 0;
	else
		return strlen(line);
}
