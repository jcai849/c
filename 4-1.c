#include <stdio.h>
#define MAXLINE 1000

int getLine(char line[], int max);
int strindex(char source[], char searchfor[]);
int strrindex(char s[], char t[]);

char pattern[] = "ould";

int main()
{
	char line[MAXLINE];
	int found = 0;
	int i;

	while (getLine(line, MAXLINE) > 0) {
		i = strrindex(line, pattern);
		printf("%d: %s", i, line);
		found++;
	}
	return found;
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

int strindex(char s[], char t[])
{
	int i, j, k;

	for (i = 0; s[i] != '\0'; i++) {
		for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			return i;
	}
	return -1;
}

int strrindex(char s[], char t[])
{
	int i, j, k, l;
	l = -1;

	for (i = 0; s[i] != '\0'; i++) {
		for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			l = i;
	}
	return l;
}
