#include<stdio.h>

int selectionSort(int *A, int N) {
	int i, j;
	int minj, temp;
	int cnt = 0;

	for (i = 0; i < N; i++) {
		minj = i;
		for (j = i; j < N; j++) {
			if (A[j] < A[minj]) {
				minj = j;
			}
		}
		temp = A[i];
		A[i] = A[minj];
		A[minj] = temp;

		if (i != minj) {
			cnt++;
		}
	}
	return cnt;
}


int main()
{
	int N;
	int A[100];
	int i;
	int cnt;

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	cnt = selectionSort(A, N);

	for (i = 0; i < N; i++) {
		printf("%d", A[i]);
		if (i < N - 1) {
			printf(" ");
		}
	}
	printf("\n%d\n", cnt);

	return 0;
}
