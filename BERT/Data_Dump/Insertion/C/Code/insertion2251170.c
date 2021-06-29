


#include <stdio.h>

int main(){

	int n, i, j;
	int A[101], key;

	scanf( "%d", &n );

	for( i=0; i<n; i++ ) scanf( "%d", &A[i] );
	

	for( i=0; i<n; i++){

		key = A[i];

		j = i-1;

		while( j>=0 && A[j]>key ){
			A[j+1] = A[j];
			j--;
		}

		A[j+1] = key;

		for( j=0; j<n; j++ ) 
			printf( "%d%c", A[j], j!=(n-1)?' ':'\n' );

	}


	return 0;

}
