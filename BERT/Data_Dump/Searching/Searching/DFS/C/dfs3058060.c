#include<stdio.h>
#define M 100
#define WHITE 0
#define BLACK 1
#define GRAY 2

int n;
int G[M][M];
int color[M];
int d[M];
int f[M];
int count = 0;
void visit(int);

int main(){
  void dfs(); 
  int u;
  int v;
  int k;
  int i;
  int j;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      G[i][j] = 0;
    }
  }

  for(i=0;i<n;i++){
    scanf(" %d %d",&u,&k);
    u--;
    for(j=0;j<k;j++){
      scanf(" %d",&v);
      v--;
      G[u][v] = 1;
    }
  }
  dfs();
  return 0;
}

void visit(int r){
  int v;

  color[r] = GRAY;
  d[r] = ++count;
  for(v=0;v<n;v++){
    if(G[r][v] == 0) continue;
    if(color[v] == WHITE) visit(v);
  }
  color[r] = BLACK;
  f[r] = ++count;
}

void dfs(){
  int u;

  for(u=0;u<n;u++){
    color[u] = WHITE;
  }
  count = 0;
  for(u=0;u<n;u++){
    if(color[u] == WHITE) visit(u);
  }
  for(u=0;u<n;u++){
    printf("%d %d %d\n",u+1,d[u],f[u]);
  }
}

