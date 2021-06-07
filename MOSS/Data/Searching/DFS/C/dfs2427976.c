#include <stdio.h>
#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2
void dfs_visit(int);
void dfs(void);
int n,M[N][N]={},color[N],o[N],e[N],count;

void dfs_visit(int u){
  int v;
  
  color[u]=GRAY;
  o[u]=++count;

  for(v=0;v<n;v++){
    if(M[u][v]==0) continue;
    if(color[v]==WHITE) dfs_visit(v);
  }

  color[u]=BLACK;
  e[u]=++count;
}

void dfs(void){
  int u;
  
  for(u=0;u<n;u++) color[u]=WHITE;
  count=0;

  for(u=0;u<n;u++){
    if(color[u]==WHITE) dfs_visit(u);
  }

  for(u=0;u<n;u++){
    printf("%d %d %d\n",u+1,o[u],e[u]);
  }
}

int main()
{
  int u,v,k,i,j;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d %d",&u,&k);
    u--;
    for(j=0;j<k;j++){
      scanf("%d",&v);
      v--;
      M[u][v]=1;
    }
  }

  dfs();

  return 0;
}
