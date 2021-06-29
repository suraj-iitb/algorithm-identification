#include <stdio.h>

#define N 2000000
#define K 10000

int A[N + 1], B[N + 1], C[K + 1];
int n, k;

void inputArray() {
	int i;

	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		scanf("%d", &A[i]);
		if (k < A[i]) {
			k = A[i];
		}
	}

}

void coutingSort() {
	int i, j;

	for (j = 1; j <= n; j++) {
		C[A[j]]++;
	}

	for (i = 1; i <= k; i++) {
		C[i] += C[i - 1];
	}

	for (j = n; j >= 1; j--) {
		B[C[A[j]]] = A[j];
		C[A[j]]--;
	}

}

void displayArray() {
	int i;

	for (i = 1; i <= n; i++) {
		if (i > 1) printf(" ");
		printf("%d", B[i]);
	}
	printf("\n");
}

int main() {

	inputArray();
	coutingSort();
	displayArray();

	return 0;
}
