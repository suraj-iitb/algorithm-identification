#include <stdio.h>

#define WHITE 0
#define GRAY 1
#define BLACK 2
#define M 101


void dfs(int);
void visit(int);


int g[M][M];
int color[M];
int d[M];
int f[M];
int time, n;


int main(){
  int u, k, v;
  int i, j;

  scanf("%d", &n);

  for(i = 0; i <= n; i++){
    for(j = 0; j <= n; j++){
      g[i][j] = 0;
    }
  }

  for(i = 1; i <= n; i++){
    scanf("%d", &u);
    scanf("%d", &k);

    for(j = 1; j <= k; j++){
      scanf("%d", &v);

      g[u][v] = 1;
    }
  }

  dfs(n);

  for(i = 1; i <= n; i++) printf("%d %d %d\n", i, d[i], f[i]);

  return 0;
}


void dfs(int u){
  int i;

  for(i = 1; i <= n; i++){
    color[i] = WHITE;
  }

  time = 0;

  for(i = 1; i <= n; i++){
    if(color[i] == WHITE) visit(i);
  }
}


void visit(int u){
  int i;
  int v;
  
  color[u] = GRAY;

  d[u] = ++time;

  for(v = 1; v <= n; v++) {
    if(color[v] == WHITE && g[u][v] == 1) visit(v);
  }

  color[u] = BLACK;

  f[u] = ++time;
}

