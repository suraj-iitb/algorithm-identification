#include <stdio.h>


int  selectionSort(int A[], int N) {
	int i, j,minj, tmp, count = 0;
	
	for (i = 0; i < N ; i++) {
		minj = i;
		for (j = i; j < N ; j++) {
			if (A[j] < A[minj]) {
				minj = j;
			}
		}
		tmp = A[i];
		A[i] = A[minj];
		A[minj] = tmp;;
		if (i != minj) count++;
	}
	return count;
}

int main(void) {
	int N;
	int A[100];
	int i;
	int kai;

	scanf("%d", &N);
	
	for (i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	
	kai = selectionSort(A, N);

	for (i = 0; i < N; i++) {
		if (i > 0) printf(" ");
		printf("%d", A[i]);
	}
	printf("\n");

	printf("%d\n", kai);

	return 0;
}
