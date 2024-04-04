#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define MAX 101
#define COMPARE(x,y)((x)<(y))? -1:((x) == (y)) ?0 : 1)

int binSearch(int list[], int searchnum, int left, int right);

int main()
{
	int target, arrSize;
	int list[MAX];
	scanf("%d %d", &target, &arrSize);

	for (int i = 0; i < arrSize; i++)
	{
		scanf("%d", &list[i]);
	}

	printf("%d", binSearch(list, target, 0, arrSize - 1));

	return 0;
}

int binSearch(int list[], int searchnum, int left, int right)
{
	int middle;
	if (left <= right)
	{
		middle = (left + right) / 2;
		switch (COMPARE(list[middle], searchnum)
		{
			case -1:
				return binSearch(list, searchnum, middle + 1, right);

			case 0:
				return middle;

			case 1:
				return binSearch(list, searchnum, left, middle - 1);

		}
	}
	return -1;
}
