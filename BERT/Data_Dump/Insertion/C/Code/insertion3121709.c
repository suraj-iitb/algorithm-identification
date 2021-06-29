
#include <stdio.h>

int main() {
	int A[1000], n, j,v;
	for (int i = 0; i < 101; i++) {
		A[i] = 0;
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
			scanf("%d", &A[i]);
	}

	for (int k = 0; k < n; k++) {
		if (k < n - 1) {
			printf("%d ", A[k]);
		}
		else {
			printf("%d\n", A[k]);
		}
	}

	for (int i = 1; i < n; i++) {
		v = A[i];
		j = i - 1;
		while (j>=0 && A[j] >v) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = v;
		for (int k = 0; k < n; k++) {
			if (k < n - 1) {
				printf("%d ", A[k]);
			}
			else {
				printf("%d\n", A[k]);
			}
		}
	}
}
