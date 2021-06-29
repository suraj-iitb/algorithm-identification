#include <stdio.h>

void trace(int A[], int N) {
	int i;
	for (i = 0; i < N; i++) {
		if (i > 0) printf(" ");
		printf("%d", A[i]);
	}
	printf("\n");
}

void InsertionSort(int A[], int N) {
	int i, j;
	int v;

	for (i = 1; i < N; i++) {
		v = A[i];
		j = i - 1;
		while (v < A[j] && j >= 0) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = v;
		trace(A, N);
	}
}

int main() {
	int N, i;
	int A[100];

	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	trace(A, N);
	InsertionSort(A, N);

	return 0;
}
