#include<stdio.h>
#define N 501

static const int INFTY = (1<<21);
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

int n,M[N][N],color[N],d[N],f[N],tt;

void dfs_visit(int u){
  int v;

  color[u] = GRAY;
  tt++;
  d[u] = tt;
  for(v = 0;v < n;v++){
    if(M[u][v] == 0) continue;
    if(color[v] == WHITE){
      dfs_visit(v);
    }
  }
  
  color[u] = BLACK;
  f[u] = ++tt;
}

void dfs(){
  int i;

  for(i = 0;i < n;i++){
    color[i] = WHITE;
  }
  
  tt = 0;

  for(i = 0;i < n;i++){
    if(color[i] == WHITE){
      dfs_visit(i);
    }
  }

  for(i = 0;i < n;i++){
    printf("%d %d %d\n",i + 1,d[i],f[i]);
  }
}

int main(){
  int u,k,v,i,j;

  scanf("%d",&n);

  for(i = 0;i < n;i++){
    for(j = 0;j < n;j++){
      M[i][j] = 0;
    }
  }

  for(i = 0;i < n;i++){
    scanf("%d %d",&u,&k);
    u--;

    for(j = 0;j < k;j++){
      scanf("%d",&v);
      v--;
      M[u][v] = 1;
    }
  }

  dfs();
  
  return 0;
}

