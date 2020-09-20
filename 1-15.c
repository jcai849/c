#include <stdio.h>

/* print Fahrenheit-Celsius table
 * for fahr = 0, 20, ..., 300; floating-point version */

int f2c(int fahr);

main()
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;	/* lower limit of temperature table */
	upper = 300;	/* upper limit */
	step = 20;	/* step size */

	fahr = lower;
	printf("Fahrenheit-Celsius Conversion Table\n");
	while (fahr <= upper) {
		celsius = f2c(fahr);
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
}

int f2c(int fahr)
{
	return (5.0/9.0) * (fahr-32.0);
}
