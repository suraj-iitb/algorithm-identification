#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n, a[10001] = { 0 };
	scanf("%d", &n);
	int* A = malloc(n * sizeof(int));
	for (int i = 0; i < n; ++i) {
		scanf("%d", &A[i]);
		++a[A[i]];
	}
	for (int i = 0, j = 0; i < n; ++i) {
		while (!a[j]) ++j;
		--a[j];
		A[i] = j;
	}
	for (int i = 0; i < n - 1; ++i) printf("%d ", A[i]);
	printf("%d\n", A[n - 1]);
	free(A);
	return 0;
}
