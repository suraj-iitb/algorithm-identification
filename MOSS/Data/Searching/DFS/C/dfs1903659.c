#include <stdio.h>
#define W 0
#define G 1
#define B 2

int n,M[100][100];
int color[100],d[100],f[100],count=0;

void serch(int u){
  int v;
  color[u] = G;
  d[u] = ++count;

  for(v=0;v<n;v++){
    if(M[u][v] == 0){
      continue;
    }
    if(color[v] == W){
      serch(v);
    }
  }
  color[u] = B;
  f[u] = ++count;
}

void dfs(){
  int u;

  for(u=0;u<n;u++){
    color[u] = W;
  }
  count = 0;
  
  for(u=0;u<n;u++){
    if(color[u] == W){
      serch(u);
    }
  }

  for(u=0;u<n;u++){
    printf("%d %d %d\n",u+1,d[u],f[u]);
  }
}

int main(){
  int u,v,k,i,j;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      M[i][j] = 0;
    }
  }

  for(i=0;i<n;i++){
    scanf("%d %d",&u,&k);
    u--;
    for(j=0;j<k;j++){
      scanf("%d",&v);
      v--;
      M[u][v] = 1;
    }
  }

  dfs();

  return 0;
} 
