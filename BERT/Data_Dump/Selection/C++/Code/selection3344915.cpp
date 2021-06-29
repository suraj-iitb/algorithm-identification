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
void SelectionSort(int A[], int N)
{
	
	for(int i = 0; i < N-1; i++)
	{
		int min = i;
		for(int j = i+1 ; j < N; j++)
		{
			if(A[j] < A[min])
				min = j;
		}
		if(min != i)
		{
			int tmp = A[min];
			A[min] = A[i];
			A[i] = tmp;
			count++;
		}
	
	}
 } 
int main()
{
	int N, A[100];
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%d", &A[i]);
	SelectionSort(A, N); 
	Traverse(A, N);
	printf("%d\n", count);
}

