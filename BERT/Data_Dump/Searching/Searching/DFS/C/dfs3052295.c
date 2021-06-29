#include<stdio.h>
#define N 100
#define W 0
#define G 1
#define B 2

int n,M[N][N];
int col[N],d[N],f[N],tt;

void dfs_visit(int u){
  int v;
  col[u] = G;
  d[u] = ++tt;
  for(v=0;v<n;v++){
    if(M[u][v] == 0)continue;
    if(col[v]==W){
      dfs_visit(v);
    }
  }
  col[u] = B;
  f[u] = ++tt;
}

void dfs(){
  int u;
  for(u=0;u<n;u++)col[u] = W;
  tt=0;

  for(u=0;u<n;u++){
    if(col[u] == W)dfs_visit(u);
  }
  for(u=0;u<n;u++){
    printf("%d %d %d\n",u+1,d[u],f[u] );
  }
}

int main(){
  int u,v,i,j,k;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      M[i][j] =0;
    }
  }

  for(i=0;i<n;i++){
    scanf("%d %d",&u,&k);
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

