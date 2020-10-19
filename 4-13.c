#include <stdio.h>
#include <string.h>

void reverse(char s[]);

int main()
{
	char s[] = "1234";
	printf("%s\n", s);
	reverse(s);
	printf("%s\n", s);
	reverse(s);
	printf("%s\n", s);

	char t[] = "12345";
	printf("%s\n", t);
	reverse(t);
	printf("%s\n", t);
	reverse(t);
	printf("%s\n", t);
}

void reverse(char s[]) 
{
	static int low;
	int high;

	int len = strlen(s) - 1;

	if (low < len/2) {
		high = s[len-low];
		s[len - low] = s[low];
		s[low] = high;
		low++;
		reverse(s);
	}
	else 
		low = 0;
}
