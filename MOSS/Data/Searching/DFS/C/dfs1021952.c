#include <stdio.h>

int Adj[101][101];
int d[101], f[101], color[101];
int n, time;

void DFS(void){

  int i;

  for(i = 1; i <= n ;i++){
    color[i] = 0;
  }
  time = 0;

  for(i = 1; i <= n; i++){
    if(color[i] == 0){
      DFS_Visit(i);
    }
  }

}

void DFS_Visit(int u){

  int i;

  color[u] = 1;
  time++;
  d[u] = time;

  for(i = 1; i <= n; i++){
    if( (Adj[u][i] == 1) && (color[i] == 0) ){
      DFS_Visit(i);
    }
  }

  color[u] = 2;

  f[u] = ++time;

}

main(){
 
  int i, j, m, l;
 
  scanf("%d", &n);
 
  for(i = 1; i <= n; i++){
    scanf("%d %d", &Adj[i][0], &m);
 
    for(j = 1; j <= n; j++){
      Adj[i][j] = 0;
    }
     
    for(j = 1; j <= m; j++){
      scanf("%d", &l);
      Adj[i][l] = 1;
    }
 
  }
 
  DFS();

  for(i = 1; i <= n; i++){
    printf("%d %d %d\n", i, d[i], f[i]);
  }
 
  return 0;
 
}
