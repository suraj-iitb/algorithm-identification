#include <stdio.h>
#include <stdlib.h>

const int SENTINEL = 10000000000;
int L[500000/2+2];
int R[500000/2+2];
int n_comparison = 0;


void merge(int A[], int left, int mid, int right) {
	int n1 = mid - left;
	int n2 = right - mid;
//	int* L = (int*)malloc(sizeof(int) * (n1+1));
//	int* R = (int*)malloc(sizeof(int) * (n2 + 1));
	int i, j, k;

	for (i = 0; i < n1;i++) {
		L[i] = A[left + i];
	}
	for (i = 0; i < n2;i++) {
		R[i] = A[mid + i];
	}
	L[n1] = SENTINEL;
	R[n2] = SENTINEL;
	i = 0, j = 0;
	for (k = left;k < right; k++) {
		n_comparison++;
		if (L[i] <= R[j]) {
			A[k] = L[i];
			i++;
		}
		else {
			A[k] = R[j];
			j++;
		}
	}
//	free(L);
//	free(R);
}

void mergeSort(int A[], int left, int right) {
	int mid;
	if (left + 1 < right) {
		mid = (left + right) / 2;
		mergeSort(A, left, mid);
		mergeSort(A, mid, right);
		merge(A, left, mid, right);
	}
}

int main() {
	int n = 0;
	int* A;
	int i;

	scanf("%d",&n);
	A = (int*)malloc(n* sizeof(int));
	for (i = 0;i < n; ++i) {
		scanf("%d", &A[i]);
	}
	n_comparison = 0;
	mergeSort(A, 0, n);
	for (i = 0;i < n; ++i) {
		if (i > 0) { printf(" "); }
		printf("%d", A[i]);
	}
	printf("\n");
	printf("%d\n", n_comparison);
	free(A);
	return 0;
}
