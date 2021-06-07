#include <stdio.h>
#define N 100

int A[N],d[N],f[N],tt,i;
int n,G[N][N];

void dfs_visit(int u){
  int t;
  A[u] = 1;
  d[u] = tt++;
  for(t=0;t<n;t++){
    if(G[u][t] == 1 && A[t] == 0) {
      dfs_visit(t);
    }
  }
  A[u] = 2;
  f[u] = tt++;
}

void dfs(void){

  for(i=0;i<n;i++) A[i] = 0;
  tt = 1;

  for(i=0;i<n;i++){
    if(A[i] == 0) dfs_visit(i);
  }
  for(i=0;i<n;i++){
    printf("%d %d %d\n",i+1,d[i],f[i]);
  }
}


int main(){
  int j,u,k,v;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      G[i][j] = 0;
    }
  }

  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    u--;
    for(j = 0; j < k;j++){
      scanf("%d",&v);
      v--;
      G[u][v] = 1;
    }
  }
  dfs();

  return 0;
}

