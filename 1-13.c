#include <stdio.h>

#define IN		1	/* inside a word */
#define OUT		0	/* outside a word */
#define MAXLENGTH	20	/* max word length */

/* print histogram of word lengths */

main()
{
	int c, i, j, cwl, state, lyr;
	int wl[MAXLENGTH];

	state = OUT;
	for (i = 0; i < MAXLENGTH; ++i)
		wl[i] = 0;
	cwl = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			state = OUT;
			if (cwl > 0)
				++wl[cwl-1];
			cwl = 0;
		} else if (state == OUT) 
			state = IN;
		
		if (state == IN && cwl < MAXLENGTH) 
			++cwl;
	}

	for (i = 1; i < MAXLENGTH; ++i) 
		printf("%3d", i);
	printf("%2d+\n", MAXLENGTH);
	for (i = 0; i < MAXLENGTH; ++i)
		printf("%3d", wl[i]);
	printf("\n");
	for (i = 0; i < MAXLENGTH*3; ++i)
		printf("-");
	printf("\n");

	lyr = 0;
	for (i = 0; i < MAXLENGTH; ++i)
		if (wl[i] > lyr)
			lyr = wl[i];
	while (lyr > 0) {
		for (j = 0; j < MAXLENGTH; ++j) {
			if (wl[j] == lyr) {
				printf("  #");
				--wl[j];
			} else 
				printf("   ");
		}
		printf("\n");
		--lyr;
	}
	for (i = 1; i < MAXLENGTH; ++i) 
		printf("%3d", i);
	printf("%2d+\n", MAXLENGTH);
}
