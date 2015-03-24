// author: Guchan Alkan
// date: 2015.02.23

#include <stdio.h>
#include <time.h>
#include <math.h>

int main()
{
	clock_t begin, end;
	double elapsed;

	begin = clock();

	int sumOfSquares = 0;
	for (int i = 1; i <= 100; ++i)
	{
		sumOfSquares += pow(i, 2);
	}

	int squareOfSums = 0;
	for (int i = 1; i <= 100; ++i)
	{
		squareOfSums += i;
	}
	squareOfSums = pow(squareOfSums, 2);

	int difference = squareOfSums - sumOfSquares;

	end = clock();
	elapsed = (double)(end - begin) / CLOCKS_PER_SEC;

	printf("%d in %f", difference, elapsed);
}