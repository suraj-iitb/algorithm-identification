#include<stdio.h>

void BubbleSort( int *A, int n ) 
{
	int i,j;
	int tmp;
	int cnt;
	
	cnt=0;
	for( i=0; i<n; i++ ) {
		for( j=n-1; i<j; j-- ) {
			if( A[j] < A[j-1] ) {
				tmp=A[j-1];
				A[j-1]=A[j];
				A[j]=tmp;
				cnt++;
			}
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
	
	BubbleSort( A, n );
	
	return 0;
}
