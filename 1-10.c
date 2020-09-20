#include <stdio.h>

#define B_SLASH	92
#define B_LWR	98
#define T_LWR	116

main()
{
	int c;

	while ((c = getchar()) != EOF) {
		if (c == '\b') {
			putchar(B_SLASH);
			putchar(B_LWR);
		} else if (c == '\t') {
			putchar(B_SLASH);
			putchar(T_LWR);
		} else if (c == '\\') {
			putchar(B_SLASH);
			putchar(B_SLASH);
		} else
			putchar(c);
	}
}
