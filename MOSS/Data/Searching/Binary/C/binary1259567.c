#include<stdio.h>
   
#define MAXLEN 100000
    
     
int main( void ) 
{
    int n,q;
    int S[MAXLEN+1],T[MAXLEN+1];
    int i;
    int cnt;
    int lo,hi,m;
       
    scanf( "%d", &n ); 
    for( i=0; i<n; i++ ) {
        scanf( "%d", &S[i] ); 
    }
   
    scanf( "%d", &q); 
    for( i=0; i<q; i++ ) {
        scanf( "%d", &T[i] ); 
    }
    
    cnt=0;
    for( i=0; i<q; i++ ) {
		lo=0;
		hi=n;
		while( lo <= hi ) {
			m=(lo+hi)/2; 
            if( T[i] == S[m] ) {
                cnt++;
                break;
            } else if( T[i] < S[m] ) {
            	hi=m-1;
            } else {
            	lo=m+1;        	
            }
        }
    }
 
    if( cnt ) {
        printf( "%d\n", cnt );
    } else {
        printf( "0\n" );
    }
   
    return 0;
}
