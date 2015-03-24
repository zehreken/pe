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

	int limit = 2000000;
	unsigned long long sumOfPrimes = 0;
	int primes[200000];
	int primeCounter = 0;

	for (int i = 2; i < limit; ++i)
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
			sumOfPrimes += i;
		}
	}

	end = clock();
	elapsed = (double)(end - begin) / CLOCKS_PER_SEC;

	printf("%llu in %f", sumOfPrimes, elapsed);
}