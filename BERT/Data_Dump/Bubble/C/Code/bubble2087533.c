#include <stdio.h>
int main(void) {
	int i, n, flag, temp, A[10000], count = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}
	flag = 1;
	while (flag) {
		flag = 0;
		for (i = n - 1; i > 0; i--) {
			if (A[i] < A[i - 1]) {
				temp = A[i];
				A[i] = A[i - 1];
				A[i - 1] = temp;
				flag = 1;
				count++;
			}
		}
	}
	for (i = 0; i < n - 1; i++) {
		printf("%d ", A[i]);
	}
	printf("%d\n", A[n - 1]);
	printf("%d\n", count);
	return 0;
}
