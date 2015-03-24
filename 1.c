// author: Guchan Alkan
// date: 2015.02.20

#include <stdio.h>
#include <time.h>

int main ()
{
	clock_t begin, end;
	double elapsed;

	begin = clock();

	int sum = 0;

	for (int i = 0; i < 1000; ++i)
	{
		if (i % 3 == 0)
			sum += i;
		else if (i % 5 == 0)
			sum += i;
	}

	end = clock();
	elapsed = (double)(end - begin) / CLOCKS_PER_SEC;

	printf("%d in %f", sum, elapsed);
}