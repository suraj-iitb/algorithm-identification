#include <stdio.h>

/* 选择排序法(0起点) */
int selectionSort(int A[], int N) {
	int sw = 0;
	for (int i = 0; i < N - 1; i ++ ) {
		int minj = i;
		for (int j = i; j < N; j ++ ) {
			if (A[j] < A[minj]) minj = j;
		}
		int t = A[i]; A[i] = A[minj]; A[minj] = t;
		if (i != minj) sw ++ ;
	}
	return sw;
} 

int main() {
	int A[100], N, sw;
	
	scanf("%d", &N);
	for (int i = 0; i < N; i ++ ) scanf("%d", &A[i]);
	
	sw = selectionSort(A, N);
	
	for (int i = 0; i < N; i ++ ) {
		if (i > 0) printf(" ");
		printf("%d", A[i]);
	}
	printf("\n");
	printf("%d\n", sw);
	return 0;
}
