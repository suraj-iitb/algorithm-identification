#include<stdio.h>

int V[150][150],d[150],f[150],color[150];
int time, n;

void DFSVisit(int u){
  int v;

  color[u] = 1;
  time++;
  d[u] = time;

  for(v = 1; v <= n; v++){
    if(V[u][v] == 1 && color[v] == 0){
      DFSVisit(v);
    }
  }
  color[u] = 2;
  time++;
  f[u] = time;
}

void DFS(){
  int u;

  time = 0;
  for(u = 1; u <= n; u++){
    if(color[u] == 0){
      DFSVisit(u);
    }
  }
}

int main(){
  int i,j,v,m,k;

  scanf("%d",&n);

  for(i = 1; i <= n; i++){
    scanf("%d%d",&v,&m);
    for(j = 1; j <= m; j++){
      scanf("%d",&k);
      V[v][k] = 1;
    }
  }

  DFS();

  for(i = 1; i <= n; i++){
    printf("%d %d %d\n", i, d[i], f[i]);
  }

  return 0;
}
