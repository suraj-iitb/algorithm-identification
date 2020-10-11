#include <stdio.h>
#include <limits.h>

#define ARRAY_SIZE 500000
#define DIV_SIZE 250001

int A[ARRAY_SIZE];
int L[DIV_SIZE];
int R[DIV_SIZE];
int count;

void merge(int left, int mid, int right)
{
	int i, j, k, n1, n2;
	n1 = mid - left;
	n2 = right - mid;
	count += right - left;
	
	for (i = 0; i < n1; i++) L[i] = A[left + i];
	for (i = 0; i < n2; i++) R[i] = A[mid + i];

	L[n1] = R[n2] = INT_MAX;

	i = j = 0;
	for (k = left; k < right; k++)
	{
		if (L[i] <= R[j]) A[k] = L[i++];
		else A[k] = R[j++];
	}
}

void mergeSort(int left, int right)
{
	int mid;
	if (left + 1 >= right) return;

	mid = (left + right) / 2;
	mergeSort(left, mid);
	mergeSort(mid, right);
	merge(left, mid, right);
}

int main(void)
{
	int i, n;

	scanf("%d", &n);

	for (i = 0; i < n; i++) scanf("%d", &A[i]);

	count = 0;
	mergeSort(0, n);

	for (i = 0; i < n; i++)
	{
		printf("%d", A[i]);
		if ((i + 1) < n) printf(" ");
	}
	printf("\n%d\n", count);

	return 0;
}
