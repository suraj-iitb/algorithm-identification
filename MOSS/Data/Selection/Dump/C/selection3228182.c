#include<stdio.h>
int main(){
	int A[100], n, i, j, f, g, h, k = 0, minj;
	scanf("%d", &n);
	for (i = 0;i < n; i++) {
		scanf("%d", &A[i]);
	}
	for (i = 0; i < n - 1; i++) {
		minj = i;
		for (j = i; j < n; j++) {
			if (A[j] < A[minj]) {
				minj = j;
			}
		}
		g = A[minj];
		h = A[i];
		A[i] = A[minj];
		A[minj] = h;
		if (g != h) {
			k++;
		}
	}
	for (i = 0; i < n; i++) {
		if (i == 0) {
			printf("%d", A[i]);
		}
		if (i != 0) {
			printf(" %d", A[i]);
		}
	}
	putchar('\n');
	printf("%d\n", k);
	return 0;
}

	
