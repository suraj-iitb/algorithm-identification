#include <stdio.h>
#include <stdlib.h>

#define N 2000001
#define I 10000

int n;

void CountingSort(int *A, int *B) {
	int i, j;
	int C[I+1];

	for (i = 0; i <= I; i++) C[i] = 0;

	for (j = 1; j <= n; j++) {
		C[A[j]]++;
	}
	for (i = 1; i <= I; i++) {
		C[i] = C[i] + C[i-1];
	}
	for (j = n; j >= 1; j--) {
		B[C[A[j]]] = A[j];
		C[A[j]]--;
	}
}

int main () {
	int i;
	int *A, *B;

	scanf("%d", &n);

	A = (int *)malloc(sizeof(int) * n + 1);
	B = (int *)malloc(sizeof(int) * n + 1);

	for (i = 1; i <= n; i++) {
		scanf("%d", &A[i]);
	}

	CountingSort(A, B);

	for (i = 1; i < n; i++) {
		printf("%d ", B[i]);
	}
	printf("%d\n", B[i]);

	return 0;
}
