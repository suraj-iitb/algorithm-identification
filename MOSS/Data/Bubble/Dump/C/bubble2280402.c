

#include <stdio.h>


int main(){

	int n, i, j;
	int A[101], tmp;
	int count=0;

	scanf( "%d", &n );

	for( i=0; i<n; i++ )
		scanf( "%d", &A[i] );

	for( i=0; i<n; i++ ){
	for( j=(n-1); j>i; j-- ){
		
		if( A[j] < A[j-1] ){
			tmp = A[j];
			A[j] = A[j-1];
			A[j-1] = tmp;	

			count++;
		} 

	}}

	for( i=0; i<n; i++ )
		printf( "%d%c", A[i], i!=(n-1)?' ':'\n' );

	printf( "%d\n", count );



	return 0;
}
