#include<stdio.h>

#define MAX 105
#define WHITE 0
#define GRAY 1
#define BLACK 2

void dfs(void);
void visit(int);
  
int m[MAX][MAX];
int d[MAX];
int f[MAX];
int color[MAX];
int n;
int time;
  
int main(){
  
  int i,j,u,k,ne;
  
  scanf("%d",&n);
  for(i = 1; i <= n; i++){
    for(j = 1; j <= n; j++){
      m[i][j] = 0;
    }
  }
  for(i = 1; i <= n;i++){
    scanf("%d",&u);
    scanf("%d",&k);
    for(j = 1; j <= k; j++){
      scanf("%d",&ne);
      m[i][ne] = 1;
    }
  }
  dfs();
  for(i = 1; i <= n; i++){
    printf("%d %d %d\n",i,d[i],f[i]);
  }
  
  return 0;
}
void dfs(void){
  
  int u;
  
  for(u = 1; u <= n; u++){
    color[u] = WHITE;
  }
  time = 0;
  for(u = 1; u <= n; u++){
    if(color[u] == WHITE) visit(u);
  }
}
void visit(int u){
  
  int v;
  
  color[u] = GRAY;
  d[u] = ++time;
  for(v = 1; v <= n; v++){
    if(m[u][v] == 1 && color[v] == WHITE) visit(v);
  }
  color[u] = BLACK;
  f[u] = ++time;
}
