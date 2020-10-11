#include <stdio.h>
int main(void) {
	int i, n, minj, j, A[1000], temp, count = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}
	for (i = 0; i < n; i++) {
		minj = i;

		for (j = i; j < n; j++) {
			if (A[j] < A[minj]) {
				minj = j;
			}
		}
		if (A[minj] == A[i]) {
			continue;
		} else {
			temp = A[i];
			A[i] = A[minj];
			A[minj] = temp;
			count++;
		}
	}
	for (i = 0; i < n - 1; i++) {
		printf("%d ", A[i]);
	}
	printf("%d\n", A[n - 1]);
	printf("%d\n", count);
	return 0;
}
