#include<stdio.h>
#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n, M[N][N];
int color[N],d[N],e[N],t;

void dfs_a( int u ){
  int v;
  color[u] = GRAY;
  d[u] = ++t;
  for ( v = 0 ; v < n ; v++ ){
    if( M[u][v] == 0)continue;
    if( color[v] == WHITE ){
      dfs_a( v );
    }
  }
  color[u] = BLACK;
  e[u] = ++t;
}

void dfs_b(){
  int u;
  for ( u = 0 ; u < n; u++ ){
    color[u] = WHITE;
  }
  t = 0;
  for( u = 0 ; u < n ; u++ ){
    if( color[u] == WHITE )dfs_a(u);
  }
  for( u = 0 ; u < n ; u++ ){
    printf("%d %d %d\n",u+1 ,d[u] ,e[u]);
  }
}

int main( void ){
  int u,v,k,i,j;

  scanf("%d",&n);
  for( i = 0 ; i < n ; i++ ){
    for( j = 0 ; j < n ; j++ ){
      M[i][j] = 0;
    }
  }
  for( i = 0 ; i < n ; i++ ){
    scanf("%d %d",&u,&k);
    u--;
    for( j = 0 ; j < k ; j++ ){
      scanf("%d",&v);
      v--;
      M[u][v] = 1;
    }
  }
  dfs_b();

  return 0;
}
