#include <stdio.h>

#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)

int bubbleSort(int *A, int n)
{
	int c, f, i, j;

	c = 0;
	for (i = 0, f = 1; f; i++)
	{
		f = 0;
		for (j = n - 1; j >= i + 1; j--)
		{
			if (A[j] < A[j - 1])
			{
				swap(int, A[j], A[j - 1]);
				f = 1;
				c++;
			}
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

	c = bubbleSort(A, n);

	for (i = 0; i < n; i++) {
		printf("%d", A[i]);
		if (i < n - 1) printf(" ");
	}
	printf("\n");

	printf("%d\n", c);

	return 0;
}
