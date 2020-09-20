#include <stdio.h>

#define VII_BIT	128

/* print histogram of frequencies of different (ascii) character counts */

main()
{
	int c, i, lyr;
	int ch[VII_BIT];

	for (i = 0; i < VII_BIT; ++i)
		ch[i] = 0;

	while ((c = getchar()) != EOF) {
		++ch[c];
	}

	for (i = 0; i < VII_BIT; ++i) 
		if (ch[i] > 0) {
			printf("  ");
			putchar(i);
		}
	printf("\n");
	for (i = 0; i < VII_BIT; ++i) 
		if (ch[i] > 0) 
			printf("%3d", ch[i]);
	printf("\n");
}
