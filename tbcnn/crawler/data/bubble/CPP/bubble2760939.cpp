#include <stdio.h>
#include <iostream>

using namespace std;

void bubbleprint(int A[], int N,int replace)
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
	int flg = 1;
	int replace=0;

	while (flg)
	{
		flg = 0;
		for (int i = N-1; i>0; i--)
		{
			if (A[i] < A[i - 1]) 
			{
				swap(A[i],A[i - 1]);
				replace++;
				flg = 1;
			}
		}
	}

	bubbleprint(A,N,replace);
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
