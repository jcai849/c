#include <stdio.h>
#define LIM 100

int any(char s1[], const char s2[]);

int main()
{
	int i, c;
	char s1[LIM];
	const char s2[] = "aeiouyAEIOUY";

	for (i=0; (c=getchar())!=EOF; ++i)
		s1[i] = c;
	s1[i] = '\0';
	printf("%d", any(s1, s2));
	return 0;
}

int any(char s1[], const char s2[])
{
	int i, j;

	for (i=0; s1[i] != '\0'; ++i) 
		for (j=0; s2[j] != '\0'; ++j)
			if (s1[i] == s2[j])
				return i;
	return -1;
}
