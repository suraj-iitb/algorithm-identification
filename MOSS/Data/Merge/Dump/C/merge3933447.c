#include<stdio.h>

#define INF 0x7fffffff

int cnt = 0;
int L[500011 / 2], R[500011 / 2];

void merge(int A[], int left, int mid, int right)
{
	int n1, n2;
	n1 = mid - left;
	n2 = right - mid;
	for (int i = 0; i < n1; i++)
		L[i] = A[left + i];
	for (int i = 0; i < n2; i++)
		R[i] = A[mid + i];
	L[n1] = R[n2] = INF;

	for (int k = left, i = 0, j = 0; k < right; k++)
	{
		if (L[i] <= R[j])
			A[k] = L[i++];
		else
			A[k] = R[j++];
		cnt++;
	}
}

void mergeSort(int A[], int left, int right)
{
	if (left + 1 < right)
	{
		int mid = (left + right) / 2;
		mergeSort(A, left, mid);
		mergeSort(A, mid, right);
		merge(A, left, mid, right);
	}
}

int main()
{
	int A[500011];
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	mergeSort(A, 0, n);
	for (int i = 0; i < n; i++)
	{
		if (i)
			printf(" ");
		printf("%d", A[i]);
	}
	printf("\n%d\n", cnt);
}
