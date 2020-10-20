#include <stdio.h>
#define MAXLINE	1000

void strCat(char *s, char *t);

int main()
{
	int c, i = 0;
	char s[MAXLINE];
	char t[] = "END";

	while ((c=getchar())!=EOF)
		s[i++] = c;
	s[i] = '\0';
	strCat(s, t);
	printf("%s\n", s);
	return 0;
}

void strCat(char *s, char *t)
{
	while (*++s != '\0');
	while ((*s++ = *t++) != '\0');
}

