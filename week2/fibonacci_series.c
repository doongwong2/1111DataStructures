#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

long long int fibonacci(long long int n);

int main()
{
	long long int months;
	scanf("%lld", &months);
	printf("%lld", fibonacci(months));

	return 0;
}

long long int fibonacci(long long int n)
{
	long long int previous2num = 0;
	long long int previousnum = 0;
	long long int currentnum = 1;

	for (int i = 1; i < n; i++)
	{
		previous2num = previousnum;
		previousnum = currentnum;
		currentnum = previous2num + previousnum;
	}
	return currentnum;
}
