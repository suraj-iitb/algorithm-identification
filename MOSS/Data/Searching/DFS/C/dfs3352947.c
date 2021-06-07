#include<stdio.h>
#define MAX 110
#define WHITE 0
#define GRAY 1
#define BLACK 2
int n,time;
int dis[MAX],fin[MAX],color[MAX],num[MAX][MAX];
void dfs(void);
void visit(int);

int main(){
  int i,j,k,u,v;

  scanf("%d",&n);
  for(i=1;i<=n;i++){
    scanf("%d%d",&u,&k);
    for(j=1;j<=k;j++){
      scanf("%d",&v);
      num[u][v] = 1;
    }
  }
  dfs();
      
  return 0;
}

void visit(int u){
  int v;
  color[u] = GRAY;
  dis[u] = ++time;
  for(v=1; v<=n; v++){
    if(num[u][v] == 1 && color[v] == WHITE) visit(v);
  }
  color[u] = BLACK;
  fin[u] = ++time;
}

void dfs(){
  int u;//for each vertex u in v. use in this part count "u" convenientry.
  for(u=1;u<=n;u++){
    color[u] = WHITE;
  }
    time = 0;
    for(u=1;u<=n;u++){
      if (color[u] == WHITE) visit(u);
    }
    for(u=1;u<=n;u++){
      printf("%d %d %d\n",u,dis[u],fin[u]);
    }
}


  

