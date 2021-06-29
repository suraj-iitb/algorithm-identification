#include<stdio.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define N 100

void dfs(int);
void dfs_visit(int,int);

int n,t;
int M[N][N];
int color[N],d[N],f[N];

int main(){
  int i,j,k,u,v;
  scanf("%d",&n);
  for(i = 0;i < n;i++){
    for(j = 0;j < n;j++){
      M[i][j] = 0;
    }
  }
  for(i = 0;i < n;i++){
    scanf("%d%d",&u,&k);
    u--;
    for(j = 0;j < k;j++){
      scanf("%d",&v);
      M[u][v-1] = 1;
    }
  }
  dfs(n);
  return 0;
}

void dfs(int n){
  int u;
  for(u = 0;u < n;u++){
    color[u] = WHITE;
  }
  t = 0;
  for(u = 0;u < n;u++){
    if(color[u] == WHITE)dfs_visit(u,n);
  }
  for(u = 0;u < n;u++){
    printf("%d %d %d\n",u+1,d[u],f[u]);
  }
}

void dfs_visit(int u,int n){
  int v;
  color[u] = GRAY;
  d[u] = ++t;
  for(v = 0;v < n;v++){
    if(M[u][v] == 0)continue;    
    if(color[v] == WHITE)dfs_visit(v,n);
  }
  color[u] = BLACK;
  f[u] = ++t;
}

