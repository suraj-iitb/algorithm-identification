#include<stdio.h>

int selectionSort(int A[], int N)
{
	int i, j, minj, t, sw = 0;
	for (i = 0; i < N - 1; i++)
	{
		minj = i;
		for (j = i + 1; j <= N - 1; j++)
		{
			if (A[minj] > A[j])
				minj = j;
		}
		t = A[minj];
		A[minj] = A[i];
		A[i] = t;
		if (i != minj)
			sw += 1;
	}
	return sw;
}

int main()
{
	int sw, N,i;
	int A[100];

	scanf("%d",&N);

	for (i = 0; i < N; i++)
		scanf("%d", &A[i]);

	sw=selectionSort(A,N);

	printf("%d", A[0]);
	for (i = 1; i < N; i++)
	{
		printf(" %d", A[i]);
	}
	printf("\n");
	printf("%d\n", sw);

	return 0;
}
