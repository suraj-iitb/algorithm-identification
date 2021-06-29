#include<stdio.h>

int main() {
	int n, i, j;
	int A[100];
	int minj = 0;
	int tmp = 0;;
	int k = 0;

	scanf("%d", &n);

	for (i = 0; i < n; i++) scanf("%d", &A[i]);

	for (i = 0; i < n; i++) {
		minj = i;

		for (j = i + 1; j < n; j++) {
			if (A[j] < A[minj]) {
				minj = j;
			}
		}

		if(minj != i) k++;

		tmp = A[i];
		A[i] = A[minj];
		A[minj] = tmp;
	}

	for (i = 0; i < n; i++) {
		printf("%d", A[i]);
		if (i != n - 1) printf(" ");
	}
	printf("\n");
	printf("%d\n", k);

	return 0;
}
