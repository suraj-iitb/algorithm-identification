#include <stdio.h>

int length(int *A) {
	return A[0];
}

void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

int BubbleSort(int *A) {
	int i, j, n = 0;
	for (i = 1; i <= length(A); i++) {
		for (j = length(A); j >= i + 1; j--) {
			if (A[j] < A[j - 1]) {
				swap(&A[j], &A[j - 1]);
				n++;
			}
		}
	}
	return n;
}

int SelectionSort(int *A) {
	int i, j, mini, n = 0;
	for (i = 1; i <= length(A); i++) {
		mini = i;
		for (j = i; j <= length(A); j++) {
			if (A[j] < A[mini]) {
				mini = j;
			}
		}
		if (i != mini) {
			swap(&A[i], &A[mini]);
			n++;
		}
	}
	return n;
}

int main(void) {
	int A[101] = {0};
	int N, c;
	int i;
	
	scanf("%d", &N);
	A[0] = N;
	for (i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
	}
	
	c = SelectionSort(A);
	
	for (i = 1; i <= N; i++) {
		if (i > 1) {
			putchar(' ');
		}
		printf("%d", A[i]);
	}
	
	printf("\n%d\n", c);
	
	return 0;
}
