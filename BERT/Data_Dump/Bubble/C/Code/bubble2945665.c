#include<stdio.h>
int main() {
	int A[100];
	int N, i, j, dum, ct=0;

	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	for(i=0;i<N;i++){
		for (j = N - 1; j > 0; j--) {
			if (A[j] < A[j - 1]) {
				dum = A[j - 1];
				A[j-1]=A[j];
				A[j]=dum;
				ct++;
			}
		}
	}
	for (i = 0; i < N-1; i++) {
		printf("%d ",A[i]);
	}
	printf("%d\n",A[N-1]);
	printf("%d\n", ct);
	return 0;
}
