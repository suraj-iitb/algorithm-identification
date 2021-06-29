#include <stdio.h>
#include <iostream>

using namespace std;

void selectprint(int A[], int N, int replace)
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
	printf("%d", replace);
	printf("\r\n");
}

void bubbleSort(int A[], int N)
{
	int min;
	int replace = 0;


	for (int i = 0; i < N; i++)
	{
		min = i;
		for (int j = i; j < N; j++)
		{
			if (A[min] > A[j]) 
			{
				min = j;

			}
		}
		if (min != i) 
		{
			swap(A[min], A[i]);
			replace++;
		}
	}
	selectprint(A,N,replace);
}

int main()
{
	int N, A[100];

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &A[i]);
	}
	bubbleSort(A, N);

	return 0;
}

