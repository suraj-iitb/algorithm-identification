#include <stdio.h>

#define WHITE 1
#define GRAY 2
#define BLACK -1

int f[101], d[101], Adj[101][101], time, n;

visit(int *color, int u){
  int v;

  color[u] = GRAY;
  d[u] = ++time;

  for(v=1; v<=n; v++){
    if(Adj[u][v] && color[v] == WHITE){
      visit(color, v);
    }
  }

  color[u] = BLACK;
  f[u] = ++time;
}


dfs(){
  int u, time;
  int color[n+1];

  for(u=1; u<=n; u++){
    color[u] = WHITE;
    time = 0;
  }

  for(u=1; u<=n; u++){
    if(color[u] == WHITE){
      visit(color, u);
    }
  }
}

int main(){
  int i, j, u, k, temp;

  scanf("%d", &n);

  for(i=0; i<n; i++){
    scanf("%d%d", &u, &k);
    for(j=0; j<k; j++){
      scanf("%d",&temp);
      Adj[u][temp] = 1;
    }
  }

  dfs();

  for(i=1; i<=n; i++){
    printf("%d %d %d\n", i, d[i], f[i]);
  }

  return 0;

}
