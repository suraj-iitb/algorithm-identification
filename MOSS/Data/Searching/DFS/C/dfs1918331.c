#include <stdio.h>

int G = 1, n;
int c[101][101], d[101]={0};
int first[101], second[101];

void DFS(int u);

int main(){
  int i, j, k, u, v;
  scanf("%d",&n);

  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      c[i][j] = 0;
    }
  }

  for(i = 0; i < n; i++){
    scanf("%d%d", &u, &k);
    for(j = 0; j < k; j++){
      scanf("%d", &v);
      c[u-1][v-1] = 1;
    }
  }

  for(i = 0; i < n; i++){
    if(d[i] == 0){
      DFS(i);
    }
  }

  for(i = 0; i < n; i++){
    printf("%d %d %d\n", i+1, first[i], second[i]);
  }
  return 0;
}

void DFS(int u){
  int v; 
  first[u] = G++;
  d[u] = 1;
  for(v = 0; v < n; v++){
    if(c[u][v]==1 && d[v]==0){ 
      DFS(v);
    }
  }   
  second[u] = G++;  
}
