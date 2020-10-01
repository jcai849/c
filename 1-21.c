#include <stdio.h>

#define N	8	/* tab column space */

void putws(int nspaces, int entab);

int main()
{
	int c, nspaces;
	int lpos;		/* line position */

	nspaces = 0;
	for (lpos=1; (c=getchar())!=EOF; ++lpos) {
		if (c != ' ') {
			putws(nspaces, 0);
			nspaces = 0;
			putchar(c);
		} else {
			nspaces += 1;
			if ((lpos % N) == 0) { /* at a tab column */
				putws(nspaces, 1);
				nspaces = 0;
			} 
		}
		if (c == '\n')
			lpos = 0;
	}
}

void putws(int nspaces, int entab)
{
	if (!entab || nspaces == 1)
		for (nspaces; nspaces > 0; --nspaces)
			putchar(' ');
	else if (nspaces > 0) putchar('\t');
}
