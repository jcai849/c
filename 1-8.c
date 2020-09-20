#include <stdio.h>

main()
{
	int c;
	int b, t, l;

	b = t = l = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\b')
			++b;
		if (c == '\t')
			++t;
		if (c == '\n')
			++l;
	}
	printf("%d %d %d\n", b, t, l);
}
