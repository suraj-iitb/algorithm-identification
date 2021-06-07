#include <stdio.h>

#define N 100

void dfs( int table[], int begin[], int end[], int pos, int n, int* count )
{
    int i;
    if ( begin[pos] != 0 )
        return;
  
    begin[pos] = ++(*count);
    for( i=0; i<n; ++i ) {
        if ( table[pos*N+i] == 1 ) {
            dfs( table, begin, end, i, n, count );
        }
    }
    end[pos] = ++(*count);
}

int main( void )
{
    int n, i, j, u, k, v;
    int cnt = 0;
    int table[N*N] = {0};
    int begin[N] = {0}, end[N] = {0};
    scanf( "%d", &n );

    for( i=0; i<n; ++i ) {
        scanf( "%d %d", &u, &k );
        for( j=0; j<k; ++j ) {
            scanf("%d", &v);
            table[((u-1)*N)+(v-1)] = 1;
        }
    }

    for( i=0; i<n; ++i )
        if ( begin[i] == 0 )
            dfs( table, begin, end, i, n, &cnt );

    for( i=0; i<n; ++i )
        printf("%d %d %d\n", i+1, begin[i], end[i]);

    return 0;
}
