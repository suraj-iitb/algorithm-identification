#include<stdio.h>
#define N 101
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n,a[N][N],color[N],d[N],f[N],time;
void dfs(void);
void visit(int);

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
    for(j=0;j<k;j++){
      scanf("%d",&v);
      a[u][v]=1;
    }
  }

  dfs();
  return 0;
}


void dfs(void){
  int u;
  
  for(u=1;u<=n;u++){
    color[u]=WHITE;
  }
  time=0;
  for(u=1;u<=n;u++){
    if(color[u]==WHITE)
      visit(u);
  }
  for(u=1;u<=n;u++){
    printf("%d %d %d\n",u,d[u],f[u]);
  }
}


void visit(int u){
  int v;

  color[u]=GRAY;
  d[u]=++time;
  for(v=1;v<=n;v++){
    if(a[u][v]==0)
      continue;
    if(color[v]==WHITE)
      visit(v);
  }
  color[u]=BLACK;
  f[u]=++time;
}
