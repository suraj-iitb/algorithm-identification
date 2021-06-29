#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

int main() {
        int s_ary[MAX], q_ary[MAX];
        int n, q, cnt = 0, flag = 0;

        scanf( "%d", &n );
        for ( int i = 0 ; i < n ; i++ ) {
                scanf( " %d", &s_ary[i] );
        }

        scanf( " %d", &q );
        for ( int i = 0 ; i < q ; i++ ) {
                scanf( " %d", &q_ary[i] );
        }

        for ( int i = 0 ; i < q ; i++ ) {

                flag = 0;
                for ( int j = 0 ; j < n ; j++ ) {
                        if ( s_ary[j] == q_ary[i] ) {
                                flag = 1;
                        }
                }
                if ( flag ) { cnt++; }
        }
        printf( "%d\n", cnt );
}

