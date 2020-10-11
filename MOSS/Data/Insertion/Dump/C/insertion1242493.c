#include<stdio.h>

void trace( int *A, int n )
{
	int i=0;
	while( i<n ) {
		printf( "%d", A[i++] );
		if( i != n ) { printf( " " ); }
	}
	printf( "\n" );
	
	return;
}

void insertionSort( int *A, int n )
{
	int i,j;
	int key;
	
  	for( i=1; i<n; i++ ) {
  		key = A[i];
  		j = i-1;
  		while( 0<=j && key<A[j] ) {
  			A[j+1] = A[j];
  			j--;
  		}
  		A[j+1] = key;
  		trace( A, n );
   	}
  
	return;
}

int main( void ) 
{
	int n;
	int A[101];
	int i;
	
	scanf( "%d", &n );
	for( i=0;  i<n; i++ ) {
		scanf( "%d", &A[i] );
    }
    trace( A, n );
    insertionSort( A, n );

	return 0;
}
