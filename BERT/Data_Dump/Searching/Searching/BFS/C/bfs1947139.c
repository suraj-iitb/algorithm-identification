#include<stdio.h>
 
int n,g[101][101], x[101], y[101];
 
void bfs(int,int);
 
int main(){
  int i, j, m;
 
  scanf("%d",&n);
 
  for(i = 1; i <= n; i++){
    x[i] = 100000000;
    scanf("%d", &m);
    scanf("%d", &y[m]);
 
    for(j=1;j<=y[m];j++) scanf("%d",&g[m][j]);
  }
 
  bfs(1,0);
 
  for(i=1;i<=n;i++){
    if(x[i] == 100000000) x[i] = -1;
  }
 
  for(i=1;i<=n;i++) printf("%d %d\n",i,x[i]);
 
  return 0;
}

void bfs(int a,int b){
  int i;
  x[a]=b;
  for(i=1;i<=y[a];i++){
    if(b+1<x[g[a][i]]) bfs(g[a][i],b+1);
  }
}
