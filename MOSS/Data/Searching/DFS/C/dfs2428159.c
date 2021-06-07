#include <stdio.h>
int size[101],g[101][101],x[101], y[101], k, d;
void dfs(int z){
  int i;
  x[z] = d++;
  for(i=1;i<=size[z];i++) if(!x[g[z][i]]) dfs(g[z][i]);
  y[z] = d++;
}
 
main(){
  int i, j, a;
  d=1;
  scanf("%d", &k);
  for(i=1;i<=k;i++){
    x[i] = y[i] = 0;
    scanf("%d", &a);
    scanf("%d", &size[a]);
    for(j=1;j<=size[a];j++) scanf("%d", &g[a][j]);
  }
  for(i=1;i<=k;i++){
    if(!x[i]) dfs(i);
  }
  for(i=1;i<=k;i++){
    printf("%d %d %d\n", i, x[i], y[i]);
  }
  return 0;
}
