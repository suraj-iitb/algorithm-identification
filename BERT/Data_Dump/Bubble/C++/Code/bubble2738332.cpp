#include<stdio.h>

static const int NMAX = 100;

void bubblesort(int A[], int N)
{
	int times = 0;
	int flag = 1;
	for(int i = 0 ; i < N && flag == 1; i++)
	{
		flag = 0;
		for(int j = 0 ; j < N - (i + 1) ; j++)
		{
			if(A[j] > A[j+1])
			{
				int temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
				flag = 1;
				times++;
			}	
		}
	}
	for(int i = 0 ; i < N ; i++)
	{
		if(i > 0)
		{
			printf(" ");
		}
		printf("%d", A[i]);
		if(i == N - 1)
		{
			printf("\n");
		}
	}
	printf("%d\n", times);
}

int main()
{
	int N = 0;
	int flag = 0;
	int A[NMAX] = {0};
	scanf("%d", &N);
	for(int i = 0 ; i < N ; i++)
	{
		scanf("%d", &A[i]);
	}
	bubblesort(A, N);
	return 0;
}
