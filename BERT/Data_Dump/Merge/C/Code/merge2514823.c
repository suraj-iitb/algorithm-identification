#include<stdio.h>
#define MAX 500000
#define SENTINEL 2000000000
int L[MAX/2 + 2], R[MAX/2 +2];
int count = 0;

void merge(int A[], int left, int mid, int right)
{
	int i, j, k;
	int n1 = mid - left;
	int n2 = right - mid;
	for(i = 0; i < n1; i++)
		L[i] = A[left+i];
	for(i = 0; i < n2; i++)
		R[i] = A[mid+i];
	L[n1] = SENTINEL;
	R[n2] = SENTINEL;
	i = 0;
	j = 0;
	for(k = left; k < right; k++) {
		count++;
		if(L[i] <= R[j]) {
			A[k] = L[i++];
		}
		else {
			A[k] = R[j++];
		}
	}
}

void mergeSort(int A[], int left, int right)
{	
	if(left + 1 < right) {
		int mid = (left + right) / 2;
		mergeSort(A, left, mid);
		mergeSort(A, mid, right);
		merge(A, left, mid, right);
	}
}
int main()
{	
	int A[MAX];
	int i, n;

	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &A[i]);

	mergeSort(A, 0, n);

	for(i = 0; i < n; i++) {
		if(i == n-1)
			printf("%d\n", A[i]);
		else
			printf("%d ", A[i]);
	}

	printf("%d\n", count);
    return 0;
}
