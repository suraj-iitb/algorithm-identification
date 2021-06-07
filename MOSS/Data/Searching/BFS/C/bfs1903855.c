#include <stdio.h>
#define MAX 100
#define INF 1<<21
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n,A[MAX][MAX],dis[INF];
int head,tail,color[MAX];
int Q[MAX];

void bfs(void);
void enqueue(int);
int dequeue(void);

int main(){
  int i,j,u,v,k;
  scanf("%d",&n);

  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      A[i][j]=0;
    }
  }

  for(i=0;i<n;i++){
    scanf("%d %d",&u,&k);
    u--;
    for(j=0;j<k;j++){
      scanf("%d",&v);
      v--;
      A[u][v]=1;
    }
  }

  bfs();

  return 0;
}

void bfs(){
  int i,j,s=0;

  for(i=0;i<n;i++){
    color[i]=WHITE;
    dis[i]=INF;
  }
  dis[s]=0;
  head=0;
  tail=0;
  enqueue(s);
  
  while(head!=tail){
    i=dequeue();
    for(j=0;j<n;j++){
      if(A[i][j] && color[j]==WHITE){
	color[j]=GRAY;
	dis[j]=dis[i]+1;
	enqueue(j);
      }
      color[i]=BLACK;
    }
  }
  for(i=0;i<n;i++){
    if(dis[i]==INF) dis[i]=-1;
  }
  for(i=0;i<n;i++){
    printf("%d %d\n",i+1,dis[i]);
    }
}

void enqueue(int s){
   Q[tail]=s;
  if(tail+1==MAX){
    tail=0;
  }
  else tail++;
}

int dequeue(){
  int i;

  i=Q[head];
  if(head+1==MAX){
    head=0;
  }
  else head++;
  return i;
}
