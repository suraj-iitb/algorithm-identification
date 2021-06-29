#include<stdio.h>

int bubblesort( int a[] , int n );

int main( void ){
	
	int n;
	scanf( "%d" , &n );
	
	int a[n];
	int i;
	int c;
	
	for( i = 0; i < n; i++ ){
		scanf( "%d" , &a[i] );
	}
	
	c = bubblesort( a , n );
	
	for( i = 0; i < n; i++ ){
		if( i > 0 ){ printf( " " ); } 
		printf( "%d" , a[i] );
	}
	
	printf( "\n" );
	printf( "%d\n" , c );
	
	return 0;
}

int bubblesort( int a[] , int n ){
	
	int temp , flag = 1;
	int i , j;
	int c = 0;
	
	for( i = 0; flag == 1; i++ ){
		
		flag = 0;
		
		for( j = n - 1; j >= i + 1; j-- ){
			
			if( a[j] < a[ j - 1 ] ){
				temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
				flag = 1;
				c++;
			}
		}
	}
	
	return c;
}
