#include<stdio.h>

int main(void) {
	int A[1000], N, i, j,k, v;

	scanf("%d", &N);

	for (i = 0; i <= N-1; i++) {
		scanf("%d", &A[i]);
	}

	for (k = 0; k <= N - 1; k++) {
		if (k <= N - 2)printf("%d ", A[k]);
		else if (k == N - 1) printf("%d\n", A[k]);
	}

	for (i = 1; i <= N-1; i++) {
		
		v = A[i];
		j = i - 1;
		while (j >= 0 && A[j] > v) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = v;

		for (k = 0; k <= N - 1; k++) {
			if(k<=N-2)printf("%d ", A[k]);
			else if(k==N-1) printf("%d\n", A[k]);
		}
	}

	
	return 0;
}
