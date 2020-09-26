#include <stdio.h>
#define MAXLINE	80
#define MAXREAD	1000

int takeline(char line[], int start, int maxline);
int clear(char s[], int len);

int main()
{
	int len;
	char line[MAXREAD];

	while ((len=takeline(line, 0, MAXLINE+2)) > 0) { /* +2 to account for 1 
							 more than MAXLINE + a '\0' */
		if (len > MAXLINE && line[MAXLINE]!='\n') {
			takeline(line, len, MAXREAD);
			printf("%s", line);
		}
		clear(line, MAXLINE+2);
	}
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

int clear(char s[], int len)
{
	int i;

	for (i=0; i<len; ++i)
		s[i] = '\0';
}

