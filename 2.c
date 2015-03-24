// author: Guchan Alkan
// date: 2015.02.21

#include <stdio.h>
#include <time.h>

int main()
{
	clock_t begin, end;
	double elapsed;

	begin = clock();

	int prev = 0;
	int next = 1;
	int sumOfEvens = 0;

	while (next < 4000000)
	{
		next = next + prev;
		prev = next - prev;

		if (next % 2 == 0)
			sumOfEvens += next;
	}

	end = clock();
	elapsed = (double)(end - begin) / CLOCKS_PER_SEC;

	printf("%d in %f", sumOfEvens, elapsed);
}