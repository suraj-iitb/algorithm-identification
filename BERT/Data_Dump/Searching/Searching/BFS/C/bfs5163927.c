#include <stdio.h>

#define N 100
#define INFTY 10000000

int n, M[N+1][N+1], k[N+1];
int d[N+1];

void bfs(int p, int t){
  int i;
  d[p] = t;
  for(i=1;i<=k[p];i++) 
    if(t+1 < d[M[p][i]]) bfs(M[p][i], t+1);
}

int main(){
  int u, v, i;

  scanf("%d", &n);

  for(i=1;i<=n;i++){
    d[i] = INFTY;
    scanf("%d", &u);
    scanf("%d", &k[u]);
    for(int j=1;j<=k[u];j++){
      scanf("%d", &M[u][j]);
    }
  }

  bfs(1, 0);
  for(i=1;i<=n;i++) printf("%d %d\n", i, (d[i] == INFTY) ? (-1) : d[i]);
  
  return 0;
}


