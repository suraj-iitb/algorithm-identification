#include<stdio.h>

void insertionsort(int A[], int n)
{
	int v, j;
	for(int i = 0; i < n; i++)
	{
		if(i < n-1)
		printf("%d ", A[i]);	
		else
		printf("%d", A[i]);
	}
	putchar('\n');
	for(int i = 1; i < n; i++)
	{
		v = A[i];
		j = i - 1;
		while(j >= 0 && A[j] > v)
		{
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = v;
	for(int i = 0; i < n; i++)
	{
		if(i < n-1)
		printf("%d ", A[i]);	
		else
		printf("%d", A[i]);
	}	
	putchar('\n');
	}
}
int main()
{
	int A[100];
	int n,x;
	scanf("%d", &x);	
	for(int i = 0; i < x; i++)
		scanf("%d", &A[i]);
	insertionsort(A, x);	
	return 0;
}
