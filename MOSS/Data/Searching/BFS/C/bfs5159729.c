#include <stdio.h>
#define N_MAX 100
#define INF 10000000

int G[N_MAX+1][N_MAX+1],d[N_MAX+1],n,size[N_MAX+1];

void dfs(int p, int t){
  int id;
  d[p] = t;
  for(id=1;id<=size[p];id++)
    if(t+1 < d[G[p][id]]) dfs(G[p][id],t + 1);
}

int main(){
  int id,k,u;
  scanf("%d",&n);
  for(id=1;id<=n;id++){
    d[id] = INF;
    scanf("%d",&u);
    scanf("%d",&size[u]);
    for(k=1;k<=size[u];k++)
      scanf("%d",&G[u][k]);
  }
  dfs(1, 0);
  for(id=1;id<=n;id++)
    printf("%d %d\n",id,(d[id] == INF) ? -1 : d[id]);
  return 0;
}
