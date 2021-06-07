#include <stdio.h>

int linear_Search( int , int* );

int main( void ){
	int i, n, q, count;
	
	scanf("%d", &n );
	
	int s[n+1];
	
	for( i = 0; i < n; i++ ){
		scanf("%d", &s[i] );
	}
	
	scanf("%d", &q );
	
	int t[q];
	
	for( i = 0; i < q; i++ ){
		scanf("%d", &t[i] );
	}
	
	count = 0;
	for( i = 0; i < q; i++ ){
		s[n] = t[i];
		count += linear_Search( n, s );
	}
	
	printf("%d\n", count );
	
	return 0;
}
	
int linear_Search( int n, int* s){
	int i;
	
	for( i = 0; i < n; i++ ){
		if( s[i] == s[n] ){
			return 1;
		}
	}
	
	return 0;
} 
