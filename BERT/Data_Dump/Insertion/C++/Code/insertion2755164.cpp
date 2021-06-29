#include <stdio.h>

void trace(int A[], int N) 
{
	for (int i = 0; i < N; i++)
	{
		if (i > 0)
		{
			printf(" ");
		}

		printf("%d", A[i]);
	}
	printf("\r\n");
}

void insertSort(int A[], int N)
{
	int v,j;
	for (int i = 1; i < N; i++)
	{
		v = A[i];
		j = i - 1;
		while (j >= 0 && A[j] > v) 
		{
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = v;
		trace(A, N);
	}
	
}

int main()
{
	int N, A[100];

	scanf("%d", &N);
	
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &A[i]);
	}
	trace(A , N);
	insertSort(A, N);

    return 0;
}