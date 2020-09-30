#include <stdio.h>

#define N	8	/* tab column space */

void putws(int nspaces, int replace);

int main()
{
	int c, nspaces;
	int l;		/* line position */
	int state;

	nspaces = 0;
	for (l = 0; (c=getchar())!=EOF && l>=0; ++l) {
		if ((l % N) == N-1) { /* at tab column */
			putws(nspaces, 1);
			nspaces = 0;
		} else if (c == ' ')
			nspaces += 1;
		if (c != ' ') {
			putws(nspaces, 0);
			nspaces = 0;
			putchar(c);
		}
		if (c == '\n')
			l = -1;
	}
}

void putws(int nspaces, int replace)
{
	if (!replace)
		for (nspaces; nspaces > 0; --nspaces)
			putchar(' ');
	else if (nspaces > 0) putchar('\t');
}
