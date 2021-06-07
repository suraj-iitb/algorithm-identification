#include <stdio.h>
#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n,color[N],d[N],f[N],time,A[N][N];
/*d[n]はnが初めて探索された時,                                                  
f[n]はnが探索から抜けた時*/

void visit(int u){
  int i;
  color[u] = GRAY;
  d[u] = ++time;
  for(i = 0; i < n; i++){
    if(A[u][i] == 0) continue;
    if(color[i] == WHITE) visit(i);
  }
    color[u] = BLACK;
    f[u] = ++time;
  }

void dfs(void){
  int u;
  for(u = 0; u < n;u++){
    color[u] = WHITE;
  }
  time = 0;
  for(u = 0; u < n;u++){
    if(color[u] == WHITE) visit(u);
  }
  for(u = 0; u < n; u++){
    printf("%d %d %d\n",u+1,d[u],f[u]);
}
}

int main(void){
  int i,j,u,v,k;/*uは頂点の番号,kはuの出次数,                                   
              vはuに隣接する頂点の番号を示します。*/
  scanf("%d",&n);

  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      A[i][j] = 0;
    }
  }
    for(i = 0; i < n; i++){
      scanf("%d %d",&u,&k);
      for(j = 0; j < k; j++){
        scanf("%d",&v);
        A[u-1][v-1] = 1;
      }
    }
    dfs();
}

