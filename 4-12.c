#include <stdio.h>
#include <limits.h>
#define LIM	100

/* overflow at -INT_MIN (2's complement) */

int itoa(int n, char s[]);

int main()
{
	char s[LIM];
	itoa(122333, s);
	printf("\n%s\n", s);
	return 0;
}

int itoa(int n, char s[])
{
	static int i;

	if (i == 0 && n < 0) {
		s[i++] = '-';
		switch (n) {
			case INT_MIN: 
				n = INT_MAX;
				break;
			default:
				n = -n;
				break;
		}
	}
	if (n/10) {
		i = itoa(n/10, s);
		s[i] = n % 10 + '0';
	} else {
		s[i] = n % 10 + '0';
		s[++i] = '\0';
		i = 0;
	}
	return ++i;
}
