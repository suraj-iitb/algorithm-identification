#include <stdio.h>
int main() {
	int N, i, j, k, key;
	int A[1000];
	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	for (k = 0; k < N; k++) {
		if (k == 0) {
			printf("%d", A[k]);
		}
		else {
			printf(" %d", A[k]);
		}
	}
	printf("\n");
	for (i = 1; i <= N - 1; i++) {
		key = A[i];
		j = i - 1;
		while (j >= 0 && A[j] > key) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = key;
		for (k = 0; k < N; k++) {
			if (k == 0) {
				printf("%d", A[k]);
			}
			else {
				printf(" %d", A[k]);
			}
		}
		
		
			printf("\n");
		

	}

	return 0;
}

