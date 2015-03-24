// author: Guchan Alkan
// date: 2015.02.22

#include <stdio.h>
#include <time.h>

int isPrime(long number)
{
	int isPrime = 1;

	for (long i = 2; i < number; i++)
	{
		if (number % i == 0)
		{
			isPrime = 0;
			break;
		}
	}

	return isPrime;
}

int main()
{
	clock_t begin, end;
	double elapsed;

	begin = clock();

	long limit = 600851475143;
	for (long i = 2; i <= limit; ++i)
	{
		if (limit % i == 0)
		{
			printf("%ld is prime: %d\n", limit / i, isPrime(limit / i));
			limit = limit / i;
			i = 2;
		}
	}

	end = clock();
	elapsed = (double)(end - begin) / CLOCKS_PER_SEC;

	printf("\n%f", elapsed);
}