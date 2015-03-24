// author: Guchan Alkan
// date: 2015.02.24

#include <stdio.h>
#include <time.h>
#include <math.h>
#include <limits.h>

int main()
{
	clock_t begin, end;
	double elapsed;

	begin = clock();
	int primes[10000];

	int primeCounter = 0;

	for (int i = 2; i < INT_MAX; ++i)
	{
		int isPrime = 1;
		for (int j = 0; j < primeCounter; ++j)
		{
			if (i % primes[j] == 0)
				isPrime = 0;
		}

		if (isPrime)
		{
			primes[primeCounter] = i;
			++primeCounter;
			if (primeCounter == 10001)
			{
				printf("%d\n", i);
				break;
			}
		}
	}

	end = clock();
	elapsed = (double)(end - begin) / CLOCKS_PER_SEC;

	// printf("%d in %f", difference, elapsed);
}