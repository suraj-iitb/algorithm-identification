#include<stdio.h>
int main(){
	int A[100], n, i, j, f, g, h, k = 0;
	scanf("%d", &n);
	for (i = 0;i < n; i++) {
		scanf("%d", &A[i]);
	}
	for (g = 0; g < n - 2; g++) {
		f = 1;
		i = g;
		while (f == 1) {
			f = 0;
			for (j = n - 1; j > i; j--) {
				if (A[j] < A[j - 1]) {
					h = A[j];
					A[j] = A[j - 1];
					A[j - 1] = h;
					f = 1;
					k++;
				}
			}
			i++;
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

	
