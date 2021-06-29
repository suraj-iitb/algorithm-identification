#include<stdio.h>
#define WHITE 1
#define GRAY 2
#define BLACK 3

void dfs(void);
void visit(int);

int n ,t;
int V[102][102], d[102], f[102], color[102];

int main(){
  int i, j, k, l, m;
  scanf("%d", &n);
  for(i = 1 ; i <= n ; i++){
    scanf("%d %d", &j, &k);
    for(l = 1 ; l <= k ; l++){
      scanf("%d", &m);
      V[j][m] = 1;
    }
  }
  dfs();
  for(i = 1 ; i <= n ; i++){
    printf("%d %d %d\n", i, d[i], f[i]);
  }
  return 0;
}

void dfs(void){
  int u;
  for(u = 1 ; u <= n ; u++) color[u] = WHITE;
  t = 0;
  for(u = 1 ; u <= n ; u++) if(color[u] == WHITE) visit(u);
}

void visit(int u){
  int v;
  color[u] = GRAY;
  d[u] = ++t;
  for(v = 1 ; v <= n ; v++){
    if(color[v] == WHITE && V[u][v] == 1) visit(v);
  }
  color[u] = BLACK;
  f[u] = ++t;
}

