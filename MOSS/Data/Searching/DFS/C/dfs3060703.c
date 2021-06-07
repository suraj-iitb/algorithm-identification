#include <stdio.h>
#define N 100
#define W 0
#define G 1
#define B 2

int n,t;
int co[N], d[N], f[N], M[N][N];

void dfs1(int);
void dfs2();

int main(){
  int i,j,k,u,v;

  scanf("%d", &n);
  for(i = 0 ; i < n; i++){
    for(j = 0 ; j < n ; j++){
      M[i][j] = 0;
    }
  }
  for(i = 0 ; i < n ; i++){
    scanf("%d%d",&u,&k);
    for(j = 0 ; j < k ; j++){
      scanf("%d",&v);
      M[u-1][v-1] = G;
    }
  }
  dfs2();

  return 0;
}

void dfs1(int u){
  int i;

  co[u] = G;
  d[u] = ++t;

  for(i = 0 ; i < n; i++){
    if(M[u][i] == 0){
       continue;
    }
    if(co[i] == 0){
       dfs1(i);
    }
  }

  co[u] = B;
  f[u] = ++t;
}

void dfs2(){
  int i;

  for(i = 0; i < n; i++){
    co[i] = 0;
  }

  t = W;

  for(i = 0 ; i < n; i++){
    if(co[i] == 0){
      dfs1(i);
    }
  }

  for(i = 0; i < n; i++){
    printf("%d %d %d\n",i+1,d[i],f[i]);
  }
}

