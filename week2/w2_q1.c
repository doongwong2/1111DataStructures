#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define MAX_SIZE 101
#define SWAP(x,y,t)((t) =(x),(x) = (y),(y) = (t))

void sort(int[], int);
void main(void)
{
	int i, n;
	int list[MAX_SIZE];
	scanf("%d", &n);

	for (i = 0; i < n; i++)
		scanf("%d", &list[i]);

	sort(list, n);
	for (i = 0; i < n; i++)
		printf("%d", list[i]);
	printf("\n");

	return 0;
}

void sort(int list[], int n)
{
	int i, j, min, temp;
	for (i = 0; i < n; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)
			if (list[j] < list[min])
				min = j;
		SWAP(list[i], list[min], temp);

	}
}
