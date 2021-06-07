#include<stdio.h> 

#define MAXLEN 10000    
     
int main( void ) 
{
	int n,q;
	int S[ MAXLEN+1 ], t;
	int i,j;
	int cnt;    
	
	scanf( "%d", &n ); 
	for( i=0; i<n; i++ ) {
		scanf( "%d", &S[i] ); 
	}
	
	cnt=0;
	scanf( "%d", &q ); 
	for( i=0; i<q; i++ ) {
		scanf( "%d", &t );
		for( j=0; j<n; j++ ) {
			if( t == S[j] ) {
				cnt++;
				break;
			}
		}
	}
	
	printf( "%d\n", cnt );

	return 0;
}
