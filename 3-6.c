#include <stdio.h>
#include <string.h>
#include <limits.h>
#define LIM	100

/* overflow at -INT_MIN (2's complement) */

void itoa(int n, char s[], int width);
void reverse(char s[]);

int main()
{
	char s[LIM];
	itoa(INT_MIN, s, 20);
	printf("%s", s);
	return 0;
}

void itoa(int n, char s[], int width)
{
	int i, sign;

	if ((sign = n) < 0)
		switch (n) {
			case INT_MIN: 
				n = INT_MAX;
				break;
			default:
				n = -n;
				break;
		}
	i = 0;
	do {
		s[i++] = n % 10 + '0';
	} while ((n /= 10) > 0);
	if (sign < 0)
		s[i++] = '-';
	do {
		s[i++] = ' ';
	} while (i < width);
	s[i] = '\0';
	reverse(s);
}

void reverse(char s[])
{
	int c, i, j;

	for (i = 0, j = strlen(s)-1; i < j; i++, j--)
		c = s[i], s[i] = s[j], s[j] = c;
}
