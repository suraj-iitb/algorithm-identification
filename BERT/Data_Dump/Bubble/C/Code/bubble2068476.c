#include <stdio.h>


int bubbleSort(int A[], int N) {
	int i, v, roopCount = 0, t = 0, flg;


	for (i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	flg = 1;

	while (flg) {
		flg = 0;
		for (i = N - 1; i > roopCount; i--) {
			if (A[i] < A[i - 1]) {
				v = A[i]; A[i] = A[i - 1]; A[i - 1] = v;
				t++;
				flg = 1;
			}
		}
		roopCount++;
	}

	for (i = 0; i < N; i++){
		printf("%d", A[i]);
		if (i < N - 1) {
			printf(" ");
		}
		else {
			printf("\n");
		}
	}

	return t;
}


int main() {
	int A[100], N;

	scanf("%d", &N);
	printf("%d\n", bubbleSort(A, N));

	return 0;
}
