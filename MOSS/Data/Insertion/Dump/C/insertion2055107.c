#include <stdio.h>

int main(void) {
	int N,i,j,k,tmp;
	int A[100];
	
	scanf("%d", &N);
	for (i = 0;i < N;i++) {
		scanf("%d", &A[i]);
	}
	
	for (i = 0;i < N;i++) {
		tmp = A[i];
		k = i-1;
		while (k >= 0 && A[k] > tmp) {
			A[k+1] = A[k];
			k--;
		}
		A[k+1] = tmp;
		for (j = 0;j < N;j++) {
			printf("%d%c", A[j], j == N-1 ? '\n' : ' ');
		}
	}
	return 0;
}
