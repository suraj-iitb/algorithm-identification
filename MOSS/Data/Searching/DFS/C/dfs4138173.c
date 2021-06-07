#include<stdio.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define N 100

int M[N][N];
int color[N],d[N],f[N],tt,n;
int u,v;
void dfs_visit(int u){
  int v;
  color[u] = GRAY;
  d[u]=++tt;
  for(v=0;v<n;v++){
    if(M[u][v]==0) continue;
    if(color[v] == WHITE){
      dfs_visit(v);
    }
  }
  f[u]=++tt;
  color[u]=BLACK;
}

void dfs(){
  int i;
  for(i=0;i<n;i++) color[i] = WHITE;
  tt = 0;
  for(i=0;i<n;i++){
    if(color[i] == WHITE) dfs_visit(i);
  }
}

int main(){
  int u,v,k;
  int i,j;
  scanf("%d",&n);

  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      M[i][j] = 0;
    }
  }

  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    u--;
    for(j=0;j<k;j++){
      scanf("%d",&v);
      v--;
      M[u][v] = 1;
    }
  }

  dfs();
  for(u=0;u<n;u++){
    printf("%d %d %d\n",u+1,d[u],f[u]);
  }
  return 0;
}

