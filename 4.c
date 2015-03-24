// author: Guchan Alkan
// date: 2015.02.22

#include <stdio.h>
#include <time.h>
#include <math.h>
#include <limits.h>

int isPalindrome(int number);
int findDigitValue(int number, int digit);
int findDigitCount(int number);

int isPalindrome(int number)
{
	int isPalindrome = 1;

	int digitCount = findDigitCount(number);
	if (digitCount == 2)
	{
		isPalindrome = findDigitValue(number, 1) == findDigitValue(number, 2);
	}
	else
	{
		for (int i = 1; i <= (int)ceil((double)digitCount / 2); ++i)
		{
			// printf("%d %d\n", findDigitValue(number, i), findDigitValue(number, digitCount + 1 - i));
			if (findDigitValue(number, i) != findDigitValue(number, digitCount + 1 - i))
			{
				isPalindrome = 0;
				break;
			}
		}
	}

	return isPalindrome;
}

int findDigitValue(int number, int digit)
{
	if (digit == 0 || number < 1)
		return -1;
	else if (digit == 1)
		return number % 10;
	else
	{
		int a = number / pow(10, digit - 1);
		a = a % 10;

		return a;
	}
}

int findDigitCount(int number)
{
	for (int i = 0; i < INT_MAX; ++i)
	{
		if (number < pow(10, i))
		{
			return i;
		}
	}

	return -1;
}

int main()
{
	clock_t begin, end;
	double elapsed;

	begin = clock();

	int biggestPalindrome = 0;

	for (int i = 999; i > 99; --i)
	{
		for (int j = i; j > 99; --j)
		{
			if (isPalindrome(i * j) && (i * j) > biggestPalindrome)
				biggestPalindrome = i * j;

				// printf("%d * %d = %d isPalindrome: %d\n", i, j, i * j, isPalindrome(i * j));
		}
	}

	end = clock();
	elapsed = (double)(end - begin) / CLOCKS_PER_SEC;

	printf("%d in %f", biggestPalindrome, elapsed);
}