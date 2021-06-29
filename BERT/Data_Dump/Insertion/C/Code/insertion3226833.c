#include<stdio.h>

int main(){
	int N, i, j, k, l, v, A[1000];  
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	for (i = 1; i < N + 1; i++) {
		for (j = 0; j < i; j++) {
			v = A [j];
			k = j - 1;
			while (k >= 0 && A [k] > v) {
				A [k + 1] = A [k];
				k--;
			}
			A[k + 1] = v;
		}
		for (l = 0; l < N; l++) {
			if (l == 0) {
				printf("%d",A[l]);
			}
			else {
				printf(" %d",A[l]);
			}
		}
		putchar('\n');
	}
}



