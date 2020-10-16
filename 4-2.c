#include <stdio.h>
#include <ctype.h>

#define MAXLINE 100

/* rudimentary calculator */
int main()
{
	double sum, atof(char []);
	char line[MAXLINE];
	int getLine(char line[], int max);

	sum = 0;
	while (getLine(line, MAXLINE) > 0)
		printf("\t%g\n", sum += atof(line));
	return 0;
}

int getLine(char s[], int lim)
{
	int c, i;

	i = 0;
	while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

double atof(char s[])
{
	double val, power, exp, expval;
	int i, sign, expneg;

	for (i=0; isspace(s[i]); i++)
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++) 
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}

	switch(s[i++]) {
		case 'e': case 'E':
			expneg = (s[i] == '-') ? 1 : 0;
			if (s[i] == '+' || s[i] == '-')
				i++;
			for (expval = 0.0; isdigit(s[i]); i++) {
				expval =  10.0 * expval + (s[i] - '0');
			}
			for (exp = 1; expval > 0; expval--)
				exp *= 10;
			if (expneg)
				exp = 1 / exp;
			break;
	}
	printf("sign: %g\n", sign);
	printf("val: %g\n", val);
	printf("power: %g\n", power);
	printf("expval: %g\n", expval);
	printf("exp: %g\n", exp);
	return sign * val / power * exp;
}
