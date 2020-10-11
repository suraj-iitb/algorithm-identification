#include<stdio.h>

#define ABMAX 2000000
#define CMAX 10000

long gn;
 
void countingSort( short A[], short B[], short k )
{
	long i,j;
	int C[CMAX+1];

	for( i=0; i<=k; i++ ) {
		C[i]=0;
	}
	for( j=1; j<=gn; j++ ) {
		C[ A[j] ]=C[ A[j] ]+1;
	}

	for( i=1; i<=k; i++ ) {
		C[i]=C[i]+C[ i-1 ];
	}

	for( j=gn; 0<j; j-- ) {
		B[ C[ A[j] ] ]=A[j];
		C[ A[j] ]=C[ A[j] ]-1;
	}

	return;
}


int main( void ) 
{	
	long i;
	short A[ABMAX+1];
	short B[ABMAX+1];
	short k;
		
    scanf( "%ld", &gn );
	k=0;
	for( i=1; i<=gn; i++ ) {
		scanf( "%hd", &A[i] );
		if( k < A[i] ) {
			k=A[i];
		}
	}
	countingSort( A, B, k );
	for( i=1; i<=gn; i++ ) {
		printf( "%hd", B[i] );
		if( i < gn ) {
			printf( " " );
		}
	}
	printf( "\n" );

    return 0;
}

