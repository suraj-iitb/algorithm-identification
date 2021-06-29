#include<stdio.h>

void insertionSort(int A[],int N);
void Show(int A[],int N);

void insertionSort(int A[],int N)
{
	int i,j,key;
	for(i=1;i<=N-1;i++)
	{
		key=A[i];
		j=i-1;
		while(j>=0&&A[j]>key)
		{
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=key;
		Show(A,N);
	}
}

void Show(int A[],int N)
{
	int i;
	for(i=0;i<N-1;i++)
	{
		printf("%d ",A[i]);
	}
	printf("%d",A[i]);
	printf("\n");
}

int main()
{
	int N,A[200],i;
	scanf("%d",&N);
	for(i=0;i<N;i++)
	{
		scanf("%d",&A[i]);
	}
	Show(A,N);
	insertionSort(A,N);
	return 0;
} 
