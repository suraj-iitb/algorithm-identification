#include <stdio.h>

#define Max 500000
#define INFTY 1000000000

void  swap(int *x, int *y)
{
    int  buff;
	
	buff = *x;
	*x = *y;  
	*y = buff;
}

void printA(int A[Max], int N) {
	int i;

	for (i = 0; i < N - 1; i++)
		printf("%d ", A[i]);
	printf("%d\n", A[N - 1]);
}

int merge(int A[Max], int left, int mid, int right) {
	int i, j, k;
	int count = 0;

	int n1 = mid - left;
	int n2 = right - mid;

	// L[0...n1], R[0...n2] ?????????
	int L [Max], R[Max];
	for (i = 0; i < n1; i++) L[i] = A[left + i];
	for (i = 0; i < n2; i++) R[i] = A[mid + i];

	L[n1] = INFTY;
	R[n2] = INFTY;
	i = 0;
	j = 0;

	for (k = left; k < right; k++) {
		count++;
		if (L[i] <= R[j])  A[k] = L[i++];
		else  A[k] = R[j++];
	}

	return count;
}

int mergeSort(int A[Max], int left, int right) {
	int count = 0;
	int mid;

	if (left + 1 < right) {
		mid = (left + right)/2;
		count += mergeSort(A, left, mid);
		count += mergeSort(A, mid, right);
		count += merge(A, left, mid, right);
	}

	return count;
}

int main( ) {
	int N, i, count;
	int A[Max];

	scanf("%d", &N);

	for (i = 0; i < N; i++) scanf("%d", &A[i]);

	count = mergeSort(A, 0, N);

	printA(A, N);

	printf("%d\n", count);

	return 0;
}
