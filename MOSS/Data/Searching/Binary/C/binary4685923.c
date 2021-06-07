#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

int binary_search( int * ary, int key, int size );
int main() {
        int s_ary[MAX], q_ary[MAX];
        int n, q, cnt = 0, flag = 0;

        scanf( "%d", &n );
        for ( int i = 0 ; i < n ; i++ ) {
                scanf( "%d", &s_ary[i] );
        }

        scanf( "%d", &q );
        for ( int i = 0 ; i < q ; i++ ) {
                scanf( "%d", &q_ary[i] );
        }

        for ( int i = 0 ; i < q ; i++ ) {
                if ( binary_search( s_ary, q_ary[i], n ) ) { cnt++; }
        }

        printf( "%d\n", cnt );
}

int binary_search( int * ary, int key, int size ) {
        int left = 0, right = size;
        int mid;

        while ( left < right ) {
                mid = ( left + right ) / 2;
                if ( key == ary[mid] ) {
                        return 1;
                } else if ( key > ary[mid] ) {
                        left = mid + 1;
                } else if ( key < ary[mid] ) {
                        right = mid;
                }
        }

        return 0;
}


