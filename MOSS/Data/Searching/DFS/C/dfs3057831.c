#include <stdio.h>
#define N 100
#define WHITE 0
#define GRAY -1
#define BLACK 1
void dfs(void);
void visit(int);

int V[N+1][N+1];
int color[N+1];
int n;
int d[N+1],f[N+1];
int time;

int main(){
  int i,j,u,k,v;

  scanf("%d",&n);
  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      V[i][j] = 0;
    }
  }
  for(i=1;i<=n;i++){
    scanf("%d%d",&u,&k);
    for(j=0;j<k;j++){
      scanf("%d",&v);
      V[u][v] = 1;
    }
  }
  dfs();
  for(i=1;i<=n;i++){
    printf("%d %d %d\n",i,d[i],f[i]);
  }
  return 0;
}

void dfs(void){
  int u;
  for(u=1;u<=n;u++){
    color[u] = WHITE;
  }
  time = 0;
  for(u=1;u<=n;u++){
    if(color[u] == WHITE)
      visit(u);
  }
}

void visit(int u){
  int i;
  color[u] = GRAY;
  d[u] = ++time;
  for(i=1;i<=n;i++){
    if(V[u][i] == 0) continue;
    if(color[i] == WHITE) 
      visit(i);
  }
  color[u] = BLACK;
  f[u] = ++time;
}

