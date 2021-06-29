#include <stdio.h>
#define MAX 101
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n, adj[MAX][MAX], c[MAX], d[MAX], f[MAX], t=0;

void visit(int);

  
int main() {
  int i, u, j, k, v;
  
  scanf( "%d" , &n );
  for ( i=1; i<=n; i++ ) {
    c[i] = WHITE;
    for ( j=1; j<=n; j++ ) adj[i][j] = 0;
  }
  
  for ( i=1; i<=n; i++ ) {
    scanf( "%d %d" , &u , &k );
    for ( j=1; j<=k; j++ ) {
      scanf( "%d" , &v );
      adj[u][v] = 1;
    }
  }

  for ( i=1; i<=n; i++ ) if ( c[i] == WHITE ) visit(i);

  for ( i=1; i<=n; i++ ) printf( "%d %d %d\n" , i , d[i] , f[i] );

  return 0;
}

void visit(int u) {
  int i;
  
  c[u] = GRAY;
  d[u] = ++t;
  for ( i=1; i<=n; i++ ) if ( (adj[u][i] == 1) && (c[i] == WHITE) ) visit(i);
  c[u] = BLACK;
  f[u] = ++t;
}

