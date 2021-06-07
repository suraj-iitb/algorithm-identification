#include <stdio.h>
#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n, t=0, color[N], d[N], f[N], M[N][N]; 

void visit(int u){

  int i;
  
  color[u] = GRAY;
  d[u] = ++t;
  for(i=0; i<n; i++){
    if(M[u][i] == 0) continue;
    if(color[i] == WHITE){
       visit(i);
    }
  }
  color[u] = BLACK;
  f[u] = ++t;

}

void dfs(){

  int i;
  
  for(i=0; i<n; i++){
    color[i] = WHITE;
  }
  t = 0;
  for(i=0; i<n; i++){
    if(color[i] == WHITE){
      visit(i);
    }
  }
  
}

int main(){

  int i, j, u, k, v;

  scanf("%d", &n);
  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      M[i][j] = 0;
    }
  }

  for(i=0; i<n; i++){
    scanf("%d%d", &u, &k);
    u--;
    for(j=0; j<k; j++){
      scanf("%d", &v);
      v--;
      M[u][v] = 1;
    }
  }

  dfs();

  for(i=0; i<n; i++){
      printf("%d %d %d\n", i+1, d[i], f[i]); 
  }

  return 0;
}
