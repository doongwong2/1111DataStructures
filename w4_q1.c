#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 10001

typedef struct
{
	int row;
	int col;
	int value;
}matrix;

void transpose(matrix a[], matrix b[]);

int main()
{
	matrix a[MAX];
	matrix b[MAX];

	scanf("%d %d %d", &a[0].row, &a[0].col, &a[0].value);

	for (int i = 1; i <= a[0].value; i++)
	{
		scanf("%d %d %d", &a[i].row, &a[i].col, &a[i].value);
	}
	
	transpose(a, b);

	for (int i = 0; i <= b[0].value; i++)
	{
		printf("%d %d %d\n", b[i].row, b[i].col, b[i].value);
	}

	return 0;
}

void transpose(matrix a[], matrix b[])
{
	int rowTerms[MAX], startingPos[MAX];
	int numCols = a[0].col;
	int numTerms = a[0].value;

	b[0].row = numCols;
	b[0].col = a[0].row;
	b[0].value = numTerms;

	if (numTerms > 0)
	{
		for (int i = 0; i < numCols; i++) rowTerms[i] = 0;
		for (int i = 1; i <= numTerms; i++) rowTerms[a[i].col]++;

		startingPos[0] = 1;

		for (int i = 1; i <= numCols; i++) startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];
		for (int i = 1; i <= numTerms; i++)
		{
			int j = startingPos[a[i].col]++;
			b[j].row = a[i].col;
			b[j].col = a[i].row;
			b[j].value = a[i].value;
		}
	}
	return;
}
