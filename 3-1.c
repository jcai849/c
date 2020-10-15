#include <stdio.h>
#include <string.h>

int binsearch(int x, int v[], int n);

int main()
{
	int x = 'e';
	int v[12];
	v[0] = ' ';
	v[1] = 'd';
	v[2] = 'e';
	v[3] = 'h';
	v[4] = 'l';
	v[5] = 'l';
	v[6] = 'l';
	v[7] = 'o';
	v[8] = 'o';
	v[9] = 'r';
	v[10] = 'w';
	printf("%d\n", binsearch(x, v, 12));
	return 0;
}

int binsearch(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high && x != v[mid]) {
		mid = (low+high) / 2;
		if (x < v[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	if (x == v[mid])
		return mid;
	return -1;
}
