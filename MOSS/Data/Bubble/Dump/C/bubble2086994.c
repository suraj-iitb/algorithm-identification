#include<stdio.h>

int main() {
	int n, i, j;
	int tmp;
	int A[1000];
	int flag = 1;

	scanf("%d", &n);

	for (i = 0; i < n; i++) scanf("%d", &A[i]);

	i = 0;

	while (flag) {
		flag = 0;

		for (j = n - 1; j > 0; j--) {
			if (A[j] < A[j - 1]) {
				tmp = A[j];
				A[j] = A[j - 1];
				A[j - 1] = tmp;
				flag = 1;

				i++;
			}
		}
	}

	for (j = 0; j < n; j++) {
		printf("%d", A[j]);
		if (j != n - 1) printf(" ");
	}
	printf("\n");
	printf("%d\n", i);

	return 0;
}
