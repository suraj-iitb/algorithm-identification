#include <stdio.h>

int bubbleSort(int A[], int N) {
	int sw, flag, i, j, e;
	sw = 0; flag = 1;

	while (flag) {
		flag = 0;
		for (i = 0; i < N; i++) {
			for (j = N - 1; j > i; j--) {
				if (A[j] < A[j - 1]) {
					e = A[j]; A[j] = A[j - 1]; A[j - 1] = e;
					flag = 1;
					sw++;
				}
			}
		}
	}

	return sw;

}

int main() {
	int A[100], N, sw, i;
	scanf("%d", &N);

	for (i = 0; i < N; i++)
		scanf("%d", &A[i]);

	sw = bubbleSort(A, N);

	for (i = 0; i < N; i++) {
		if (i > 0) printf(" ");
		printf("%d", A[i]);
	}
	
	printf("\n%d\n", sw);

	return 0;
}
