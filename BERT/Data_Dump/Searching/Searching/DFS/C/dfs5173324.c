#include<stdio.h>
#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n, M[N][N], c[N], d[N], f[N], t;

void idfs(int u){
  int i;
  
  c[u] = GRAY;
  d[u] = ++t;
  
  for(i = 0; i < n; i++){
      
    if(M[u][i] == 0) continue;
    
    if(c[i] == WHITE){
      idfs(i);
    }
  }
  
  c[u] = BLACK;
  f[u] = ++t;
}

void dfs_init(){
  int i;
  
  for(i = 0; i < n; i++){
    c[i] = WHITE;
  }

  t = 0;
  
  for(i = 0; i < n; i++){
      
    if(c[i] == WHITE ){
      idfs(i);
    }
  }

  for(i = 0; i < n; i++){
    printf("%d %d %d\n", i+1, d[i], f[i]);
  }

}


int main(){
  int i, j, u, k, v;
  
  scanf("%d", &n);

  for(i = 0; i < n; i++){
      
    for(j = 0; j < n; j++){
      M[i][j] = 0;
    }
  }

  for(i = 0; i < n; i++){
    scanf("%d%d", &u, &k);
    
    for(j = 0; j < k; j++){
      scanf("%d", &v);
      M[u-1][v-1] = 1;
    }
  }

  dfs_init();

  return 0;
}

