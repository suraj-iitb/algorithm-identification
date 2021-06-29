#include <stdio.h>
#define N 100

int FLAG[N],d[N],f[N],time,n;

int G[N][N];


void DFS_visit(int u){
  FLAG[u] = 1;
  d[u] = time++;
  for(int i = 0; i < n;i++){
    if(G[u][i] == 1 && FLAG[i] == 0) {
      DFS_visit(i);
    }
  }
  FLAG[u] = 2;
  f[u] = time++;
}

void DFS(void){
  int i;
  for(i = 0; i < n;i++) FLAG[i] = 0;
  time = 1;

  for(i = 0; i < n;i++){
    if(FLAG[i] == 0) DFS_visit(i);
  }
  for(i = 0; i  < n;i++){
    printf("%d %d %d\n",i+1,d[i],f[i]);
  }
}
    

int main(){
  int i,j,u,k,v;

  scanf("%d",&n);
  for(i = 0; i < n; i++){
    for(j = 0; j < n;j++){
      G[i][j] = 0;
    }
  }
  
  for(i = 0; i < n;i++){
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

