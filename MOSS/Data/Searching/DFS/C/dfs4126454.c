#include<stdio.h>
#define N 101
#define WHITE 0
#define GRAY 1
#define BLACK 2

int d[N],f[N],color[N];
int time;

void visit(int Adj[N][N],int u,int n){
  int v;
  color[u]=GRAY;
  d[u]=++time;
  for(v=1;v<=n;v++){
    if(Adj[u][v]==1 && color[v]==WHITE)
      visit(Adj,v,n);
  }
  color[u]=BLACK;
  f[u]=++time;
}

void dfs(int Adj[N][N],int n){
  int i,j;
  for(i=1;i<=n;i++){
    color[i]=WHITE;
  }
  time=0;
  for(i=1;i<=n;i++)
    if(color[i]==WHITE)
      visit(Adj,i,n);
}

int main(){
  int n,i,j,Adj[N][N],u,k,v;
  scanf("%d",&n);
  for(i=0;i<N;i++){
    for(j=0;j<N;j++)
      Adj[i][j]=0;
    d[i]=f[i]=0;
  }

  for(i=1;i<=n;i++){
    scanf("%d%d",&u,&k);
    for(j=1;j<=k;j++){
      scanf("%d",&v);
      Adj[u][v]=1;
    }
  }
  dfs(Adj,n);

  for(i=1;i<=n;i++){
    printf("%d %d %d\n",i,d[i],f[i]);
  }
  return 0;
}

