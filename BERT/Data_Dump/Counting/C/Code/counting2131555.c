#include <stdio.h>
#define MAX 2000001

int n;
int A[MAX] = {0};
int B[MAX] = {0};

void CountingSort(int A[], int B[], int k) {
	int i;
	int C[MAX] = {0};
//	for (i = 0; i < k; ++i) C[i] = 0;
	for (i = i; i < n; ++i) {
		C[A[i+1]]++;
	}

	for (i = 1; i <= k; ++i) {
		C[i] = C[i] + C[i-1];
	}

	for (i = n; i > 0; --i) {
		B[C[A[i]]] = A[i];
		C[A[i]]--;
	}
	return;
}

int main(void) {

	int i;
	int max = 0;

	
	scanf("%d", &n);

	for (i = 0; i < n; ++i) {
		scanf("%d", &A[i+1]);
		if (max < A[i]) max = A[i];
	}

	CountingSort(A, B, max);

	for (i = 0; i < n; ++i) {
		if (i != n -1 ) {
			printf("%d ", B[i+1]);
		} else {
			printf("%d\n", B[i+1]);
		}
	}
	return 0;
}
