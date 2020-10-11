#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define ABS(x) ( (x)>0 ? x : -(x) )
#define MIN(x,y) ( (x) < (y) ? (x) : (y) )
#define MAX(x,y) ( (x) > (y) ? (x) : (y) )

#define MOD 1000000007

void swap(int* a, int* b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void print(int A[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d", A[i]);
		if (i != n - 1)
			printf(" ");
	}
	printf("\n");
}

void insertionSort(int A[], int N)
{
	int i, j,tmp;

	for (i = 1; i < N; i++)
	{
		j = i;
		while (j > 0 && A[j - 1] > A[j])
		{
			tmp = A[j - 1];
			A[j - 1] = A[j];
			A[j] = tmp;

			j--;
		}
		print(A, N);
	}
}

int main()
{
	int A[10000];
	int N, i;

	scanf("%d", &N);

	for (i = 0; i < N; i++)
		scanf("%d", &A[i]);

	print(A, N);

	insertionSort(A, N);

	return 0;
}
