#include<stdio.h>
#define N 100
#define RED 0
#define BLUE 1
#define GREEN 2

int n,Mtw[N][N];
int colortw[N],d[N],f[N],tt;

void dfs_visit(int u){
  int v;
  colortw[u] = BLUE;
  d[u]=++tt;
  for(v=0;v<n;v++){
    if(Mtw[u][v]==0)continue;
    if(colortw[v]==RED){
      dfs_visit(v);
    }
  }
  colortw[u]=GREEN;
  f[u]=++tt;
}

void dfs(){
  int u;
  for(u=0;u<n;u++)colortw[u]=RED;
  tt=0;

  for(u=0;u<n;u++){
    if(colortw[u]==RED)dfs_visit(u);
  }
  for(u=0;u<n;u++){
    printf("%d %d %d\n",u+1,d[u],f[u]);
  }
}

int main(){
  int u,v,k,i,j;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++)Mtw[i][j]=0;
  }

  for(i=0;i<n;i++){
    scanf("%d %d",&u,&k);
    u--;
    for(j=0;j<k;j++){
      scanf("%d",&v);
      v--;
      Mtw[u][v]=1;
    }
  }

  dfs();

  return 0;
}

