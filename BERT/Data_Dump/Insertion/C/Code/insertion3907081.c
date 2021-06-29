#include<stdio.h>

int main(void)
{
	int N, i, v, j, s;
	scanf( "%d", &N );
	
	int A[N];
	for( i = 0; i < N; i++ ){
		scanf( "%d", &A[i] );
	}
	
	printf( "%d", A[0] );
	
	for( s = 1; s < N; s++ ){
			printf( " %d", A[s] );
		}
	
	printf( "\n" );
	
	for( i = 1; i < N; i++ ){
		v = A[i];
		j = i-1;
		while( j >= 0 && A[j] > v ){
			A[j+1] = A[j];
			j--;
			A[j+1] = v;
		}
		
		printf( "%d", A[0] );
		
		for( s = 1; s < N; s++ ){
			printf( " %d", A[s] );
		}
		
		printf( "\n" );
	}
	
	return 0;
}
