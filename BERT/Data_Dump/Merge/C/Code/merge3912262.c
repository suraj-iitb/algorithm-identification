#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int cnt = 0;

void merge(int A[], int left, int mid, int right) {
	int i, j, k;
	int n1 = mid - left;
	int n2 = right - mid;

	int* L = malloc(sizeof(int) * (n1 + 1));
	int* R = malloc(sizeof(int) * (n2 + 1));
	for (i = 0; i < n1; i++) {
		L[i] = A[left + i];
	}
	for (i = 0; i < n2; i++) {
		R[i] = A[mid + i];
	}
	L[n1] = INT_MAX;
	R[n2] = INT_MAX;

	i = 0;
	j = 0;
	for (k = left; k < right; k++) {
		cnt++;
		if (L[i] <= R[j]) {
			A[k] = L[i];
			i++;
		}
		else {
			A[k] = R[j];
			j++;
		}
	}
	free(L);
	free(R);
}

void mergeSort(int A[], int left, int right) {
	if (left + 1 < right) {
		int mid = (left + right) / 2;
		mergeSort(A, left, mid);
		mergeSort(A, mid, right);
		merge(A, left, mid, right);
	}
}

int main() {
	int i, n;
	int* S;

	scanf("%d", &n);
	S = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++) {
		scanf("%d", &S[i]);
	}

	mergeSort(S, 0, n);
	for (i = 0; i < n; i++) {
		printf("%d", S[i]);
		if (i != n - 1) {
			printf(" ");
		}
		else {
			printf("\n");
		}
	}
	printf("%d\n", cnt);

	return 0;
}
