#include <stdio.h>
#define N 100

int C[N],d[N],f[N],tt;
int n,G[N][N];

void DFS_visit(int u){
  int v;
  C[u] = 1;
  d[u] = tt++;
  for(v=0;v<n;v++){
    if(G[u][v] == 1 && C[v] == 0) {
      DFS_visit(v);
    }
  }
  C[u] = 2;
  f[u] = tt++;
}

void DFS(void){
  int u;
  for(u=0;u<n;u++) C[u] = 0;
  tt = 1;

  for(u=0;u<n;u++){
    if(C[u] == 0) DFS_visit(u);
  }
  for(u=0;u<n;u++){
    printf("%d %d %d\n",u+1,d[u],f[u]);
  }
}
    

int main(){
  int i,j,u,k,v;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      G[i][j] = 0;
    }
  }
  
  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    u--;
    for(j = 0; j < k;j++){
      scanf("%d",&v);
      v--;
      G[u][v] = 1;
    }
  }
  DFS();

  return 0;
}


