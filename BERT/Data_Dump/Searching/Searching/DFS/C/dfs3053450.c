#include<stdio.h>

#define N 101

void DFS(int);

int n,G[N][N],dfs[N],d[N],f[N],count=1;

int main() {
  int i,j,u,k,v;

  scanf("%d",&n);

  dfs[0] = 0;
  for(i = 0 ; i < n ; i++){
    for(j = 0 ; j < n ; j++) {
      G[i][j] = 0;
    }
  }

  for(i = 0 ; i < n ; i++) {
    scanf("%d%d",&u,&k);
    u--;
    for(j = 0 ; j < k ; j++) {
      scanf("%d",&v);
      v--;
      G[u][v] = 1;
    }
  }

  for(i = 0 ; i < n ; i++) {
    if(dfs[i] == 0) {
      DFS(i);
    }
  }

  for(i = 0 ; i < n ; i++) {
    printf("%d %d %d\n",i+1,d[i],f[i]);
  }
  return 0;
}

void DFS(int x) {
  int y;

  d[x] = count++;
  dfs[x] = 1;
  for(y = 0 ; y < n ; y++) {
    if(G[x][y] == 1 && dfs[y] == 0) {
      DFS(y);
    }
  }
  f[x] = count++;
}

