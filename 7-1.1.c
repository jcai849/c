#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int c;
	while ((c = getchar()) != EOF)
		putchar(strcmp(argv[0], "7-1.1") ? tolower(c) : toupper(c));
	return 0;
}
