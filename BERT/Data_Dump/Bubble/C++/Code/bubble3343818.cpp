#include<stdio.h>
int count = 0;
void Traverse(int A[], int N)
{
	for(int i = 0; i < N; i++)
	{
		if(i > 0)
			printf(" ");
		printf("%d", A[i]);
	}
	putchar('\n'); 	
}
void BubbleSort(int A[], int N)
{
	int flag = 1;
	while(flag)
	{
		flag = 0;
		for(int j = N-1; j >= 1; j--)
		{
			if(A[j] < A[j-1])
			{
				int tmp = A[j-1];
				A[j-1] = A[j];
				A[j] = tmp;
				flag = 1;
				count++;
			}
		}
	}
}
int main()
{
	int N;
	int A[100];
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%d", &A[i]);
	BubbleSort(A, N);
	Traverse(A, N);
	printf("%d\n", count);
}

