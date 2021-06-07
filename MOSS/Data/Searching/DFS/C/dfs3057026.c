#include <stdio.h>
#define MAX 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

void visit(int);
void dfs();
int n,a[MAX+1][MAX+1],color[MAX+1],d[MAX+1],f[MAX+1],t=0;

int main(){
  int i,j,u,k,v;

  scanf("%d",&n);

  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      a[i][j]=0;
    }
  }

  for(i=1;i<=n;i++){
    scanf("%d%d",&u,&k);
    for(j=1;j<=k;j++){
      scanf("%d",&v);
      a[u][v]=1;
    }
  }

  dfs();

  for(i=1;i<=n;i++){
    printf("%d %d %d\n",i,d[i],f[i]);
  }
  return 0;
}

void visit(int u){
  int v;

  color[u]=GRAY;
  d[u]=++t;
  
  for(v=1;v<=n;v++){
    if(a[u][v]==0) continue;
    if(color[v]==WHITE) visit(v);
  }
  color[u]=BLACK;
  f[u]=++t;
}

void dfs(){
  int u;
  for(u=1;u<=n;u++){
    color[u]=WHITE;
  }
  t=0;

  for(u=1;u<=n;u++){
    if(color[u]==WHITE) visit(u);
  }
}
