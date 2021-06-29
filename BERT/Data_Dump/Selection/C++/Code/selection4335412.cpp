#include <stdio.h>
void selectionSort(int A[], int N) {
	int minj, sw = 0, tmp, j, k;
	for (int i = 0; i < N - 1; i++)
	{
		minj = i;
		for (j = i; j < N; j++)
		{
			if (A[j] < A[minj]) {
				minj = j;
			}
		}
		tmp = A[i];
		A[i] = A[minj];
		A[minj] = tmp;
		if (i != minj) sw++;
	}

	for (k = 0; k < N; k++)
	{
		if (k > 0) printf(" ");
		printf("%d", A[k]);
	}
	printf("\n%d\n", sw);
}


int main() {
	int N, i, j;
	int A[100];

	scanf("%d", &N);
	for (i = 0; i < N; i++) scanf("%d", &A[i]);

	selectionSort(A, N);

	return 0;
}
