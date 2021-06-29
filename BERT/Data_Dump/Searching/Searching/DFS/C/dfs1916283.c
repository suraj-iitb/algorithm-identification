#include <stdio.h>
#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

void dfs(void);
void visit(int);
int n,time,d[N],f[N],color[N],M[N][N] = {};

int main(){
int i,j,u,k,v;

  scanf("%d",&n);
  
  for(i=0; i<n; i++){
    scanf("%d",&u);
    scanf("%d",&k);
    for(j=0; j<k; j++){
      scanf("%d",&v);
      M[u-1][v-1] = 1;   
    }
  }

  dfs();

  for(u=0; u<n;u++)
    printf("%d %d %d\n",u+1,d[u],f[u]);
  
  return 0;
}

void dfs(){
  int u;

  for(u=0; u<n; u++){
    color[u] = WHITE;
  }

  time = 0;

  for(u=0; u<n; u++){
    if(color[u] == WHITE)
      visit(u);
  }

}

void visit(int u){
  int v;

  color[u] = GRAY;
  d[u] = ++time;

  for(v=0; v<n; v++){
    if(M[u][v] == 0)
      continue;
    if(color[v] == WHITE)
      visit(v);
  }

  color[u] = BLACK;
  f[u] = ++time;
}
