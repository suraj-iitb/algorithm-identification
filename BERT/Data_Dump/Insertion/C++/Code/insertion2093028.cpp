#include <stdio.h>
#define N 100

void trace(int A[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%d", A[i]);
		if (i + 1 < n) printf(" ");
	}
	printf("\n");
}

void insertionSort(int A[], int n) {
	int i, j, v;

	for (i = 1; i < n; i++) {
		v = A[i];
		j = i - 1;

		while (j >= 0 && A[j]>v) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = v;
		trace(A, n);
	}
}


int main(){
	int i, n, A[N];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &A[i]);

	trace(A, n);
	insertionSort(A, n);

	return 0;
}
