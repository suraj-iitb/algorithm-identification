#include<stdio.h>

void selectionSort(int A[], int N);

int main(void)
{
	int n=0, i=0;
	
	scanf("%d", &n);
	
	int a[n];
	
	for(i=0; i<n; i++)
	{
		scanf("%d", &a[i]);
	}

	selectionSort(a, n);
	
	return 0;
}

void selectionSort(int A[], int N)
{
	int i=0, j=0, minj=0, temp=0, c=0;
	
	for(i=0; i<N; i++)
	{
		minj = i;
		
		for(j=i; j<N; j++)
		{
			if(A[j] < A[minj])
			{
				minj = j;
			}
		}
		
		if(i != minj)
		{
			c++;
		}
		temp = A[i];
		A[i] = A[minj];
		A[minj] = temp;
	}
	
	for(i=0; i<N; i++)
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
	printf("\n%d\n", c);
}


