#include<stdio.h>
#define MAX 100
#define white 0
#define gray 1
#define black 2

int t,n,g[MAX][MAX] = {0};
int d[MAX],f[MAX],color[MAX] = {white};
void dfs(void);
void visit(int);

int main(){
  int i,j,u,k,v;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d %d",&u,&k);
    for(j=0;j<k;j++){
      scanf("%d",&v);
      g[u-1][v-1] = 1;
    }
  }
  dfs();
  return 0;
}

void dfs(){
  int u;
  t = 0;
  for(u=0;u<n;u++)
    if(color[u] == white)visit(u);
  for(u=0;u<n;u++)
    printf("%d %d %d\n",u+1,d[u],f[u]);
}

void visit(int u){
  int v;
  color[u] = gray;
  d[u] = ++t;
  for(v=0;v<n;v++){
    if(g[u][v] == 0)continue;
    if(color[v] ==white)visit(v);
  }
  color[u] = black;
  f[u] = ++t;
}
