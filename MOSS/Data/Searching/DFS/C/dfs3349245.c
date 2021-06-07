#include<stdio.h>

#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

void dfs_visit(int);
void dfs();

int g_n, g_M[N][N];
int g_color[N], d[N], f[N], count;

int main(){
  int u,v,k,i,j;

  scanf("%d",&g_n);
  for(i = 0; i < g_n; i++){
    for(j = 0; j < g_n; j++){
      g_M[i][j] = 0;
    }
  }
  for(i = 0; i < g_n; i++){
    scanf("%d %d", &u, &k);
    u--;
    for(j = 0; j < k; j++){
      scanf("%d",&v);
      v--;
      g_M[u][v] = 1;
    }
  }

  dfs();
  
  return 0;
}

void dfs_visit(int u){
  int v;
  g_color[u] = GRAY;
  d[u] = ++count;
  for(v = 0; v < g_n; v++){
    if(g_M[u][v] == 0) continue;
    if(g_color[v] == WHITE) dfs_visit(v);
  }
  g_color[u] = BLACK;
  f[u] = ++count;
}

void dfs(){
  int u;
  for(u = 0; u < g_n; u++) g_color[u] = WHITE;
  count = 0;

  for(u = 0; u < g_n; u++){
    if(g_color[u] == WHITE) dfs_visit(u);
  }
  for(u = 0; u < g_n; u++){
    printf("%d %d %d\n",u+1, d[u], f[u]);
  }
}

