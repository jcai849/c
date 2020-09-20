#include <stdio.h>

main()
{
	int c, nb;

	nb = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ')
			nb++;
		if (c != ' ')
			nb = 0;
		if (nb <= 1)
			putchar(c);
	}
}
