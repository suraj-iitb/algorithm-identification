#include <stdio.h>

int main ()
{
	int A[100], N, flag, i, j, tmp, count;
	
	scanf ("%d", &N);
	for ( i = 0; i < N; i++ ) {
		scanf ("%d", &A[i]);
	}
	
	flag = 1;
	count = 0;
	
	while (flag) {
		flag = 0;
		for (j = N - 1; j >= 1; j--) {
			if ( A[j] < A[j-1] ) {
				tmp = A[j];
				A[j] = A[j-1];
				A[j-1] = tmp;
				count++;
				flag = 1;
			}
		}
	}
	
	for(i = 0; i < N; i++) {
		printf ("%d", A[i]);
		if(i != N - 1) {
			printf (" ");
		}
	}
	printf ("\n%d\n", count);
	
	return 0;
}
