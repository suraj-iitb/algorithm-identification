#include <stdio.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define INF (1<<21)
#define N 100
int Q[N+1],d[N+1],color[N+1],M[N+1][N+1];
int head,tail,n;
void bfs(int s){
  int i,u,v;
  head=tail=1;
  Q[tail++]=s;
  for(i=0;i<n;i++){
    d[i]=INF;
  }
  d[s]=0;
  while(head!=tail){
    u=Q[head++];
    for(v=0;v<n;v++){
      if(M[u][v]==WHITE) continue;
      if(d[v]!=INF) continue;
	d[v]=d[u]+1;
	Q[tail++]=v;
    }
  }
  for(i=0;i<n;i++) printf("%d %d\n",i+1,((d[i]==INF)?(-1):d[i]));    
}
int main(){
  int i,j,u,k,v;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    for(j=0;j<n;j++) M[i][j]=0;
  for(i=0;i<n;i++){
    scanf("%d %d",&u,&k);
    u--;
    for(j=0;j<k;j++){
      scanf("%d",&v);
      v--;
      M[u][v]=1;
    }
  }
  bfs(0);
  return 0;
}
