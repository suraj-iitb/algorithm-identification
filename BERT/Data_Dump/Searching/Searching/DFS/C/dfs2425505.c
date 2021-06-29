#include<stdio.h>
#define N 100
#define WHITE 0
#define GRAY 1
#define BLUE 2

void dfs(void);
void visit(int);

int time,d[N],f[N],G[N][N],color[N],n;

int main(){
  int i,j,u,k,v;
  scanf("%d",&n);

  for(i = 0;i < n;i++){
    for(j = 0;j < n;j++){
      G[i][j]=0;
    }
  }

  for(i = 0;i < n;i++){
    scanf("%d%d",&u,&k);
    for(j = 0;j < k;j++){
      scanf("%d",&v);
      G[u-1][v-1]=1;
    }
  }
  dfs();
  return 0;
}

void visit(int u){
  int v;
  color[u] = GRAY;
  d[u] = ++time;
  for(v = 0;v < n;v++){
    if(G[u][v]==0)continue;
    if(color[v] == WHITE){
      visit(v);
    }
  }
  color[u] = BLUE;
  f[u] = ++time;
}

void dfs(){
  int u;
  for(u = 0;u < n;u++){
    color[u] = WHITE;
  }
  time=0;

  for(u = 0;u < n;u++){
    if(color[u]==WHITE){
      visit(u);
    }
  }
  for(u = 0;u < n;u++){
    printf("%d %d %d\n",u+1,d[u],f[u]);
  }
}
