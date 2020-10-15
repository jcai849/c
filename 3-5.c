#include <stdio.h>
#include <string.h>
#include <limits.h>
#define LIM	100

/* overflow at -INT_MIN (2's complement) */

void itob(int n, char s[], int b);
void reverse(char s[]);

int main()
{
	char s[LIM];
	itob(INT_MIN, s, 16);
	printf("%s", s);
	return 0;
}

void itob(int n, char s[], int b)
{
	int i, num, sign;

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
		num = n % b;
		if (num > 9)
			s[i++] = num - 10 + 'A';
		else
			s[i++] =  num + '0';
	} while ((n /= b) > 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}
void reverse(char s[])
{
	int c, i, j;

	for (i = 0, j = strlen(s)-1; i < j; i++, j--)
		c = s[i], s[i] = s[j], s[j] = c;
}
