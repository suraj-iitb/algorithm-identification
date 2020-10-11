

#include <stdio.h>


int main(){

	int n, i, j;
	int A[101], tmp, mini;
	int count=0;

	scanf( "%d", &n );

	for( i=0; i<n; i++ )
		scanf( "%d", &A[i] );

	for( i=0; i<n; i++ ){
		mini = i;
		for( j=i; j<n; j++ )
			if( A[j] < A[mini] ) mini = j;
		
		//
		tmp = A[i];
		A[i] = A[mini];
		A[mini] = tmp;	
		if(i!=mini)count++; 

	}

	for( i=0; i<n; i++ )
		printf( "%d%c", A[i], i!=(n-1)?' ':'\n' );

	printf( "%d\n", count );



	return 0;
}
