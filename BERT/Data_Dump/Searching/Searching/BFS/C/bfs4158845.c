#include <stdio.h>
#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

int isEmpty(void);
void enqueue(int);
int dequeue(void);

int n, G[N+1][N+1], d[N+1], Q[N], head, tail;

void bfs(void);

int main(){
 
  int u, k, v, i, j;

  scanf("%d",&n);
  
  for(i=1;i<n+1;i++){
    for(j=1;j<n+1;j++){
      G[i][j]=0;
    }
  }

  for(i=0;i<n;i++){
    scanf("%d %d",&u,&k);
    for(j=0;j<k;j++){
      scanf("%d",&v);
      G[u][v]=1;
    }
  }
 
  bfs();
  for(i=1;i<n+1;i++){
    printf("%d %d\n",i, d[i]);
  }
}

void bfs(){
  int i, color[N+1], now, next;

  for(i=1;i<n+1;i++){
    color[i]=WHITE;
    d[i]=-1;
  }
  head=tail=0;

  d[1]=0;
  color[1]=GRAY;
  enqueue(1);
  
  while(isEmpty()!=1){
    now=dequeue();
    /*printf("%d ",now);*/
    for(next=1;next<=n;next++){
      if(G[now][next]==1 && color[next]==WHITE){
        color[next]=GRAY;
        d[next]=d[now]+1;
        enqueue(next);
      }
    color[now]=BLACK;
    }
  }
}


void enqueue(int x){
    Q[tail]=x;
    if(tail+1==N) tail=0;
    else tail++;
}

int dequeue(){
  int x;

  x=Q[head];
  if(head+1==N) head=0;
  else head++;
  return x;
}

int isEmpty(){
  if(head==tail) return 1;
  else return 0;
}

