#include <stdio.h>
#include <stdlib.h>
#define N 100
#define INF 1000000

void enq(int);
int deq(void);
void bfs(int);

int que[INF],head=0,tail=0;
int n,M[N][N],d[N];
int main(){
  int u,k,v,i,j;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      M[i][j]=0;
    }
  }
  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
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

void bfs(int s){
  int i,u,v;
  enq(s);
  for(i=0;i<n;i++){
    d[i]=INF;
  }
  d[s]=0;
  while(tail!=head){
    u=deq();
    for(v=0;v<n;v++){
      if(M[u][v]==0){
	continue;
      }
      if(d[v]!=INF){
	continue;
      }
      d[v]=d[u]+1;
      enq(v);
    }
  }
  for(i=0;i<n;i++){
    printf("%d ",i+1);
    if(d[i]==INF){
      printf("-1\n");
    }
    else{
      printf("%d\n",d[i]);
    }
  }
}

void enq(int num){
  int next;
  next=(tail+1)%INF;
  if(next==head){
    printf("enq error!!\n");
    exit(1);
  }
  que[tail]=num;
  tail=next;
}

int deq(){
  int val;
  if(tail==head){
    printf("deq error!!\n");
    exit(2);
  }
  val=que[head];
  head=(head+1)%INF;
  return val;
}
/*
void bfs(){
  if((M[][]==0)&&(color[]==W))
}
 */

