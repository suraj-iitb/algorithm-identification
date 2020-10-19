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

void bubbleSort(int A[], int N,int *count)
{
	int flag = 0;
	int i, j,tmp;

	for (i = 0; i < N; i++)
	{
		for (j = N - 1; j > 0; j--)
		{
			if (A[j - 1] > A[j])
			{
				tmp = A[j - 1];
				A[j - 1] = A[j];
				A[j] = tmp;
				flag = 1;
				(*count)++;
			}
		}
		if (flag == 0)
			break;
		else
			flag = 0;
	}
}

int main()
{
	int A[10000];
	int N, i;

	int count = 0;

	scanf("%d", &N);

	for (i = 0; i < N; i++)
		scanf("%d", &A[i]);

	//print(A, N);

	bubbleSort(A, N,&count);

	print(A, N);

	printf("%d\n", count);

	return 0;
}