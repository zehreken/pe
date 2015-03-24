// author: Guchan Alkan
// date: 2015.03.10

#include <stdio.h>
#include <time.h>

long findChainLength(long number, long acc)
{
	if (number == 1) return ++acc;

	if (number % 2 == 0)
	{
		number = number / 2;
	}
	else
	{
		number = 3 * number + 1;
	}

	return findChainLength(number, ++acc);
}

int main()
{
	clock_t begin, end;
	double elapsed;

	begin = clock();

	long maxChainLength = 0;
	long number;
	for (int i = 1; i < 1000000; ++i)
	{
		long temp = findChainLength(i, 0);
		if (temp > maxChainLength)
		{
			maxChainLength = temp;
			number = i;
		}
	}

	end = clock();
	elapsed = (double)(end - begin) / CLOCKS_PER_SEC;

	printf("%d in %f", number, elapsed);
}