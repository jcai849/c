#include <stdio.h>
#include <limits.h>

void printbits(unsigned x);
int bitcount(int x);
int krbitcount(int x);

int main()
{
	signed x = 111111111;
	int n = 5;

	printbits(x);
	putchar('\n');
	printf("%d", bitcount(x));
	putchar('\n');
	printf("%d", krbitcount(x));
	putchar('\n');
	return 0;
}

int krbitcount(int x)
{
	int b;

	for (b = 0; x != 0; x >>= 1)
		if (x & 01)
			b++;
	return b;

}

int bitcount(int x)
{
	int b;

	for (b = 0; x != 0; ++b)
		x &= x-1;
	return b;

}

void printbits(unsigned x)
{
	int i;
	for (i = CHAR_BIT * sizeof(typeof(x)) -1; i >= 0; --i)
		printf("%d", (x >> i) & 1);
}
