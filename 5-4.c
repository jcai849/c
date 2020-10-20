#include <stdio.h>
#define MAXLINE	1000

int strend(char *s, char *t);

int main()
{
	int c, i=0;
	char s[MAXLINE];
	char t[] = "END";

	while ((c=getchar())!=EOF)
		s[i++] = c;
	s[i] = '\0';
	printf("%d\n", strend(s, t));
	return 0;
}

int strend(char *s, char *t)
{
	char *tbegin = t;

	while (*++s != '\0') ;
	while (*++t != '\0') ;
	while (t > tbegin) {
		if (*--s != *--t)
			return 0;
	}
	return 1;
}
