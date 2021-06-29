#include<stdio.h>

void insertionSort(int A[], int N);

int main(void)
{
	int n=0, i=0;
	
	scanf("%d", &n);
	
	int a[n];
	
	for(i=0; i<n; i++)
	{
		scanf("%d", &a[i]);
	}
	
	insertionSort(a, n);
	
	return 0;
}

void insertionSort(int A[], int N)
{
	int i=0, j=0, v=0, k=0;
	
	for(i=0; i<N; i++) //1行目
	{
		if(i<N-1)
		{
			printf("%d ", A[i]);
		}
		else
		{
			printf("%d", A[i]);
		}
	}
	
	printf("\n");
	
	for(i=1; i<=N-1; i++)
	{
		v = A[i];
		j = i-1;
		
		while(j>=0 && A[j]>v)
		{
			A[j+1] = A[j];
			j--;
		}
		
		A[j+1]=v;
		
		for(k=0; k<N; k++) //2～N行目
		{
			if(k<N-1)
			{
				printf("%d ", A[k]);
			}
			else
			{
				printf("%d", A[k]);
			}
		}
			printf("\n");

	}
}
