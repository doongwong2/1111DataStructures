#include <stdio.h>

int main()
{
	int a, b;

	while (scanf("%d %d", &a, &b) != EOF)
	{
		printf("%d+%d=%d\n", a, b, a + b);
		printf("%d*%d=%d\n", a, b, a * b);
		printf("%d-%d=%d\n", a, b, a - b);

		if (a % b > 0)
			printf("%d/%d=%d...%d", a, b, a / b, a % b);
		else
			printf("%d/%d=%d", a, b, a / b);
	}

	return 0;
}
