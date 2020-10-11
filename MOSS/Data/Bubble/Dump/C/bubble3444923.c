#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int bubble_sort(int *A, int N) {
	int itmp, change_number = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - i - 1; j++) {
			if (A[j] > A[j + 1]) {
				itmp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = itmp;
				change_number++;
			}
		}
	}
	return change_number;
}

int main(void) {
	int N, answer;
	int *Array;
	scanf("%d", &N);
	Array = (int *)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) {
		scanf("%d", Array + i);
	}
	answer = bubble_sort(Array, N);
	for (int i = 0; i < N-1; i++) {
		printf("%d ", Array[i]);
	}
	printf("%d\n%d\n", Array[N - 1], answer);
	return 0;
}
