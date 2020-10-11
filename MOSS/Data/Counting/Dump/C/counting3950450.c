#include<stdio.h>

#define MAX 2000000

void CountingSort( int A[] , int B[] , int k , int n ){
	
	int i , j;
	int C[MAX];
	
	for( i = 0; i <= k + 1; i++ ){
		C[i] = 0;
	}
	
	for( j = 1; j <= n; j++ ){
		C[A[j]]++;
	}
	
	for( i = 1; i <= k + 1; i++ ){
		C[i] = C[i] + C[i - 1 ];
	}
	
	for( j = n; j >= 1; j-- ){
		B[C[A[j]]] = A[j];
		C[A[j]]--;
	}
	
}

int max( int A[] , int n ){
	
	int max = -1;
	
	for( int i = 0; i < n; i++ ){
		if( A[i] > max ){
			max = A[i];
		}
	}
	
	return max;
}

int main( void ){
	
	int n;
	int A[MAX] , B[MAX];
	
	scanf( "%d" , &n );
	
	for( int i = 1; i <= n; i++ ){
		scanf( "%d" , &A[i] );
	}
	
	CountingSort( A , B , max( A , n ) , n );
	
	for( int i = 1; i <= n; i++ ){
		
		if( i > 1 ){ printf( " " ); }
		printf( "%d" , B[i] );
			
	}
	printf( "\n" );
}


