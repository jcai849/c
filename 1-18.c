#include <stdio.h>
#define MAXLINE	1000
#define RM_EMPTY_LINES 1

int takeline(char line[], int maxline);
void removetrail(char s[], int len, int rmemptylines);

int main()
{
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;
	while ((len = takeline(line, MAXLINE)) > 0)
	{
		removetrail(line, len, RM_EMPTY_LINES);
		printf("%s", line);
	}
	return 0;
}

int takeline(char s[], int lim)
{
	int c, i;

	for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	/* --v--continue counting after limit reached --v-- */
	while (i>=lim-1 && c!=EOF && c!='\n'){
		c=getchar();
		++i;
	}
	return i;
}

void removetrail(char s[], int len, int rmemptylines)
{			
	int i;     
		
	for (i=len-1; i>0 && (s[i]=='\t' || s[i]==' ' || s[i]=='\n'); --i){}
	s[i+1] =  '\n';
	s[i+2] =  '\0';
	if (rmemptylines && i == 0)	/* blank line */
		s[0] = '\0';
}
