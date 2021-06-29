#include<stdio.h>

int selectionsort( int a[] , int n );

int main( void ){
	
	int n;
	scanf( "%d" , &n );
	
	int a[n];
	int i;
	int c;
	
	for( i = 0; i < n; i++ ){
		scanf( "%d" , &a[i] );
	}
	
	c = selectionsort( a , n );
	
	for( i = 0; i < n; i++ ){
		if( i > 0 ){ printf( " " ); } 
		printf( "%d" , a[i] );
	}
	
	printf( "\n" );
	printf( "%d\n" , c );
	
	return 0;
}

int selectionsort( int a[] , int n ){
	
	int temp;
	int i , j;
	int min;
	int c = 0;
	
	for( i = 0; i <= n - 1; i++ ){
		
		min = i;
		
		for( j = i; j <= n - 1; j++ ){
			
			if( a[j] < a[min] ){
				min = j;
			}
		}
			
		temp = a[i];
		a[i] = a[min];
		a[min] = temp;
		
		if( i != min ){ c++; }
	}
	return c;
}
