// author: Guchan Alkan
// date: 2015.03.10

#include <stdio.h>
#include <time.h>

double factorial(int n)
{
	if (n == 0) return 1; // 0! = 1

	double result = n;
	for (int i = n - 1; i > 0; --i)
	{
		result = result * i;
	}

	return result;
}

unsigned long long binomialCoefficient(int n, int k)
{
	return factorial(n) / (factorial(k) * factorial(n - k));
}

void pascalTriangle(int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			printf("%llu ", binomialCoefficient(i, j));
		}
		printf("\n");
	}
}

int main()
{
	clock_t begin, end;
	double elapsed;

	begin = clock();

	unsigned long long result = binomialCoefficient(40, 20);

	end = clock();
	elapsed = (double)(end - begin) / CLOCKS_PER_SEC;

	printf("%llu in %f", result, elapsed);
}