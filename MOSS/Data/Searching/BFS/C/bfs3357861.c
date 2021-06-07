#include<stdio.h>
#include<stdlib.h>
#define N 100
#define STILL 0
#define CONTE 1
#define FINISH 2
#define INFINITY 2000000000
#define Q_SIZE 10000

void search(int);
void enqueue(int);
int dequeue(void);

int n;
int G[N+1][N+1],state[N+1],dis[N+1],Q[Q_SIZE];
int head=0, tail=0;

int main(){
  int u,k,v,i,j;

  scanf("%d",&n);

  //初期化
  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      G[i][j]=0;
    }
  }

  //辺を繋げる
  for(i=1;i<=n;i++){
    scanf("%d %d",&u,&k);
    for(j=1;j<=k;j++){
      scanf("%d",&v);
      G[u][v]=1;
    }
  }

  search(1);


  return 0;
  
  
}

void search(int u){
  
  int i,v;
  
  //すべての頂点を見つけていない状態にする
  for(i=1;i<=n;i++){
    state[i]=STILL;
    dis[i]=INFINITY;
  }
  
  state[u]=CONTE;
  dis[u]=0;
  enqueue(u);
 

  while(1){
   
    if(head==tail) break;
    i=dequeue();
    for(v=1;v<=n;v++){
      if(G[i][v] && state[v]==STILL){
	state[v]=CONTE;
	dis[v]=dis[i]+1;
	enqueue(v);
	
      }
    }//for
    state[i]=FINISH;
  }//while
 
 for(i=1;i<=n;i++){
     if(dis[i]==INFINITY) dis[i]=-1;
     printf("%d %d\n",i,dis[i]);
 }
 
}

void enqueue(int x){

  if(head == (tail + 1)%N){
    printf("over flow\n");
    exit(1);
  }

  Q[tail] = x;
  if(tail + 1 == N) tail = 0;
  else tail++;
  
}

int dequeue(){

  int x;

  if(head == tail){
    printf("over flow\n");
    exit(1);
  }

  x = Q[head];
  if(head + 1 == N) head = 0;
  else head++;

  return x;
  
}

