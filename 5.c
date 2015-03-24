// author: Guchan Alkan
// date: 2015.02.23

#include <stdio.h>
#include <time.h>

int findLeastCommonMultiple(int a, int b)
{
	if (a == b)
		return a;
	if (a > b)
	{
		int temp = a;
		a = b;
		b = temp;
	}

	int lowestMultiple = 1;
	int divisor = 2;
	while (a != 1 || b != 1)
	{
		if (a % divisor == 0 && b % divisor == 0)
		{
			a = a / divisor;
			b = b / divisor;
			lowestMultiple = lowestMultiple * divisor;
		}
		else if (a % divisor == 0)
		{
			a = a / divisor;
			lowestMultiple = lowestMultiple * divisor;
		}
		else if (b % divisor == 0)
		{
			b = b / divisor;
			lowestMultiple = lowestMultiple * divisor;
		}
		else
			++divisor;
	}

	return lowestMultiple;
}

int main()
{
	clock_t begin, end;
	double elapsed;

	begin = clock();

	int currentLowestMultiple = 1;
	for (int i = 1; i <= 20; ++i)
	{
		currentLowestMultiple = findLeastCommonMultiple(i, currentLowestMultiple);
	}

	end = clock();
	elapsed = (double)(end - begin) / CLOCKS_PER_SEC;

	printf("%d in %f", currentLowestMultiple, elapsed);
}