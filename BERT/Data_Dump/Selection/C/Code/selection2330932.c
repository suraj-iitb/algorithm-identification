#include <stdio.h>

int selectionsort(int A[],int N)
{
	int i,j,t,minj;
	int count = 0;
	
	for(i = 0; i < N - 1; i++)
	{
		minj = i;
		for(j = i; j < N; j++)
		{
			if(A[j] < A[minj])
			{
				minj = j;
			}
		}
		
		t = A[minj];
		A[minj] = A[i];
		A[i] = t;
		
		if(i != minj)
		{
			count++;
		}
	}
	return count;
}

int main(void)
{
	int A[100],N,count;
	int i;
	
	scanf("%d",&N);
	
	for(i = 0; i < N; i++)
	{
		scanf("%d",A + i);
	}
	
	count = selectionsort(A,N);
	
	for(i = 0; i < N; i++)
	{
		if(i > 0)
		{
			printf(" ");
		}
		
		printf("%d",A[i]);
	}
	printf("\n");
	
	printf("%d\n",count);
	
	return 0;
}
	
