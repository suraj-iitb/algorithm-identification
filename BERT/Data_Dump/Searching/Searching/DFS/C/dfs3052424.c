#include <stdio.h>
#define N 100
#define W 0
#define G 1
#define B 2

int n, M[N][N];
int col[N],d[N],f[N],t;

void dfs1(int u){
  int v;
  col[u]=G;
  d[u]=++t;

  for(v=0; v<n; v++){
    if(M[u][v]==0) continue;
    if(col[v]==0) dfs1(v);
  }

  col[u]=B;
  f[u]=++t;
}

void dfs2(){
  int u;
  for(u=0; u<n; u++){
    col[u]=0;
  }

  t=W;

  for(u=0; u<n; u++){
    if(col[u]==0) dfs1(u);
  }

  for(u=0; u<n; u++){
    printf("%d %d %d\n",u+1,d[u],f[u]);
  }
}

int main(){
  int u, v, k, i, j;

  scanf("%d", &n);
  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      M[i][j]=0;
    }
  }
  for(i=0; i<n; i++){
    scanf("%d%d",&u,&k);
    u--;
    for(j=0; j<k; j++){
      scanf("%d",&v);
      v--;
      M[u][v]=G;
    }
  }
  dfs2();
  return 0;
}

