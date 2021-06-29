#include<stdio.h>
#define N 100
int W=0,G=1,B=2;
int n,M[N][N],color[N],d[N],f[N],t;

void dfs_visit(int u){
  int v;
  color[u] = G;
  t++;
  d[u] = t;
  for(v=0;v<n;v++){
    if(M[u][v] == 0)continue;
    if(color[v] == W){
      dfs_visit(v);
    }
  }
  color[u] = B;
  f[u] = ++t;
}
void dfs(){
  int i,u;
  for(i=0;i<n;i++)color[i] = W;
  t = 0;
  for(u=0;u<n;u++){
    if(color[u] == W)dfs_visit(u);
  }
  for(i=0;i<n;i++){
    printf("%d %d %d\n",i+1,d[i],f[i]);
  }
}
main(){
  int u,k,v,i,j;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    for(j=0;j<n;j++)M[i][j] = 0;
  }
  for(i=0;i<n;i++){
    scanf("%d %d",&u,&k);
    u--;
    for(j=0;j<k;j++){
      scanf("%d",&v);
      v--;
      M[u][v] = 1;
    }
  }
  dfs();

  return 0;
}

