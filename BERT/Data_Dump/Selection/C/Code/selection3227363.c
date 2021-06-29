#include <stdio.h>

int main()
{
	int n, i, j, temp, minj, count;
	int a[1000];

	count = 0;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);

	for (i = 0; i < n; i++)
	{
		minj = i;
		for (j = i + 1; j < n; j++)
		{
			if (a[j] < a[minj])
				minj = j;
		}

		if (minj != i)
			count++;

		temp = a[i];
		a[i] = a[minj];
		a[minj] = temp;
	}

	for (i = 0; i < n; i++)
	{
		printf("%d", a[i]);
		if (i != n - 1)
			putchar(' ');
	}
	putchar('\n');

	printf("%d\n", count);

	return 0;
}

