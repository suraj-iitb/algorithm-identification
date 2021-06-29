#include<stdio.h>
int bubbleSort(int A[], int N)
{
	int flag = 1;
	int j, i, t = 0;
	int index;
	for(i = 0; flag; i++)
	{
		flag = 0;
		for(j = N - 1; j > i; j--)
		{
			if(A[j] < A[j - 1])
			{
				index = A[j];
				A[j] = A[j - 1];
				A[j - 1] = index;
				flag = 1;
				t++;
			}
		}
	}
	return t;
}
int main(void)
{
	int N, i, t;
	int A[100];
	 
	scanf("%d", &N);
	for( i = 0; i < N; i++) scanf("%d",&A[i]);
	 
	t = bubbleSort(A, N);

	for( i = 0; i < N; i++ )
	{
		if( i ) printf(" ");
		printf("%d",A[i]);
	}
	printf("\n");
	printf("%d\n",t);
	 
	return 0;
}

