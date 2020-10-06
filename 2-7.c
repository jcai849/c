#include <stdio.h>
#include <limits.h>

void printbits(unsigned x);
unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, unsigned y);
unsigned invert(unsigned x, int p, int n);

int main()
{
	unsigned x = 111111111;
	int p = 31;
	int n = 31;

	printbits(x);
	putchar('\n');
	printbits(setbits(0, p, n, ~0));
	putchar('\n');
	printbits(invert(x, p, n));
	putchar('\n');
	return 0;
}

void printbits(unsigned x)
{
	int i;
	for (i = CHAR_BIT * sizeof(typeof(x)) -1; i >= 0; --i)
		printf("%d", (x >> i) & 1);
}

/* getbits: get n bits from position p (position 0 at right end) */
unsigned getbits(unsigned x, int p, int n)
{
	return (x >> (p-n+1)) & ~(~0 << n);
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
	/* pull x right then left, burn last y bits into last of x, then pull x
	 * left and burn in the remainder of x into the fresh bit field */
	return (((x >> p+1) << n) | (y & ~(~0 << n)) << p+1-n) | 
		(x & ~(~0 << p+1-n));

}

unsigned invert(unsigned x, int p, int n)
{
	return setbits(x, p, n, 0) | (setbits(0, p, n, ~0) & ~x);
}
