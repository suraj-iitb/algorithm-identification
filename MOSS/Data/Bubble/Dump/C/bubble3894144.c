#include <stdio.h>
void trace(int N, int A[]) {
	int i;
	for (i = 0; i < N; i++) {
		if (i > 0) printf(" ");
		printf("%d", A[i]);
	}
	printf("\n");
}

void BubbleSort(int N, int A[]) {
	int i, j, temp;
	int count = 0;
	for (i = 0; i < N - 1; i++) {
		for (j = N - 1; j > i; j--) {
			if (A[j] < A[j - 1]) {
				temp = A[j];
				A[j] = A[j - 1];
				A[j - 1] = temp;
				count++;
			}
		}
	}
	trace(N, A);
	printf("%d\n", count);
}

int main() {
	int i;
	int N, A[100];

	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	BubbleSort(N, A);

	return 0;
}
