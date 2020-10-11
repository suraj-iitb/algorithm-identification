#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX(x, y) (((x) > (y)) ? (x) : (y))

int main() {

	int n, i, max;
	scanf("%d", &n);

	unsigned short A[n+1];
	unsigned short B[n+1];

	max = (1<<30)*-1;
	for (i = 0; i < n; i++) {
		scanf("%hu", &A[i+1]);
		max = MAX(max, A[i+1]);
	}
	int C[max+1];
	memset(C, 0, sizeof(C));

	for (i = 0; i < n; i++) C[A[i+1]]++;
	for (i = 1; i <= max; i++) C[i] += C[i-1];

	for (i = n; i >= 1; i--) {
		B[C[A[i]]] = A[i];
		C[A[i]]--;
	}

	printf("%d", B[1]);
	for (i = 2; i <= n; i++) {
		printf(" %d", B[i]);
	}
	printf("\n");

	return 0;
}

