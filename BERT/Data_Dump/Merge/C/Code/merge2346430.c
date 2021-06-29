#include <stdio.h>
#include <math.h>

#define N 500000

int cnt = 0;

void merge(int *A, int left, int mid, int right) {
	int i, j, k;
	int n1 = mid - left;
	int n2 = right - mid;
	int L[n1], R[n2];


	for (i = 0; i < n1; i++) {
		L[i] = A[left+i];
	}

	for (i = 0; i < n2; i++) {
		R[i] = A[mid+i];
	}

	L[n1] = INFINITY;
	R[n2] = INFINITY;
	i = 0;
	j = 0;
	for (k = left; k < right; k++) {
		if (L[i] <= R[j]) {
			A[k] = L[i];
			i++;
			cnt++;
		} else {
			A[k] = R[j];
			j++;
			cnt++;
		}
	}
}

void mergeSort(int *A, int left, int right) {
	int mid;

	if (left+1 < right) {
		mid = (left + right)/2;
		mergeSort(A, left, mid);
		mergeSort(A, mid, right);
		merge(A, left, mid, right);
	}
}

int main() {
	int i, n;
	int S[N];

	scanf("%d", &n);

	for (i = 0; i < n; i++)
		scanf("%d", &S[i]);

	mergeSort(S ,0, n);

	for (i = 0; i < n; i++) {
		printf("%d", S[i]);
		if (i < n-1) printf(" ");
	}
	printf("\n%d\n", cnt);

	return 0;
}
