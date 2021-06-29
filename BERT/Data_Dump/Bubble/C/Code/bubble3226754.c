#include <stdio.h>
int main () {
	int i, j, flag, A[100], N, x, c = 0;

	scanf ( "%d", &N);
	for ( i = 0; i < N; i++ ) {
		scanf ( "%d", &A[i]);
	}
	
	flag = 1;
	while ( flag ) {
	flag = 0;
		for ( j = N-1; j >= 1; j-- ) {
			if ( A[j] < A[j-1] ) {
				x = A[j];
				A[j] = A[j-1];
				A[j-1] = x;
				flag = 1;
				c++;
			}
		}
	}
	for ( i = 0; i < N-1; i++){
		printf ( "%d ",A[i]);
	}
	printf ( "%d\n%d\n", A[N-1], c);

	return 0;
}
