/* ADLS1_6_A_CountingSort */
/* 20181121 AOJ */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#define N 2000000
#define M 10000

void countingSort(int *A, int *B, int k);

int main(void){
	int n, i, A[N], B[N];

	i = 0;
	scanf("%d", &n);
	while(i < n) {
		scanf("%d", &A[i++]);
	}

	countingSort(A, B, n);

	i = 0;
	while(i < n) {
		if(i) printf(" ");
		printf("%d", B[i++]);
	}

	printf("\n");

	return 0;
}

void countingSort(int *A, int *B, int k) {
	int C[M + 1] = {0};
	int i = 0;

	i = 0;
	while(i < k) {
		C[A[i++]]++;
	}

	i = 1;
	while(i <= M ) {
		C[i] += C[i - 1];
		i++;
	}

	i = k;
	while(i--) {
		B[C[A[i]] - 1] = A[i];
		C[A[i]]--;
	}
}
