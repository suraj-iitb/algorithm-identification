#include<stdio.h>
#include<stdlib.h>
#define QSIZE 100
#define INFTY 1<<21

void enqueue(int);
int dequeue(void);
void bfs(int);

int queue[QSIZE];
int head=0;
int tail=0;
int n,A[QSIZE][QSIZE],d[QSIZE];

int main()
{
  int i,j,x,y,z;
  scanf("%d",&n);
  
  for(i=0;i<n;i++){
    for(j=0;j<n;j++)A[i][j]=0;}

  for(i=0;i<n;i++){
    scanf("%d%d",&x,&y);
    for(j=0;j<y;j++){
      scanf("%d",&z);
      A[x-1][z-1]=1;}
  }

  bfs(0);
  return 0;
}

void enqueue(int num)
{
  int next=(tail+1)%QSIZE;
  if(next==head){
    printf("Queue is overflow\n");
    exit(2);}
  queue[tail]=num;
  tail=next;
}

int dequeue(void)
{
  int val;
  if(head==tail){
    printf("queue is empty\n");
    exit(3);}
  val=queue[head];
  head=(head+1)%QSIZE;
  return val;
}

void bfs(int s)
{
  int i,u,v;
  enqueue(s);
  for(i=0;i<n;i++)d[i]=INFTY;
  d[s]=0;
  while(head!=tail)
    {
      u=dequeue();
      for(v=0;v<n;v++){
	if(A[u][v]==0)continue;
	if(d[v]!=INFTY)continue;
	d[v]=d[u]+1;
	enqueue(v);
      }
    }
  for(i=0;i<n;i++){
    printf("%d ",i+1);
    if(d[i]==INFTY)printf("%d",-1);
    else printf("%d",d[i]);
    printf("\n");
  }
}

