#include <stdio.h>

#define MAX 100

int N, A[MAX];

int main() {
	int i, j;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	print();
	insertionSort();

	return 0;
}

void print() {
	int i;
	for (i = 0; i < N; i++) {
		if (i > 0) {
			printf(" ");
		}
		printf("%d", A[i]);
	}
	printf("\n");
}

void insertionSort() {
	int i, j, value;
	for (i = 1; i < N; i++) {
		value = A[i];
		j = i - 1;
		while(j >= 0 && A[j] > value) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = value;
		print();
	}
}
