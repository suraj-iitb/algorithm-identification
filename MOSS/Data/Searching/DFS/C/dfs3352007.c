#include<stdio.h>
#define N 101

int n, M[N][N];
int color[N], d[N], f[N], tt;

void dfs_visit(int u){
  int v;
  color[u]=1;
  d[u]=++tt;
  for(v=1;v<=n;v++){
    if(M[u][v]==0) continue;
    if(color[v]==0) dfs_visit(v);
  }
  color[u]=2;
  f[u]=++tt;
}

void dfs(){
  int u;
  for(u=1;u<=n;u++) color[u]=0;
  tt=0;

  for(u=1;u<=n;u++){
    if(color[u]==0) dfs_visit(u);
  }
  for(u=1;u<=n;u++) printf("%d %d %d\n",u,d[u],f[u]);
}

int main(){
  int u,v,i,j,k;

  scanf("%d", &n);
  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++) M[i][j]=0;
  }

  for(i=1;i<=n;i++){
    scanf("%d %d", &u, &k);
    for(j=1;j<=k;j++){
      scanf("%d", &v);
      M[u][v]=1;
    }
  }

  dfs();

  return 0;
}
    

