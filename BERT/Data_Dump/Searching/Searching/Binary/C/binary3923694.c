#include<stdio.h>
#include<stdlib.h>

int binarySearch( int n , int a[n] , int key);

int main( void ){
	
	int n , q;
	int *s , *t;
	int i;
	int c = 0;
	
	scanf( "%d" , &n );
	s = (int *)malloc(n * sizeof(int));  
	for( i = 0; i < n; i++ ){
		scanf( "%d" , &s[i] );
	}
	
	scanf( "%d" , &q );
	t = (int *)malloc(q * sizeof(int));  
	for( i = 0; i < q; i++ ){
		scanf( "%d" , &t[i] );
	}
	
	for( i = 0; i < q; i++ ){
		if( binarySearch( n , s , t[i]) != -1 ){
			c++;
		}
	}
	
	printf( "%d\n" , c );
	
}

int binarySearch( int n , int a[n] , int key){

	int right , left , mid;
	
	left = 0;
	right = n;
	
	while( left < right ){
		mid = ( left + right ) / 2;
		
		if( a[mid] == key ){
			return mid;
		}else if( key < a[mid] ){
			right = mid;
		}else{
			left = mid + 1;
		}
	}
	
	return -1;
	
}
