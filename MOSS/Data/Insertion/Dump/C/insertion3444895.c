#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

void print_array(int *A, int N) {
	for (int i = 0; i < N - 1; i++) {
		printf("%d ", A[i]);
	}
	printf("%d\n", A[N-1]);
}

void insertion_sort(int *A, int N) {
	int v, j;
	for (int i = 1; i < N; i++) {
		print_array(A, N);
		v = A[i];
		j = i - 1;
		while (j >= 0 && A[j] > v) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = v;
	}
	print_array(A, N);
}

int main(void) {
	int N;
	int *array;
	scanf("%d", &N);
	array = (int *)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) {
		scanf("%d", array + i);
	}
	insertion_sort(array, N);
	return 0;
}
