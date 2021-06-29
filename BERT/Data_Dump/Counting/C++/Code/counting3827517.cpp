
#include<stdio.h>

#define MAX  10001

int C[MAX] = {0};

void countSort(int A[], int B[], int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		C[A[i]] += 1;
	}
	for (i = 1; i < MAX; i++)
	{
		C[i] += C[i - 1];
	}
	for (i = n - 1; i >= 0; i--)
	{
		B[C[A[i]]] = A[i];
		C[A[i]]--;
	}
}

int main()
{
	int A[2000005], B[2000005];
	int n,i;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &A[0] + i);
	}

	countSort(A,B,n);

	printf("%d", B[1]);

	for (i = 2; i <= n; i++)
	{
		printf(" %d", B[i]);
	}
	printf("\n");
    
	return 0;
}
