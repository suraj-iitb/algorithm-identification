#include <stdio.h>
 
#define N 100
 
int queue[N] = {};
int b = 0, e = 0;
int step[N] = {};

void ENQ(int);
int DEQ();
int isemp();
void clear();
void BFS(int[], int s, int n);

int main(int argc,char *argv)
{
    int n, i, j, u, k, v;
    int cnt = 0;
    int table[N*N] = {};
    scanf( "%d", &n );
 
    clear();
 
    for( i=0; i<n; ++i ) {
        scanf( "%d %d", &u, &k );
        for( j=0; j<k; ++j ) {
            scanf("%d", &v);
            table[((u-1)*N)+(v-1)] = 1;
        }
    }
 
    BFS( table, 1, n );
 
    for( i=0; i<n; ++i )
        printf("%d %d\n", i+1, step[i]);
 
    return 0;
}
void ENQ( int v ) {
    queue[b++] = v;
}
int DEQ() {
    return queue[e++];
}
int isemp() {
    return b == e;
}
 
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
 
void BFS( int table[], int s, int n )
{
    int u, v;
 
    ENQ( s - 1 );
    while( !isemp() ) {
        u = DEQ();
        if ( step[u] == -1 )
            step[u] = 0;
                     
        for( v=0; v<n; ++v ) {
            if ( table[u*N+v] == 1 && step[v] == -1 ) {
                step[v] = step[u] + 1;
                ENQ( v );
            }
        }
    }
}
 
