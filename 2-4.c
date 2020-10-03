#include <stdio.h>
#define LIM	100

void squeeze(char s1[], const char s2[]);
int in(int s, const char s2[]);

int main()
{
	int i, c;
	char s1[LIM];
	const char s2[] = "AEIOUYaeiouy";

	for (i=0; i<LIM && (c=getchar())!=EOF; ++i)
		s1[i] = c;
	s1[i] = '\0';
	squeeze(s1, s2);
	printf("%s", s1);
	return 0;
}

void squeeze(char s1[], const char s2[])
{
	int i, j;

	for (i = j = 0; s1[i] != '\0'; ++i) 
		if (!in(s1[i], s2))
			s1[j++] = s1[i];
	s1[j] = '\0';
}

int in(int s, const char s2[])
{
	int i;

	for (i = 0; s2[i] != '\0'; ++i)
		if (s == s2[i]) {
			return 1;
		}
	return 0;
}
