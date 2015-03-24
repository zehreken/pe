// author: Guchan Alkan
// date: 2015.02.25

#include <stdio.h>
#include <time.h>
#include <math.h>

int main()
{
	clock_t begin, end;
	double elapsed;

	begin = clock();

	long result;
	int n = 1000;
	for (int a = 1; a <= n - 2; ++a)
	{
		for (int b = 1; b <= n - a - 1; ++b)
		{
			int c = n - a - b;
			if (pow(a, 2) + pow(b, 2) == pow(c, 2))
				result = a * b * c;
		}
	}

	end = clock();
	elapsed = (double)(end - begin) / CLOCKS_PER_SEC;

	printf("%ld in %f", result, elapsed);
}