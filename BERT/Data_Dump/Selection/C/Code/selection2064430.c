#include <stdio.h>

int selectionSort(int A[], int N) {
	int i, j, t, minj, sw = 0;

	for (i = 0; i < N - 1; i++) {
		minj = i;
		for (j = i; j < N; j++) {
			if (A[j] < A[minj]) {
				minj = j;
			}
		}
		t = A[minj]; A[minj] = A[i]; A[i] = t;
		if (i != minj) {
			sw++;
		}
	}
	return sw;
}

int main() {
	int A[100];
	int N, i, sw;

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	sw = selectionSort(A, N);

	for (i = 0; i < N; i++) {
		if (i > 0) printf(" ");
		printf("%d", A[i]);
	}
	printf("\n");
	printf("%d\n", sw);

	return 0;
}
