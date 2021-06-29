#include<stdio.h>

void insertionsort( int a[] , int n );
void output( int a[] , int n );

int main( void )
{
    int n;
    scanf( "%d" , &n );
	
	int a[n];
	int i;
	
	for( i = 0;  i < n; i++ ){
		
		scanf( "%d" , &a[i] );
		
	}
	
	output( a , n );
	
	insertionsort( a , n );
	
	return 0;
	
}

void insertionsort( int a[] , int n ){
	
	int i , j;
	int v;
	
	for( i = 1;  i <= n - 1; i++ ){
		
		v = a[i];
		j = i - 1;
		
		while( j >= 0 && a[j] > v ){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = v;
		output( a , n );
	}
	
}

void output( int a[] , int n ){
	
	int i;
	
	for( i = 0;  i < n; i++ ){
		
		if( i > 0 ){
			printf( " " );
		}
		
		printf( "%d" , a[i] );
		
	}
	
	printf( "\n" );
}
