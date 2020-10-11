#include<stdio.h>

int Sort(int A[], int N) {
	int i, j;
	int count = 0;
	int min;
	for (i = 0; i < N; i++) {
		min = i;
		for (j = i; j < N; j++) {
			if (A[j] < A[min]) {
				min = j;
			}
		}
		if (i != min) {
			int temp = A[i];
			A[i] = A[min];
			A[min] = temp;
			count++;
		}
	}
	return count;
}

int main() {
	int A[100];
	int N;
	int i, count;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	count = Sort(A, N);
	for (i = 0; i < N; i++) {
		if (i > 0)
			printf(" ");
		printf("%d", A[i]);
	}
	printf("\n%d\n", count);
	return 0;
}
