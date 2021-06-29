#include <stdio.h>

void insertionSort(int *A, int N)
{
	int i, j, k, v;

	for (i = 0; i < N; i++) {
		v = A[i];
		j = i - 1;
		while (j >= 0 && A[j] > v) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = v;
		for (k = 0; k < N; k++) {
			printf(k != 0 ? " %d" : "%d", A[k]);
		}
		puts("");
	}
}


int main(void)
{
	int N, A[1000], i;

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	insertionSort(A, N);

	return 0;
}

