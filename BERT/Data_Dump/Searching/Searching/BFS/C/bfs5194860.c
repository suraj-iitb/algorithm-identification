#include<stdio.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n,head,tail;
int color[101],d[101],Q[105],G[101][101];

void enqueue(int x){
  if(tail==105)tail=0;
  Q[tail]=x;
  tail++;
}

int dequeue(){
  int y;
  if(head==105)head=0;
  y=Q[head];
  Q[head]=NULL;
  head++;
  return y;
}

void bfs(){
  int i,u,v;
  for(i=1;i<=n;i++){
    color[i]=WHITE;
    d[i]=-1;
  }
  color[1]=GRAY;
  d[1]=0;
  u=1;
  enqueue(1);
  while(u!=NULL){
    u=dequeue();
    for(v=1;v<=n;v++){
      if(G[u][v]==1 && color[v]==WHITE){
        color[v]=GRAY;
        d[v]=d[u]+1;
        enqueue(v);
      }
    }
    color[u]=BLACK;
  }
}
int main(){

  int i,j,k,u,v;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    for(j=0;j<k;j++){
      scanf("%d",&v);
      G[u][v]=1;
    }
  }
  bfs();
  for(i=1;i<=n;i++)printf("%d %d\n",i,d[i]);

  return 0;
}
