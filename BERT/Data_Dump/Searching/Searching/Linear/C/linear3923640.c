#include<stdio.h>
#include<stdlib.h>

int linearSearch( int n , int a[n] , int key);


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
		if( linearSearch( n , s , t[i]) != -1 ){
			c++;
		}
	}
	
	printf( "%d\n" , c );
	
}

int linearSearch( int n , int a[n] , int key){

	int i;
	
	i = 0;
	a[n] = key;
	
	while( a[i] != key ){
		i++;
	}
	
	if( i == n ){
		return -1;
	}
	
	return i;
	
}
