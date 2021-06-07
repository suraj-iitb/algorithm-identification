#include<stdio.h>
#define W 0
#define G 1
#define B 2
#define N 100
int n,M[N][N];
int color[N],d[N],f[N],tt;
void dfs_cisit(int u){
  int v;
  color[u]=G;
  d[u]=++tt;
  for(v=0;v<n;v++){
    if(M[u][v]==0)continue;
    if(color[v]==W){
      dfs_cisit(v);
    }
  }
  color[u]=B;
  f[u]=++tt;
}
void dfs(){
  int u;
  for(u=0;u<n;u++){
    color[u]=W;
  }
  tt=0;
  for(u=0;u<n;u++){
    if(color[u]==W)dfs_cisit(u);
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
      M[i][j]=0;
    }
  }
  for(i=0;i<n;i++){
  scanf("%d%d",&u,&k);
  u--;
  for(j=0;j<k;j++){
    scanf("%d",&v);
    v--;
    M[u][v]=1;
  }
}
dfs();
return 0;
}

