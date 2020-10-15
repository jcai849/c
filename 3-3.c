#include <stdio.h>
#define LIM	100

void expand(char s1[], char s2[]);
int nextdash(char s[], int prevdash);
int fill(char from, char to, int at, char tofill[]);
int ischarordigit(char c);

int main()
{
	int i = 0;
	int c;
	char s1[LIM], s2[LIM];

	while ((c=getchar())!=EOF)
		s1[i++] = c;
	s1[i] = '\0';
	expand(s1, s2);

	printf("%s", s2);
	return 0;
}

void expand(char s1[], char s2[])
{
	int i = 0;
	int j = 0;

	while ((i=nextdash(s1, i))!=-1) {
		j = fill(s1[i-1], s1[i+1], j, s2);
	}
	s2[j] = '\0';
}

int nextdash(char s[], int prevdash)
{
	int i;

	for (i=++prevdash; s[i] != '\0'; ++i){
		if (s[i]=='-' && 
			ischarordigit(s[i-1]) && 
			ischarordigit(s[i+1]))
			return i;
	}
	return -1;
}

int fill(char from, char to, int at, char tofill[])
{
	char c;

	for (c = from; c <= to; c++, at++)
		tofill[at] = c;
	return at;
}

int ischarordigit(char c)
{
	return (c >= '0' && c <= '9') ||
		(c >= 'A' && c <= 'Z') ||
		(c >= 'a' && c <= 'z');

}
