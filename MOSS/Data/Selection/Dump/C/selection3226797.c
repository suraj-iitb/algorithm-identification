#include <stdio.h>
int main () {
	int i, j, minj, A[100], N, x, c = 0;

	scanf ( "%d", &N);
	for ( i = 0; i < N; i++ ) {
		scanf ( "%d", &A[i]);
	}
	
	for ( i = 0; i <= N-1; i++ ) {
		minj = i;
		for ( j = i; j <= N-1; j++ ) {
			if ( A[j] < A[minj] ) {
				minj = j;
			}
		}
	
		if ( i != minj ) {
			x = A[minj];
			A[minj] = A[i];
			A[i] = x;
			c++;
		}
	}
	for ( i = 0; i < N-1; i++){
		printf ( "%d ",A[i]);
	}
	printf ( "%d\n%d\n", A[N-1],c);

	return 0;
}
