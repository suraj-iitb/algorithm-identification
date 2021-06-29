#include <stdio.h>
int selectionSort(int A[],int N) {
	int counter = 0;
	for (int i = 0;i < N;i++) {
		int minj = i;
		for (int j = i;j < N;j++) {
			if (A[j] < A[minj])
				minj = j;
		}
		if (!(i == minj)) {
			int dumy = A[i];
			A[i] = A[minj];
			A[minj] = dumy;
			counter++;
		}
	}
	for (int i = 0;i < N;i++) {
		if (i > 0) printf(" ");
		printf("%d", A[i]);
	}
	printf("\n");

	return counter;
}
int main() {
	int N,i;
	int A[100];
	scanf("%d", &N);
	for (i = 0;i < N;i++)
		scanf("%d", &A[i]);
	printf("%d\n", selectionSort(A, N));
}
