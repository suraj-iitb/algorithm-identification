#include<stdio.h>
#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n,A[N][N];
int color[N],d[N],f[N],m;

void DFS2(int u){
  int v;
  color[u] = GRAY;
  m++;
  d[u] = m;
  for ( v=0 ; v<n ; v++ ){
    if ( A[u][v] == 0 ) continue;
    if ( color[v] == WHITE )
      DFS2(v);
  }
  color[u] = BLACK;
  f[u] = ++m;
}

void DFS(){
  int i, u;
  for ( i=0 ; i<n ; i++ )
    color[i] = WHITE;
  m = 0;
  for ( u=0 ; u<n ; u++ ){
    if ( color[u] == WHITE )
      DFS2(u);
  }
  for ( i=0 ; i<n ; i++ )
    printf("%d %d %d\n",i+1,d[i],f[i]);
}

main(){
  int u, k, v; 
  int i, j;

  scanf("%d",&n);

  for ( i=0 ; i<n ; i++ ){
    for ( j=0 ; j<n ; j++ )
      A[i][j] = 0;
  }
  
  for ( i=0 ; i<n ; i++ ){
    scanf("%d %d",&u,&k);
    u--;
    for ( j=0 ; j<k ; j++ ){
      scanf("%d",&v);
      v--;
      A[u][v] = 1;
    }
  }
  
  DFS();

  return 0;
}

