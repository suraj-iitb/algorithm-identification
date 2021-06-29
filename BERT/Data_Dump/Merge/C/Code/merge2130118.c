#include <stdio.h>
#include <limits.h>

int S[500000];
int L[250001];
int R[250001];
int cnt = 0;

void merge(int A[], int left, int mid, int right) {
	int i, j, k, n1, n2;
	n1 = mid - left;
	n2 = right - mid;

	for (i = 0; i < n1; ++i) {
		L[i] = A[left + i];
	}

	for (i = 0; i < n2; ++i) {
		R[i] = A[mid + i];
	}

	L[n1] = INT_MAX;
	R[n2] = INT_MAX;

	i = j = 0;
	for (k = left; k < right; ++k) {
		++cnt;
		if (L[i] <= R[j]) {
			A[k] = L[i];
			++i;
		} else {
			A[k] = R[j];
			++j;
		}
	}
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
	
int main(void) {
	int n, i;
	
	scanf("%d", &n);

	for (i = 0; i < n; ++i) {
		scanf(" %d", &S[i]);
	}
	mergeSort(S, 0, n);

	for (i = 0; i < n; ++i) {
		if (i != n - 1) {
			printf("%d ", S[i]);
		} else {
			printf("%d\n", S[i]);
		}
	}
	printf("%d\n", cnt);
	
	return 0;
}
