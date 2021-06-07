#include <stdio.h>

int Binary_Search( int , int, int* );

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
		count += Binary_Search( n, t[i], s);
	}
	
	printf("%d\n", count );
	
	return 0;
}
	
int Binary_Search( int n, int key, int* s){
	int left, right, mid;
	
	left = 0;
	right = n;
	
	while( left < right ){
		mid = (left + right)/2;
		
		if( s[mid] == key ){
			return 1;
		}
		else if( key < s[mid] ){
			right = mid;
		}
		else{
			left = mid + 1;
		}
	}
	
	return 0;
} 
