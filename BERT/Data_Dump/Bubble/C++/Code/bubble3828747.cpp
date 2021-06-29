#include<stdio.h>

int sum = 0;
void bubbleSort(int A[], int n)
{
	int i,j;
	int t;
	for (i = 0; i < n; i++)
	{
		for(j=n-1;j>=i+1;j--)
			if (A[j] < A[j - 1])
			{
				sum++;
				t = A[j];
				A[j] = A[j - 1];
				A[j-1] = t;
			}
	}
}
int main()
{
	int i, n, A[100];

	scanf("%d",&n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
	}
	bubbleSort(A,n);
	printf("%d", A[0]);

	for (i = 1; i < n; i++)
	{
		printf(" %d", A[i]);
	}
	printf("\n");
	printf("%d\n",sum);

	return 0;
}
