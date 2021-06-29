#include <stdio.h>

int A[110], cnt = 0;

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void selectionSort(int *A, int N) {
	for (int i = 0; i < N; ++i) {
		int minj = i;
		for (int j = i; j < N; ++j) {
			if (A[j] < A[minj]) minj = j;
		}
		swap(&A[i], &A[minj]);
		if (i != minj) cnt++;
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &A[i]);
	}
	selectionSort(A, n);

	for (int i = 0; i < n; ++i) {
		if (i != n-1) printf("%d ", A[i]);
		else printf("%d\n", A[i]);
	}
	printf("%d\n", cnt);
}

