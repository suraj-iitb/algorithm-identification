#include<stdio.h>
#include<stdlib.h>

#define WHITE 0
#define BRACK 1
#define GRAY 2
#define N 101

int color[N];
int d[N];
int f[N];
int e[N];
int time;
int A[N][N];
int v[N];
int B[N][N];

void DFE_Visit(int u){
  int v,i;
  
  color[u]=GRAY;
  d[u]=++time;

  for(i=1;i<=e[u];i++){
    v=B[u][i];
    if(color[v]==WHITE)DFE_Visit(v);
  }
  color[u]=BRACK;
  f[u]=++time;
}

void DFS(int n){
  int i,u;
  
  for(i=1;i<=n;i++){
    u=v[i];
    color[u]=WHITE;
    time=0;
  }
  
  for(i=1;i<=n;i++){
    u=v[i];
    if(color[u]==WHITE)DFE_Visit(u);
    printf("%d %d %d\n",u,d[u],f[u]);
  }
}

main(){
  int n,i,j,v1;
 
  
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      A[i][j]=WHITE;
    }
  }

  scanf("%d",&n);
  
  for(i=1;i<=n;i++){
    scanf("%d%d",&v[i],&e[i]);
    for(j=1;j<=e[i];j++){
      scanf("%d",&v1);
      B[i][j]=v1;
      A[i][v1]= BRACK;
    }
  }
  DFS(n);

  return 0;
}
