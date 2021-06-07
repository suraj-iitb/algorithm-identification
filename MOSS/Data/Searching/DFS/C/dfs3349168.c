#include<stdio.h>
#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n,M[N][N];
int c[N],d[N],f[N],tt;

void dfs_visit(int u){
  int v;
  c[u]=GRAY;
  d[u]=++tt;
  for(v=0;v<n;v++){
    if(M[u][v]==0) continue;
    if(c[v]==WHITE){
      dfs_visit(v);
    }
  }
  c[u]=BLACK;
  f[u]=++tt;
}

void dfs(){
  int u;
  for(u=0;u<n;u++) c[u]=WHITE;
  tt=0;

  for(u=0;u<n;u++){
    if(c[u]==WHITE) dfs_visit(u);
  }
  for(u=0;u<n;u++){
    printf("%d %d %d\n",u+1,d[u],f[u]);
  }
}

int main(){
  int u,k,v,i,j;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    for(j=0;j<n;j++) M[i][j]=0;
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

