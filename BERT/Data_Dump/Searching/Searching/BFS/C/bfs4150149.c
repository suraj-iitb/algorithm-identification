#include <stdio.h>
#include <stdlib.h>
#define N 100
#define INF (1<<21)
#define QSIZE 100005

int queue[QSIZE];
int head=0,tail=0;
int n,M[N][N];
int d[N];

void enqueue(int y)
{
int next=(tail+1)%QSIZE;
if(next==head){
  printf("Queue overflow\n");
  exit(2);
}
queue[tail]=y;
tail=next;
}

int dequeue(void)
{
  int x;
  if(head ==tail){
    printf("Queue is empty\n");
    exit(3);
  }
  x=queue[head];
  head=(head+1)%QSIZE;
  return x;
}



void bfs(int s)
{
  int i,u,v;

  enqueue(s);
  for(i=0;i<n;i++){
    d[i]=INF;
  }
  d[s]=0;
  while(head !=tail){
    u=queue[head];
    dequeue();
    for(v=0;v<n;v++){
      if(M[u][v]==0) continue;
      if(d[v]!=INF) continue;
      d[v]=d[u]+1;
      enqueue(v);
    }
  }
for(i=0;i<n;i++){
  printf("%d %d\n",i+1,((d[i]==INF)?(-1):d[i]));
}
}

int main(){
  int i,j,u,k,v;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      M[i][j]=0;
    }
  }
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
