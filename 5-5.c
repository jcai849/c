#include <stdio.h>
#include <string.h>
#define iprint(x)	printf(#x ": %d\n", x)
#define sprint(x)	printf(#x ": %s\n", x)

int strCmp(char *s, char *t);
void strCpy(char *s, char *t);
void strCat(char *s, char *t);

void strNCpy(char *s, char *ct, int n); /* copy at most n chars of string ct to
					   s; return s. Pad with '\0's if t has
					   fewer than n characters */
void strNCat(char *s, char *ct, int n); /* concat at most n characters of
					   string ct to string s, terminate s
					   with '\0'; return s */
int strNCmp(char *cs, char *ct, int n); /* compare at most n characters of
					   string cs to string ct; return <0 if
					   cs<ct, 0 if cs==ct, or >0 if cs>ct
					   */

int main()
{
	char s[] = "test test",
	     low[] = "AA",
	     high[] = "ZZ";
	char t[strlen(s)+2], u[strlen(s)+2];

	sprint(s);
	sprint(low);
	sprint(high);

	strNCpy(t, s, 9);
	printf("strNCpy(t, s, 9); t: %s\n", t);
	strNCpy(u, s, 9);
	printf("strNCpy(u, s, 9); u: %s\n", u);

	strNCat(t, low, 2);
	printf("strNCat(t, low, 2); t: %s\n", t);
	strNCat(u, high, 2);
	printf("strNCat(u, high, 2); u: %s\n", u);

	iprint(strNCmp(s, s, 9));
	iprint(strNCmp(t, s, 9));
	iprint(strNCmp(u, s, 9));
	iprint(strNCmp(t, u, 9));

	return 0;
}

void strCpy(char *s, char *t)
{
	while ((*s++ = *t++))
		;
}

void strNCpy(char *s, char *ct, int n)
{
	while ((*s++ = *ct++) && n > 0)
		n--;
}

void strCat(char *s, char *t)
{
	while (*++s != '\0');
	while ((*s++ = *t++) != '\0');
}

void strNCat(char *s, char *ct, int n)
{
	while (*++s != '\0');
	while ((*s++ = *ct++) != '\0' && n > 0)
		n--;
}

int strCmp(char *s, char *t)
{
	for ( ; *s == *t; s++, t++)
		if (*s == '\0')
			return 0;
	return *s - *t;
}

int strNCmp(char *cs, char *ct, int n)
{
	for ( ; *cs == *ct; cs++, ct++, n--)
		if (*cs == '\0' || n == 0)
			return 0;
	return *cs - *ct;
}
