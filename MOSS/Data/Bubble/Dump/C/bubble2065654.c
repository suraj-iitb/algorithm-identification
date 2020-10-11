#include <stdio.h>

int bubbleSort(int A[], int N) {
	int flag = 1;
	int sw = 0;
	int i, j, tmp;
	
	for ( i = 0; flag; i++ ) {
		flag = 0;
		for ( j = N - 1; j >= i +1; j-- ) {
			if ( A[j] < A[j - 1] ) {
				tmp = A[j];
				A[j] = A[j - 1];
				A[j - 1] = tmp;
				flag = 1;
				sw++;
			}
		}
	}
	return sw;
}

int main() {
	int A[100];
	int N, i, sw;
	
	scanf("%d", &N);
	for ( i = 0; i < N; i++ ) {
		scanf("%d", &A[i]);
	}
	
	sw = bubbleSort(A, N);
	
	for ( i = 0; i < N; i++ ) {
		if ( i > 0 ) {
			printf(" ");
		}
		printf("%d", A[i]);
	}
	printf("\n");
	printf("%d\n", sw);
	return 0;
}
