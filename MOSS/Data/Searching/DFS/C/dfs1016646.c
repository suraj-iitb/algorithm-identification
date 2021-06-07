#include <stdio.h>
#define N 102
int G[N][N],color[N],f[N],d[N],n,time;

void DFS_V(int u){
  int i,j;
  color[u] = -1;
  d[u] = ++time;
  for(i = 1; i < n+1; i++){
    if(G[u-1][i-1] == 1){
      if(color[i] == 0){
	DFS_V(i);
      }
    }
  }
  color[u] = 1;
  f[u] = ++time;
}

void DFS(void){
  int i;
  for(i = 1; i < n+1; i++){
    color[i] = 0;
    time = 0;
  }
  for(i = 1; i < n+1; i++){
    if(color[i] == 0){
      DFS_V(i);
    }
  }
}

int main(){
  int i,j,u,n2,v;
  scanf("%d",&n);
  
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      G[i][j] = 0;
    }
  }
  
  for(i = 0; i < n; i++){
    scanf("%d %d",&u,&n2);
    for(j = 0; j < n2; j++){
      scanf("%d",&v);
      G[u-1][v-1] = 1;
    }
  }
  DFS();
  for(i = 1; i < n+1; i++){
    printf("%d %d %d\n",i,d[i],f[i]);
  }
  return 0;
}
