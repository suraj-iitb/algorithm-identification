#include <stdio.h>
#define MAX 105

int queue[100000],g[MAX][MAX],head=0,tail=0,cost[MAX];
void enqueue(int);
int dequeue(void);
void bfs();

int main(){
  int n,i,j,u,k;
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    cost[i]=-1;
    scanf("%d%d",&u,&k);
    for(j=1;j<=k;j++){
      scanf("%d",&g[u][j]);
    }
    g[u][j]=-1;
  }
  bfs();
  for(i=1;i<=n;i++) printf("%d %d\n",i,cost[i]);
  return 0;
}
void enqueue(int id){
  queue[tail]=id;
  tail++;
}
int dequeue(){
  if(head==tail) return -1;
  return queue[head++]; 
}
void bfs(){
  int id,i;
  enqueue(1); cost[1]=0;
  while((id=dequeue())!=-1){
    for(i=1;g[id][i]!=-1;i++){
	if(cost[g[id][i]]==-1){
	  cost[g[id][i]]=cost[id]+1;
	  enqueue(g[id][i]);
	}
    }
  }
}

