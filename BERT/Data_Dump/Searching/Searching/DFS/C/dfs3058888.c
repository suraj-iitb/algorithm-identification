#include <stdio.h>

int n;
int A[101][101];
int B[101],d[101],f[101];
int u,v,k,time;

void visit(int u){
  int i;
  B[u] = 1;
  d[u] = ++time;
  for(i=1;i<=n;i++){
    if(A[u][i]==0){continue;}
    if(B[i]==0){
      visit(i);
    }
  }
  B[u] = 2;
  f[u] = ++time;
}

void dfs(){
  int i;
  for(i=1;i<=n;i++){
    B[i] = 0;
  }
  time = 0;

  for(i=1;i<=n;i++){
    if(B[i]==0){
      visit(i);
    }
  }
  for(i=1;i<=n;i++){
    printf("%d %d %d\n",i,d[i],f[i]);
  }
}

int main(){
  int i,j;

  scanf("%d",&n);

  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      A[i][j] = 0;
    }
  }

  for(i=1;i<=n;i++){
    scanf("%d %d",&u,&k);
    for(j=1;j<=k;j++){
      scanf("%d",&v);
      A[u][v] = 1;
  }
}
dfs();

return 0;
}

