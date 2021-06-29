#include <stdio.h>
#define MAX 101
#define INF 1000000
#define NIL -2
#define WHITE 0
#define BLACK 1

int main() {
  int n, i, j, u, k, v, w[MAX][MAX], d[MAX], pi[MAX], c[MAX], mincost, answer=0;

  scanf( "%d" , &n );
  for ( i=1; i<=n; i++ ) for ( j=1; j<=n; j++ ) w[i][j] = -1;
  for ( i=1; i<=n; i++ ) {
    scanf( "%d %d" , &u , &k );
    for ( j=1; j<=k; j++ ) {
      scanf( "%d" , &v );
      w[u][v] = 1;
    }
    if ( i == 1 ) d[i] = 0; else d[i] = INF;
    pi[i] = NIL;
    c[i] = WHITE;
  }

  while ( 1 ) {
    mincost = INF;
    for ( i=1; i<=n; i++ )
      if ( (c[i] != BLACK) && (d[i] < mincost) ) {
        mincost = d[i];
        u = i;
      }
    if ( mincost == INF ) break;
    c[u] = BLACK;
    for ( v=1; v<=n; v++ )
      if ( (w[u][v] != -1) && (c[v] != BLACK) && ((d[u]+w[u][v]) < d[v]) ) {
        pi[v] = u;
        d[v] = d[u] + w[u][v];
      }
  }

  for ( i=1; i<=n; i++ ) {
    if ( d[i] == INF ) printf( "%d %d\n" , i , -1 );
    else printf( "%d %d\n" , i , d[i] );
  }
  
  return 0;
}


/*
#include <stdio.h>
#define MAX 101
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define INF -1

int n, adj[MAX][MAX], c[MAX], d[MAX], tail, head;

int dequeue(void);
void enqueue(int);


int main() {
  int i, u, j, k, v;

  scanf( "%d" , &n );
  for ( i=1; i<=n; i++ ) {
    if ( i == 1 ){
      c[i] = GRAY;
      d[i] = 0;
    }
    else {
      c[i] = WHITE;
      d[i] = INF;
    }
    for ( j=1; j<=n; j++ ) adj[i][j] = 0;
  }

  for ( i=1; i<=n; i++ ) {
    scanf( "%d %d" , &u , &k );
    for ( j=1; j<=k; j++ ) {
      scanf( "%d" , &v );
      adj[u][v] = 1;
    }
  }

  tail = head = 1; // empty

  enqueue(1);
  while ( tail == head ) {
    u = dequeue();
    for ( i=1; i<=n; i++ )
      if ( adj[u][i] == 1 )
	if ( c[i] == WHITE ) {
	  c[i] = GRAY;
	  d[i] = d[u] + 1;
	  enqueue(i);
	}
    c[u] = BLACK;
  }

  for ( i=1; i<=n; i++ ) printf( "%d %d %d\n" , i , d[i] , c[i] );

  return 0;
}

int dequeue(void) {
  int x=adj[head][0];
  
  if ( (head+1) == n ) head = 0;
  else head++;
  return x;
}

void enqueue(int x) {
  adj[tail][0] = x;
  if ( (tail+1) == n ) tail = 0;
  else tail++;
}
*/

