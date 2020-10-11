#include <stdio.h>

#define N 500000
#define SENTINEL 1e9

int cnt;

void merge(int* A, int left, int mid, int right) {
	int n1 = mid - left;
	int n2 = right - mid;
	int L[N], R[N];
	int i, j, k;

	for (i = 0; i <= n1 - 1; i++)
		L[i] = A[left + i];
	for (i = 0; i <= n2 - 1; i++)
		R[i] = A[mid + i];

	L[n1] = R[n2] = SENTINEL;
	i = j = 0;

	for (k = left; k <= right - 1; k++) {
		if (L[i] <= R[j]) {
			A[k] = L[i];
			i++;
		} else {
			A[k] = R[j];
			j++;
		}
	}
	cnt += (i + j);
}

void mergeSort(int* A, int left, int right) {
	int mid;

	if (left + 1 < right) {
		mid = (left + right) / 2;
		mergeSort(A, left, mid);
		mergeSort(A, mid, right);
		merge(A, left, mid, right);
	}

}

int main() {
	int i, n, S[N];

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &S[i]);

	mergeSort(S, 0, n);

	for (i = 0; i < n; i++) {
		printf("%d", S[i]);
		if (i < n - 1)
			printf(" ");
	}
	printf("\n%d\n", cnt);

	return 0;
}
