#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>
#define MAX 100

typedef struct {
	double coef;
	int degree;
}polynomial;

void addPolynomials(int start_a, int end_a, int start_b, int end_b, int start_ans, int end_ans, polynomial terms[]);

int main() {
	polynomial terms[MAX];
	int terms_a;
	int terms_b;

	scanf("%d", &terms_a);
	for (int i = 0; i < terms_a; i++)
	{
		scanf("%lf %d", &terms[i].coef, &terms[i].degree);
	}

	scanf("%d", &terms_b);
	for (int i = terms_a; i < terms_a + terms_b; i++)
	{
		scanf("%lf %d", &terms[i].coef, &terms[i].degree);
	}

	addPolynomials(0, terms_a - 1, terms_a, terms_a + terms_b - 1, terms_a + terms_b, terms_a + terms_b, terms);

	return 0;
}

void addPolynomials(int start_a, int end_a, int start_b, int end_b, int start_ans, int end_ans, polynomial terms[])
{
	bool emptyFlag = true;
	int available = start_ans;
	int current_a = start_a;
	int current_b = start_b;

	while (current_a <= end_a && current_b <= end_b)
	{
		if (terms[current_a].degree == terms[current_b].degree)
		{
			terms[available].coef = terms[current_a].coef + terms[current_b].coef;
			terms[available].degree = terms[current_a].degree;
			current_a++;
			current_b++;
			available++;
			end_ans++;
		}
		else if (terms[current_a].degree > terms[current_b].degree)
		{
			terms[available].coef = terms[current_a].coef;
			terms[available].degree = terms[current_a].degree;
			current_a++;
			current_b++;
			available++;
			end_ans++;
		}
		else if (terms[current_a].degree < terms[current_b].degree)
		{
			terms[available].coef = terms[current_b].coef;
			terms[available].degree = terms[current_b].degree;
			current_b++;
			available++;
			end_ans++;
		}
	}

	for (int i = 0; i <= end_a; i++)
	{
		if (terms[i].coef == 0)
			;
		else
		{
			if (terms[i].degree > 1) printf("%.2fx^%d", terms[i].coef, terms[i].degree);
			else if (terms[i].degree == 1)printf("%.2fx", terms[i].coef);
			else if (terms[i].degree == 0)printf("%.2f", terms[i].coef);
		}

		if (terms[i + 1].coef > 0 && i < end_a)printf("+");
	}
	printf("\n");

	for (int i = end_a + 1; i <= end_b; i++)
	{
		if (terms[i].coef == 0)
			;
		else
		{
			if (terms[i].degree > 1) printf("%.2fx^%d", terms[i].coef, terms[i].degree);
			else if (terms[i].degree == 1)printf("%.2fx", terms[i].coef);
			else if (terms[i].degree == 0)printf("%.2f", terms[i].coef);
		}

		if (terms[i + 1].coef > 0 && i < end_b)printf("+");
	}
	printf("\n");

	for (int i = start_ans; i < end_ans; i++)
	{
		if (terms[i].coef == 0)
			;
		else
		{
			emptyFlag = false;
			if (terms[i].degree > 1) printf("%.2fx^%d", terms[i].coef, terms[i].degree);
			else if (terms[i].degree == 1)printf("%.2fx", terms[i].coef);
			else if (terms[i].degree == 0)printf("%.2f", terms[i].coef);
		}

		if (terms[i + 1].coef > 0 && i < end_ans - 1)printf("+");
	}

	if (emptyFlag == true) printf("0");

	return;
}