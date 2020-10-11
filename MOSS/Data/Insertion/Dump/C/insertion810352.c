#include <stdio.h>

void p(int A[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		if (i != 0) putchar(' ');
		printf("%d", A[i]);
	}
	putchar('\n');
}

int main(void) {
	int i, j, n, key, A[100];
	scanf("%d", &n);
	for (i = 0; i < n; i++) 
		scanf("%d", A + i);
	for (j = 1; j < n; j++) {
		p(A, n);
		key = A[j];
		i = j - 1;
		while ((i >= 0) && (A[i] > key)) {
			A[i + 1] = A[i];
			i--;
		}
		A[i + 1] = key;
	}
	p(A, n);
	return 0;
}
