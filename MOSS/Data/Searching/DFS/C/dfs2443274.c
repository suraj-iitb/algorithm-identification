#include <stdio.h>

#define WHITE 0
#define GRAY 1
#define BLACK 2
#define N 101

void dv(int);
void dfs();

int n;
int M[N][N];
int cl[N],d[N],f[N],tt;

int main(){
  int i,j,u,k,v;

  scanf("%d",&n);
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      M[i][j] = 0;
    }
  }

  for(i = 0; i < n; i++){
    scanf("%d%d",&u,&k);
    u--;
    for(j = 0; j < k; j++){
      scanf("%d",&v);
      v--;
      M[u][v] = 1;
    }
  }
  dfs();
  return 0;
}

void dv(int u){
  int v;

  cl[u] = GRAY;
  d[u] = ++tt;

  for(v = 0; v < n; v++){
    if(M[u][v] == 0) continue;
    if(cl[v] == WHITE){
      dv(v);
    }
  }
  cl[u] = BLACK;
  f[u] = ++tt;
}

void dfs(){
  int u;
  for(u = 0; u < n; u++){
    cl[u] = WHITE;
  }
  tt = 0;

  for (u = 0; u < n; u++){
    if(cl[u] == WHITE) dv(u);
  }
  for (u = 0; u < n; u++){
    printf("%d %d %d\n",u+1,d[u],f[u]);
  }
}
    
