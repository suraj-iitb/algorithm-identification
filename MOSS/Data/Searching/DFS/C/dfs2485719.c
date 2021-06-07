#include <stdio.h> //depth first search
#include <stdlib.h>
  
#define WHITE 0  
#define GRAY 1    
#define BLACK 2   
  
char Adj[100][100]; 
int n, d[100],f[100],color[100],time;         
  
 
 
void visit( int u )
{
  short v;
  
  color[u] = GRAY;    
  d[u] = ++time;  
    
  for( v = 0 ; v < n ; v++ )
    {
      if( Adj[u][v] == 1 && color[v] == WHITE )
	{
	  visit( v );                             
	}
    }
  
  color[u] = BLACK;
  f[u] = ++time;
  
  return;
  
}
 
void dfs()
{
  short i;
    
  for( i = 0 ; i < n ; i++ ) {
    if( color[i] == WHITE ) {
      visit( i );
    }
  }
  return;
}
  
  
  
main()
{
  
  int i, j,u, k, v;
  
  scanf( "%d",&n );
    
  for( i = 0 ; i < n ; i++ )
    {
      for( j = 0 ; j < n ; j++ )
	{
	  Adj[i][j] = 0;
	}
    }
  
    
  for( i = 0 ; i < n ; i++ )
    {
      scanf( "%d%d", &u,&k );
      
      for( j = 0  ; j < k; j++ )
	{
	  scanf( "%d",&v );
	  Adj[u-1][v-1] = 1;
	}
      
    }
  
  dfs();
    
  for( i=0; i<n; i++ )
    {
      printf("%d %d %d\n", i+1, d[i], f[i] );
    }
 
  return 0;
  
}
