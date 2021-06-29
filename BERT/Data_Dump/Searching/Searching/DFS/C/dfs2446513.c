#include <stdio.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2
void dfs(void);
void dfsv(int);
int graph[101][101],color[101],n,time,d[101],f[101];
int main(){
  int i,u,k,j,v;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
      for(j=0;j<k;j++){
	scanf("%d",&v);
	graph[u-1][v-1]=1;
      }
      }
  dfs();

  for(i=0;i<n;i++){
    printf("%d %d %d\n",i+1,d[i],f[i]);
  }

  return 0;
}

void dfs(){
  int i;
  for(i=0;i<n;i++) color[i]=WHITE;
  time=0;
  for(i=0;i<n;i++){
    if(color[i]==0)dfsv(i);
  }
 

}

void dfsv(int u){
  int i;
  color[u]=GRAY;
    d[u]=++time;
    for(i=0;i<n;i++){
      if(graph[u][i]==0)continue;
      if(color[i]==0) dfsv(i);
    }
    color[u]=BLACK;
    f[u]=++time;
}
