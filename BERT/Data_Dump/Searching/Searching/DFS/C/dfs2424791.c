#include <stdio.h>
#define N 101

int n,t=1;
int a[N][N]={0},d[N]={0},f[N]={0};

void dfs(int u){
  int i;

  d[u]=t++;
  for(i=1;i<=n;i++){
    if(d[i]==0 && a[u][i]==1)
      dfs(i);
  }
  f[u]=t++;
}


int main(void){
  int i,j,u,k,v;

  scanf("%d", &n);
  for(i=1;i<=n;i++){
    scanf("%d%d",&u,&k);
    for(j=1;j<=k;j++){
      scanf("%d",&v);
      a[u][v]=1;
    }
  }

  for(i=1;i<=n;i++){
    if(d[i]==0)
      dfs(i);
  }
  for(i=1;i<=n;i++){
    printf("%d %d %d\n", i, d[i], f[i]);
  }

  return 0;
}
