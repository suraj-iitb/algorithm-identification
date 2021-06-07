#include <stdio.h>
#define N 10000
 
int main( void )
{
    int i, j, c = 0, n, q, s[N], t;
     
    scanf( "%d", &n );
     
    for ( i = 0; i < n; i++ ) {
        scanf( "%d", &s[i] );
    }
     
    scanf( "%d", &q );
     
    for ( i = 0; i < q; i++ ) {
        scanf( "%d", &t );
        for ( j = 0; j < n; j++ ) {
            if ( t == s[j] ) {
                t = -1;
            }
        }
        if ( t == -1 ) {
            c++;
        }
    }
     
    printf( "%d\n", c );
     
    return 0;
}
