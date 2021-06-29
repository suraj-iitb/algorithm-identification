#include <stdio.h>

void swap(int *A1, int *A2) {
	int tmp;
	tmp = *A1;
	*A1 = *A2;
	*A2 = tmp;
}

int bubbleSort(int A[], int N) {
	int i, j, sw = 0;
	int flag = 1;
	for (i = 0; flag; i++) {
		flag = 0;
		for (j = N - 1; j >= i + 1; j--) {
			if (A[j] < A[j - 1]) {
				swap(&A[j], &A[j - 1]);
				flag = 1;
				sw++;
			}
		}
	}
	return sw;
}

int main(void) {
	int N;
	int A[100];
	int sw;
	int i;
	
	scanf("%d", &N);
	
	for ( i = 0; i < N; i++ ) {
		scanf("%d", &A[i]);
	}
	
	sw = bubbleSort(A, N);
	
	for ( i = 0; i < N; i++ ) {
		if (i) {
			printf(" ");
		}
		printf("%d", A[i]);
	}
	
	printf("\n");
	printf("%d\n", sw);
	

	return 0;
}
