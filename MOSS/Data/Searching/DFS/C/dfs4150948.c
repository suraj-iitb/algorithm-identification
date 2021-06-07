#include <stdio.h>
#define N 100
#define WHITE 0
#define BLACK 1
#define GRAY 2
 
int n;
int M[N][N];
int f[N],d[N],color[N],t;
 
 void dfs_visit(int u){
  int v;
 
  color[u] = GRAY;
  d[u] = ++t;
 
  for(v = 0; v < n; v++){
    if(M[u][v]== 0) continue;
    if(color[v] == WHITE){
      dfs_visit(v);
    }
  }
  color[u] = BLACK;
  f[u] = ++t;
 }

void dfs(){
  int u;
  for(u = 0; u < n; u++) color[u] = WHITE;
  t = 0;

  for(u = 0; u < n; u++){
    if(color[u] == WHITE) dfs_visit(u);
  }
  for(u = 0; u < n; u++){
    printf("%d %d %d\n",u+1,d[u],f[u]);
  }
}
  

int main(){
  int i,j;
  int u,v,k;
  
  scanf("%d",&n);
 
  for(i = 0 ; i < n ; i++)
    for(j = 0 ; j < n ; j++)
      M[i][j] = 0;
  
  for(i = 0 ; i < n ; i++){
    scanf("%d%d",&u,&k);
    u--;
    for(j = 0 ; j < k ; j++){
      scanf("%d",&v);
      v--;
      M[u][v] = 1;
    }
  }

  dfs();
  return 0;
}

