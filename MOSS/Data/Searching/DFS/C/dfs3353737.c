#include <stdio.h>
#define MAX 100

int graph[MAX+1][MAX+1];
int d[MAX+1];
int f[MAX+1];

int n;
int t;
void dfs(int id){
  int i;
  if(id!=0)
    t++;
  d[id]=t;
  for(i=1;i<=n;i++) {
    if(graph[id][i] != 0 && d[i] == 0) {
      dfs(i);
    }
  }
  if(id != 0)
    t++;
  f[id] = t;
}

int main() {
  int i,j;
  scanf("%d\n",&n);
  for(i=0;i<=n;i++){
    graph[0][i]=1;
  }
  int u,k,v;
  for(i=0;i<n;i++){
    scanf("%d %d ",&u,&k);
    for(j=0;j<k;j++){
      scanf("%d ",&v);
      graph[u][v]=1;
    }
  }
  dfs(0);
  for(i=1;i<=n;i++) {
    printf("%d %d %d\n",i,d[i],f[i]);
  }
  return 0;
}
