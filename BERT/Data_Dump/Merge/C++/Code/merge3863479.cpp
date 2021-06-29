#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <math.h>

int count;
int R[250001], L[250001], S[500001];

void merge(int A[], size_t left, size_t mid, size_t right) {
	size_t n1 = mid - left;
	size_t n2 = right - mid;
	for (int i = 0; i < n1; i++) {
		R[i] = A[left + i];
	}
	for (int i = 0; i < n2; i++) {
		L[i] = A[mid + i];
	}
	R[n1] = 1000000001;
	L[n2] = 1000000001;
	int i = 0, j = 0;
	for (int k = left; k < right; k++) {
		if (R[i] < L[j]) {
			A[k] = R[i++];
		}
		else {
			A[k] = L[j++];
		}
		count++;
	}
}

void merge_sort(int A[], size_t left, size_t right) {

	if (left + 1 < right) {
		size_t mid = (left + right) / 2;
		merge_sort(A, left, mid);
		merge_sort(A, mid, right);
		merge(A, left, mid, right);
	}
}

int main() {
	count = 0;

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", S + i);
	}
	merge_sort(S, 0, n);

	for (int i = 0; i < n; i++) {
		if (i != 0)printf(" ");
		printf("%d", S[i]);
	}
	printf("\n");
	printf("%d\n", count);
	return 0;
}
