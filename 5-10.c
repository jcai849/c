#include <stdlib.h>
#include <stdio.h>

#define MAXSTACK	1000

int main(int argc, char *argv[])
{
	char *op;
	int val[MAXSTACK];
	int *pval = val;
	int popped;

	while (--argc > 0) 
		switch(*(op=*++argv)) {
			case '+':
				*pval++ = *--pval + *--pval;
				break;
			case '*':
				*pval++ = *--pval * *--pval;
				break;
			case '-':
				popped = *--pval;
				*pval++ = *--pval - popped;
				break;
			case '/':
				popped = *--pval;
				*pval++ = *--pval / popped;
				break;
			default:
				*pval++ = atof(op);
				break;
		}
	printf("%d", *--pval);
}
