#include <stdio.h>
#define MAXLINE	1000

void reverse(char s[], int lim);
int takeline(char s[], int start, int lim);

int main()
{
	char s[MAXLINE];
	int len;

	while ((len = takeline(s, 0, MAXLINE)) > 0) {
		reverse(s, len-1);
		printf("%s", s);
	}
}

void reverse(char s[], int lim)
{
	int i;
	char tmp[lim];

	for (i=lim; i>=0; --i)
		tmp[lim-i] = s[i];
	for (i=lim; i>=0; --i)
		s[i] = tmp[i];
}

int takeline(char s[], int start, int lim)
{
	int c, i;

	for (i=start; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}
