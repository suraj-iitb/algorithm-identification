#include<stdio.h>
#define N 100

int main () {
	int count, i, tmp, n, A[N], flag;

	count = 0;

	scanf("%d", &n);

	for ( i = 0;i < n; i++ ) {
		scanf("%d", &A[i]);
	}

	flag = 1;
	while ( flag ) {
		flag = 0;
		for ( i = 1;i < n; i++ ) {
			if ( A[i] < A[i - 1] ) {
				tmp = A[i];
				A[i] = A[i - 1];
				A[i - 1] = tmp;
				count++;
				flag = 1;
			}
		}
	}
	for ( i = 0; i < n; i++ ) {
		printf("%d", A[i]);
		if( i < n-1 )
			putchar(' ');
	}
	printf("\n");
	printf("%d\n", count);

	return 0;
}
