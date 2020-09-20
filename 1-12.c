#include <stdio.h>

#define IN	1	/* inside a word */
#define OUT	0	/* outside a word */
#define LF	10	/* new line */

/* print one word per line */

main()
{
	int c, state;

	state = IN;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else if (state == OUT) {
			putchar(LF);
			state = IN;
		}
		if (state == IN) 
			putchar(c);
	}
}
