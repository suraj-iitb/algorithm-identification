#include<stdio.h>

void SelectionSort( int *A, int n ) 
{
	int i,j;
	int tmp;
	int cnt;
	int mini;
	
	cnt=0;
	for( i=0; i<n; i++ ) {
		mini=i;
		for( j=i; j<n; j++ ) {
			if( A[j] < A[mini] ) {
				mini=j;
			}
		}
		if( mini != i ) {
			tmp=A[i];
			A[i]=A[mini];
			A[mini]=tmp;
			cnt++;
		}
	}
	for( i=0; i<n; i++ ) {
		printf( "%d", A[i] );
		if( n-1 != i ) {
			printf( " " );
		}
	}	
	printf( "\n" );	
	printf( "%d\n", cnt );
	
	return;
}

int main( void ) 
{
	int n;
	int A[101];
	int i;

	scanf( "%d", &n );
	for( i=0; i<n; i++ ) {
		scanf( "%d", &A[i] );
	}
	
	SelectionSort( A, n );
	
	return 0;
}
