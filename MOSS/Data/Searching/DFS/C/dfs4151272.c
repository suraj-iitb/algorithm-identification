#include <stdio.h>
#define MAX 100
int g[MAX][MAX],d[MAX],f[MAX],t=1;

void dfs(int i){
  int j;
  if(d[i] == 0){
    d[i] = t;
    t++;
    for(j = 1; g[i][j] != -1; j++) if(d[g[i][j]] == 0) dfs(g[i][j]);
    f[i] = t;
    t++;
  }
}

int main(){
  int n,i,j,u,k;
  scanf("%d",&n);
  for(i = 1; i <= n; i++){
    scanf("%d%d",&u,&k);
    for(j = 1; j <= k; j++) scanf("%d",&g[i][j]);
    g[i][j] = -1;
  }
  for(i = 1; i <= n; i++) dfs(i);
  for(i = 1; i <= n; i++) printf("%d %d %d\n",i,d[i],f[i]);
  return 0;
}

