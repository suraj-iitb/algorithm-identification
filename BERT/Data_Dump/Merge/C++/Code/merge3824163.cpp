#include<stdio.h>

int A[500005];
int L[250002],R[250002];
int sum;

void merge(int A[], int left, int mid, int right)
{
	int n1, n2,i,j;
	n1 = mid - left;
	n2 = right - mid;
	for ( i = 0; i < n1; i++)
	{
		L[i] = A[i + left];
	}
	
	for ( i = 0; i < n2; i++)
	{
		R[i] = A[i + mid];
	}
	L[n1] = 2100000000;
	R[n2] = 2100000000;
	i = j = 0;
	for (int k = left; k < right; k++)
	{
		if (L[i] <= R[j])
			A[k] = L[i++];
		else
			A[k] = R[j++];
	}
	sum += right - left;
}

void mergeSort(int A[], int left, int right)
{
	int mid;
	if (left + 1 < right)
	{
		mid = (left + right) / 2;
		mergeSort(A,left,mid);
		mergeSort(A, mid, right);
		merge(A, left, mid, right);
	}
}

int main()
{
	int n,i;

	scanf("%d", &n);
	for ( i = 0; i < n; i++)
	{
		scanf("%d", &A[0] + i);
	}
	mergeSort(A, 0, n);

	printf("%d",A[0]);

	for (i = 1; i < n; i++)
	{
		printf(" %d", A[i]);
	}
	printf("\n");

	printf("%d\n",sum);

	return 0;
}
