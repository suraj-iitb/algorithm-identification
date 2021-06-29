#include <stdio.h>

int main(void)
{
	int A[100], i, j, k, l, N, v;
	
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	for (l = 0; l < N; l++) {
		if (l < N - 1) {
				printf("%d ", A[l]);
		} else {
				printf("%d\n", A[l]);
		}
	}
	for (i = 1; i < N; i++) {
		v = A[i];
		for (j = 0; j < i; j++) {
			if (A[j] > A[i]) {
				for (k = i - 1; k >= j; k--) {
					A[k + 1] = A[k];
				}
				A[j] = v;
			}
		}
		for (l = 0; l < N; l++) {
			if (l < N - 1) {
				printf("%d ", A[l]);
			} else {
				printf("%d\n", A[l]);
			}
		}
	}
	return 0;
}
