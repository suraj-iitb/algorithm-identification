#include <stdio.h>

#define Max 1000

void insertionSort(int A[Max], int N) {
	int i, j, v;

	for (i = 0; i < N; i++) { 
		v = A[i];
		j = i - 1;
		while (j >= 0 && A[j] > v) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = v;
		for (j = 0; j < N - 1; j++)
			printf("%d ", A[j]);
		printf("%d\n", A[N - 1]);
	}
}

int main( ) {
	int N, i, j;
	int num[Max];

	scanf("%d", &N);

	for (i = 0; i < N; i++) scanf("%d", &num[i]);

	insertionSort(num, N);

	return 0;
}
