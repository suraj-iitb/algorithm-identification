#include<stdio.h>

#define MAX 101
#define INFTY -1
#define WHITE 0
#define GRAY 1
#define BLACK 2

int G[MAX][MAX],d[MAX],color[MAX],n,Q[MAX],head,tail;

void enqueue(int x){
  Q[tail++]=x;
}

int  dequeue(){
  return Q[head++];
}


void bfs(int s){
  int i;
  for(i=1;i<=n;i++){
    d[i]=INFTY;
  }
  d[s]=0;
  color[s]=GRAY;
  enqueue(s);

  while(head!=tail){
    int u=dequeue(),v;
    for(v=1;v<=n;v++){
      if(G[u][v]==1){
      if(color[v]==WHITE){
        color[v]=GRAY;
        d[v]=d[u]+1;
        enqueue(v);
      }
    }
  }
      color[u]=BLACK;
  }
}


int main(){
  int i,j,k,u;
  scanf("%d",&n);

  for(i=0;i<n;i++){
	scanf("%d %d",&u,&k);
	for(j=0;j<k;j++){
  	int v;
  	scanf("%d",&v);
  	G[u][v]=1;
	}
  }
  bfs(1);
  for(i=1;i<=n;i++){
	printf("%d %d\n",i,d[i]);
  }
  return 0;
}


