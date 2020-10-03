#include <stdio.h>
#define LIM	10

int htoi(char s[]);

int main()
{
	char s[LIM];
	int i, c;

	for (i=0; i <= LIM-1 && (c=getchar()) != EOF && c != '\n'; ++i) {
		s[i] = c;
	}
	s[i] = '\0';
	printf("%d\n", htoi(s));
	return 0;
}

int htoi(char s[])
{
	int i, lower;
	int n = 0;

	for (i = 0; s[i] != '\0'; ++i) {
		if ((i == 0 && s[i] == '0') || /* ignore leading '0x' */
			(i == 1 && (s[i] == 'X' || s[i] == 'x'))) {
			continue;}
		else if (s[i] >= '0' && s[i] <= '9')
			lower = '0';
		else if (s[i] >= 'A' && s[i] <= 'F')
			lower = 'A';
		else if (s[i] >= 'a' && s[i] <= 'f')
			lower = 'a';
		else return 1;
		n = 16 * n + (s[i] - lower);
	}
	return n;
}
