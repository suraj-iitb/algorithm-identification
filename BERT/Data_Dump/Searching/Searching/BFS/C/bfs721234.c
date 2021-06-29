#include <stdio.h>

#define N 100

int queue[N] = {0};
int b = 0, e = 0;
void enq( int v ) {
    queue[b++] = v;
}
int deq() {
    return queue[e++];
}
int is_empty() {
    return b == e;
}

int step[N] = {0};

void clear()
{
    int i;
    for( i=0; i<N; ++i ) {
        queue[i] = 0;
        step[i] = -1;
    }
    b = 0;
    e = 0;
}

void bfs( int table[], int s, int n )
{
    int u, v;

    enq( s - 1 );
    while( !is_empty() ) {
        u = deq();
        if ( step[u] == -1 )
            step[u] = 0;
                    
        for( v=0; v<n; ++v ) {
            if ( table[u*N+v] == 1 && step[v] == -1 ) {
                step[v] = step[u] + 1;
                enq( v );
            }
        }
    }
}


int main( void )
{
    int n, i, j, u, k, v;
    int cnt = 0;
    int table[N*N] = {0};
    scanf( "%d", &n );

    clear();

    for( i=0; i<n; ++i ) {
        scanf( "%d %d", &u, &k );
        for( j=0; j<k; ++j ) {
            scanf("%d", &v);
            table[((u-1)*N)+(v-1)] = 1;
        }
    }

    bfs( table, 1, n );

    for( i=0; i<n; ++i )
        printf("%d %d\n", i+1, step[i]);

    return 0;
}
