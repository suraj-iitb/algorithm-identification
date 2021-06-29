#include<stdio.h>

#define N 101

void DFS(int);

int Adj[N][N],Dfs[N],d[N],f[N];
int n,count=1;

int main( ){
  int i,j,k,l,v,u;

  scanf("%d",&n);

  Dfs[0] = 0;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      Adj[i][j]=0;
    }
  }

  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    u--;
    for(j=0;j<k;j++){
      scanf("%d",&v);
      v--;
      Adj[u][v] = 1;
    }
  }

  for(i=0;i<n;i++){
    if(Dfs[i]==0){
      DFS(i);
    }
  }
    for(i=0;i<n;i++){
      printf("%d %d %d\n",i+1,d[i],f[i]);
    }
    return 0;
  }

  
void DFS(int x) {
  int y;

  d[x] = count++;
  Dfs[x] = 1;
  for(y = 0 ; y < n ; y++) {
    if(Adj[x][y] == 1 && Dfs[y] == 0) {
      DFS(y);
    }
  }
  f[x] = count++;
}
  

