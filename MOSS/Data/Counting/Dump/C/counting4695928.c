#include <stdio.h>
#include <stdlib.h>

void counting_sort(int A[], int B[], int k,int n)
{
	int C[10001];

	int i;

	for (i = 0; i <= k; i++)
		C[i] = 0;

	for (i = 0; i < n; i++)
		C[A[i]]++;

	for (i = 0; i < k; i++)
		C[i + 1] += C[i];

	for (i = n - 1; i >= 0; i--)
		B[--C[A[i]]] = A[i];
}

int main()
{
	int n;
	int A[2000000];
	int B[2000000];

	scanf("%d", &n);

	int i;

	for (i = 0; i < n; i++)
		scanf("%d", &A[i]);

	counting_sort(A, B, 10000,n);

	for (i = 0; i < n-1; i++)
		printf("%d ", B[i]);
	printf("%d\n", B[n - 1]);

	return 0;
}
