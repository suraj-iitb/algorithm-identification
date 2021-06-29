#include<stdio.h>

#define WHITE 0
#define GRAY 1
#define BLACK 2
#define N 100

int n ,M[N][N], time;
int color[N], d[N], f[N];

void dfs_search(int i){

  int j;

  color[i] = GRAY;
  d[i] = ++time;

  for(j = 0; j < n; j++){

    if(M[i][j] == 0){
      continue;
    }

    if(color[j] == WHITE){
      dfs_search(j);
    }
  }

  color[i] = BLACK;
  f[i] = ++time;
}
void dfs(){

int i;

  for(i = 0; i < n; i++){
    color[i] = WHITE;
    time = 0;
  }

  for(i = 0; i < n; i++){

    if(color[i] == WHITE){
      dfs_search(i);
    }
  }

  for(i = 0; i < n; i++){
    printf("%d %d %d\n", i+1, d[i], f[i]);
  }
}

int main(){

  int i, j, k, u, v;

  scanf("%d",&n);

  for(i = 0; i < n ; i++){
    for(j = 0; j < n; j++)
      M[i][j] = 0;
  }
  for(i = 0; i < n; i++){
    scanf("%d %d", &u, &k);

    u--;
    for(j = 0; j < k; j++){
         scanf("%d", &v);

      v--;
      M[u][v] = 1;
    }
  }

  dfs();
  
  return 0;
}
