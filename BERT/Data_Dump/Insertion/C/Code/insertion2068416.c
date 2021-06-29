#include <stdio.h>


void insertionSort(int A[], int N) {
	int i, j, k, v;


	for (i = 0; i < N; i++) {
		scanf("%d", &A[i]);
		printf("%d", A[i]);
		if (i == N - 1) {
			printf("\n");
		} else {
			printf(" ");
		}
	}

	for (i = 1; i < N; i++){
		v = A[i];
		j = i - 1;
		while (j >= 0 && A[j] > v){
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = v;

		for (k = 0; k < N; k++) {
			printf("%d", A[k]);
			if (k == N - 1) {
				printf("\n");
			} else {
				printf(" ");
			}
		}
	}
}


int main() {
	int A[1000], N;

	scanf("%d", &N);
	insertionSort(A, N);

	return 0;
}
