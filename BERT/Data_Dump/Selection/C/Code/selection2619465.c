#include <stdio.h>

#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)

int selectionSort(int *A, int n)
{
	int c, i, j, min;

	c = 0;
	for (i = 0; i < n - 1; i++)
	{
		min = i;
		for (j = i; j < n; j++)
		{
			if (A[j] < A[min])
			{
				min = j;
			}
		}
		if (i != min)
		{
			swap(int, A[i], A[min]);
			c++;
		}
	}
	
	return c;
}
int main()
{
	int c, i, n;
	int A[100];

	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &A[i]);

	c = selectionSort(A, n);

	for (i = 0; i < n; i++) {
		printf("%d", A[i]);
		if (i < n - 1) printf(" ");
	}
	printf("\n");

	printf("%d\n", c);

	return 0;
}
