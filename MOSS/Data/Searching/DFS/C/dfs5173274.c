#include <stdio.h>
#define MAX 100
typedef struct{
  int src,dst;
} Node;
void dfs(int,int,int[MAX][MAX]);
int time,visited[MAX];
Node node[MAX];

int main(){
  int n,u,k,v,i,j;
  int a[MAX][MAX];
  for(i = 0 ; i < MAX ; i++){
    for(j = 0 ; j < MAX ; j++){
      a[i][j] = 0;
    }
  }
  time = 0;
  scanf("%d",&n);
  for(i = 0 ; i < n ; i++){
    scanf("%d%d",&u,&k); u--;
    for(j = 0 ; j < k ; j++){
      scanf("%d",&v); v--;
      a[u][v] = 1;
    }
    visited[i] = 0;
  }
  for(i = 0 ; i < n ; i++){
    if(!visited[i]){
      visited[i] = 1;
      dfs(i,n,a);
    }
  }
  for(i = 0 ; i < n ; i++){
    printf("%d %d %d\n",i+1,node[i].src,node[i].dst);
  }
  return 0;
}

void dfs(int v,int n,int a[MAX][MAX]){
  int i;
  node[v].src = ++time;
  for(i = 0 ; i < n ; i++){
    if(a[v][i] == 0){ continue; }
    if(visited[i] == 1){ continue; }
    visited[i] = 1;
    dfs(i,n,a);
  }
  node[v].dst = ++time;
}

