// author: Guchan Alkan
// date: 2015.03.07

#include <stdio.h>
#include <time.h>

int findDivisorCount(unsigned long long a)
{
	if (a == 0)
		return -1;
	else if (a == 1)
		return 1;

	int divisorCount = 1;
	int divisor = 2;
	int currentDivisorCount = 0;

	while (a != 1)
	{
		if (a % divisor == 0)
		{
			a = a / divisor;
			++currentDivisorCount;
		}
		else
		{
			++divisor;
			divisorCount *= (currentDivisorCount + 1);
			currentDivisorCount = 0;
		}
	}
	divisorCount *= (currentDivisorCount + 1);

	return divisorCount;
}

int main()
{
	clock_t begin, end;
	double elapsed;

	begin = clock();
	
	unsigned long long traingularNumber = 0;
	for (int i = 1; i <= 1000000000; i++)
	{
		traingularNumber += i;
		if (findDivisorCount(traingularNumber) > 500)
		{
			printf("%llu %d\n", traingularNumber, findDivisorCount(traingularNumber));
			break;
		}
	}

	end = clock();
	elapsed = (double)(end - begin) / CLOCKS_PER_SEC;

	printf("%llu in %f", result, elapsed);
}