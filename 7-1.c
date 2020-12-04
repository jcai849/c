#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int c;
	while ((c = getchar()) != EOF)
		putchar(strcmp(argv[0], "lower") ? tolower(c) : toupper(c));
	return 0;
}
