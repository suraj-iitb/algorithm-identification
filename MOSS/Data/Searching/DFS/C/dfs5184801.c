#include <stdio.h>
#define MAX 101
#define WHITE -1
#define GRAY -2
#define BLACK -3

void DFS();
void visit(int);

int n,time;
int d[MAX],f[MAX],color[MAX];
int Adj[MAX][MAX];

int main(){
  int i,j,u,v,k;

  scanf("%d",&n);
  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      Adj[i][j]=0;
    }
  }

  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    for(j=0;j<k;j++){
      scanf("%d",&v);
      Adj[u][v]=1;
    }
  }

  DFS();
  for(i=1;i<=n;i++) printf("%d %d %d\n",i,d[i],f[i]);
 
  return 0;
}

void DFS(){
  int u;
  for(u=1;u<=n;u++){
    color[u]=WHITE;
  }
  time=0;
  for(u=1;u<=n;u++){
    if(color[u]==WHITE){
      visit(u);
    }
  }
}
void visit(int u){
  int v;

  color[u]=GRAY;
  d[u]= ++time;

  for(v=1;v<=n;v++){
    if(Adj[u][v]==0)continue;		\
    if(color[v]==WHITE) visit(v);
  }
  color[u]=BLACK;
  f[u] = ++time;
}

