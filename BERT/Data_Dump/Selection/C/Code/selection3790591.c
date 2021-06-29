#include <stdio.h>

int selection_Sort(int A[], int N) {
	int n = 0, tmp, minj ;
	for (int i = 0; i < N-1; i++) {
	    minj = i;
		for (int j = i; j < N; j++) {
			if (A[minj] > A[j]) {
				minj = j;
			}
		}
		tmp = A[i];
		A[i] = A[minj];
		A[minj] = tmp;
		if (i != minj) n++;
		
	}
	return n;
}

int main() {
	int A[100], N, n;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);

	n = selection_Sort(A, N);
	for (int k = 0; k < N; k++) {
	    if(k > 0) printf(" ");
		printf("%d", A[k]);
	}
	printf("\n");
	printf("%d\n", n);

	return 0;
}


