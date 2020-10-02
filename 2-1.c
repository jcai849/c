#include <stdio.h>
#include <limits.h>

/* ranges of char, short, int, long, signed & unsigned */

int main()
{
	printf("unsigned char range: %d - %u\n", 0, UCHAR_MAX);
	printf("signed char range: %d - %d\n", SCHAR_MIN, SCHAR_MAX);
	printf("short range: %d - %d\n", SHRT_MIN, SHRT_MAX);
	printf("unsigned short range: %d - %u\n", 0, USHRT_MAX);
	printf("int range: %d - %d\n", INT_MIN, INT_MAX);
	printf("unsigned int range: %d - %u\n", 0, UINT_MAX);
	/* The following don't look right; probably due to long/int issues */
	printf("long range: %d - %d\n", LONG_MIN, LONG_MAX);
	printf("unsigned long range: %d - %u\n", 0, ULONG_MAX);

}
