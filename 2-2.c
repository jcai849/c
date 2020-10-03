#include <stdio.h>

#define LIM	1000

int main()
{
	int i, c;
	char s[LIM];

	for (i=0; i<LIM-1; ++i)
		if ((c=getchar()) != '\n')
			if (c != EOF)
				s[i] = c;
	s[LIM] = '\0';
	printf("%s", s);

}
