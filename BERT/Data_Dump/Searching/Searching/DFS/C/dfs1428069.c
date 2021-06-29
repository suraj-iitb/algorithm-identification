#include <stdio.h>
#include <stdlib.h>
  
#define WHITE 0 
#define GRAY 1   
#define BLACK 2  
#define N 101
char Adj[N][N];
int n, d[N],f[N],color[N],time;        
  
 
 
void visit(int r) {
  int v;
  
  color[r] = GRAY;   
  d[r] = ++time; 
  
  for( v = 0 ; v < n ; v++ ) {
    if( Adj[r][v] == 1 && color[v] == WHITE ) {
      visit(v);                            
    }
  }
  color[r] = BLACK;
  f[r] = ++time;
}
 
void dfs() {
  int i;
  
  for( i = 0 ; i < n ; i++ ) {
    if( color[i] == WHITE ) {
      visit(i);
    }
  }
}

  
  
main() {
  
  int i,j,u,k,v;
  
  scanf( "%d",&n );
  
  for( i = 0 ; i < n ; i++ ) {
    for( j = 0 ; j < n ; j++ ) {
      Adj[i][j] = 0;
    }
  }
  
  
  for( i = 0 ; i < n ; i++ ) {
    scanf( "%d%d", &u,&k );
      
    for( j = 0  ; j < k; j++ ) {
      scanf( "%d",&v );
      Adj[u-1][v-1] = 1;
}
    
  }
  
  dfs();
  
  for( i=0; i<n; i++ ) {
    printf("%d %d %d\n", i+1, d[i], f[i] );
  }
 
  return 0;
  
}
