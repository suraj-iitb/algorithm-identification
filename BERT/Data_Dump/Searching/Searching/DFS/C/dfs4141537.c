#include <stdio.h>
#define N 100
void dep(int);
int G[N+1][N+1],s[N+1],de[N+1],f[N+1],n,w=1;
int  main(){
  int i, j, u, v;
  scanf("%d", &n);
  for(i=1;i<=n;i++){
    de[i]=0;
    f[i] = 0;
    scanf("%d", &u);
    scanf("%d", &s[u]);
    for(j=1;j<=s[u];j++) scanf("%d", &G[u][j]);
  }
  for(i=1;i<=n;i++) {
    if(!de[i]) dep(i);
  }
  for(i=1;i<=n;i++) {
    printf("%d %d %d\n", i, de[i], f[i]);
  }
  return 0;
}
void dep(int p){
  int i;
  de[p] = w++;
  for(i=1;i<=s[p];i++) {
    if(!de[G[p][i]]) dep(G[p][i]);
  }
  f[p] = w++;
}
