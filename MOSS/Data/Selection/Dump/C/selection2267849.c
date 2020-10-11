#include <stdio.h>

#define N 100

int selectionSort(int *A, int n) {
	int i,j;
	int tmp, min_index;
	int count = 0;

	for (i = 0; i < n; i++) {
		min_index = i;
		for (j = i; j < n; j++) {
			if (A[j] < A[min_index]) min_index = j;
		}
		tmp = A[i];
		A[i] = A[min_index];
		A[min_index] = tmp;

		if (i != min_index) count++;
	}

	return count;
}

int main() {
	int i, n;
	int A[N];
	int count;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
		scanf("%d", &A[i]);

	count = selectionSort(A, n);

	for (i = 0; i < n-1; i++) 
		printf("%d ", A[i]);
	printf("%d\n", A[i]);
	printf("%d\n", count);

	return 0;
}
