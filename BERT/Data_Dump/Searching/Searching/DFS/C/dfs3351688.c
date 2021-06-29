#include<stdio.h>

#define N 100
#define W 0
#define G 1
#define B 2

int n,M[N][N],c[N],U[N],V[N],t;

void dfs_visit(int a){
  int b;
  c[a] = G;
  U[a] = ++t;

  for(b = 0;b < n;b++){
    if(M[a][b] == 0) continue;
    if(c[b] == W){
      dfs_visit(b);
    }
  }
    c[a] = B;
    V[a] = ++t;
}

void dfs(){
  int u;

  for(u = 0;u < n;u++){
    c[u] = W;
  }

  t = 0;

  for(u = 0;u < n;u++){
    if(c[u] == W)dfs_visit(u);
  }
  for(u = 0;u < n;u++){
    printf("%d %d %d\n",u+1,U[u],V[u]);
  }
}

int main(){
  int a,b,i,j,k;

  scanf("%d",&n);

  for(i = 0;i < n;i++){
    for(j = 0;j < n;j++){
      M[i][j] = 0;
    }
  }

  for(i = 0;i < n;i++){
    scanf("%d%d",&a,&b);
    a--;
    for(j = 0;j < b;j++){
      scanf("%d",&k);
      k--;
      M[a][k] = 1;
    }
  }

  dfs();
  
  return 0;
  
}

