#include <stdio.h>

#define n	8	/* 8 col tab-stops */

void tabtospace(int lineloc);

int main()
{
	int c;
	int lineloc;

	lineloc = 0;
	while ((c=getchar())!=EOF) {
		if (c == '\n')
			lineloc = -1;
		if (c != '\t') {
			putchar(c);
			lineloc += 1;
		} else {
			tabtospace(lineloc);
			lineloc += n;
		}
	}
}

void tabtospace(int lineloc)
{
	int i;

	for (i=n-(lineloc%n); i>0; --i)
		putchar(' ');
}
