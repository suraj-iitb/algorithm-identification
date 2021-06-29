#include <stdio.h>
int queue[1000];
int head=0;
int tail=0;
int n;
int adj[101][101];
int d[101];
int used[101];
void push(int x){
  queue[head]=x;
  head++;
}
int pop(){
  int x;
  x=queue[tail];
  tail++;
  return x;
}
void bfs(int x){
  int i;
  int v;
  push(x);
  used[x]=1;
  while(head!=tail){
    // for(i=tail;i<head;i++)printf("%d ",queue[i]);
    // printf("\n");
    v=pop();
    for(i=1;i<=n;i++){
      if(adj[v][i]==1 && used[i]==0){
	push(i);
	d[i]=d[v]+1;
	used[i]=1;
      }
    }
  }
}
int main(){
  int i,j;
  int u,k,v;
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    scanf("%d %d",&u,&k);
    for(j=0;j<k;j++){
      scanf("%d",&v);
    adj[u][v]=1;
    }
  }

  for(i=1;i<=n;i++)d[i]=0;
  bfs(1);
  for(i=2;i<=n;i++){
    if(d[i]==0)d[i]=-1;
  }
  for(i=1;i<=n;i++)printf("%d %d\n",i,d[i]);
  return 0;
}
