#include<stdio.h>
#include<stdlib.h>

#define INFTY 100000
#define N 101
#define WHITE 0
#define GRAY 1
#define BLACK 2

int head,tail;

int min(int,int);
void initialize(void);
int isEmpty(void);
int isFull(void);
void enqueue(int);
int dequeue(void);
void bfs(void);

int Q[N];
int M[N][N],color[N],d[N],p[N];
int n;

int main(void){
  int u,k,v;
  int i,j;

  scanf(" %d",&n);

  for(i = 1; i <= n; i++){
    for(j = 1; j <= n; j++){
      M[i][j] = 0;
    }
  }
  

  for(i = 1; i <= n; i++){
    scanf(" %d %d",&u,&k);
    for(j = 1; j <= k; j++){
      scanf(" %d",&v);
      M[u][v] = 1;
    }
  }

  bfs();

  for(i = 1; i <= n; i++){
    if(d[i] != INFTY){
      printf("%d %d\n",i,d[i]);
    }
    else{
      printf("%d %d\n",i,-1);
    }
  }
  
  return 0;
}

int min(int x, int y){
  if(x <= y) return x;
  else return y;
}

void initialize(void){
  head = tail = 0;
}

//if Queue is empty, return true
int isEmpty(void){
  return head == tail;
}

//if Queue is full, return true
int isFull(void){
  return head == (tail+1) % N;
}

void enqueue(int x){
  if(isFull()){
    fprintf(stderr,"Queue is full\n");
  }
  else{
    Q[tail] = x;
    if(tail + 1 == N) tail = 0;
    else tail++;
  }
}

int dequeue(void){
  int x;
  if(isEmpty()){
    fprintf(stderr,"Queue is empty\n");
    exit(0);
  }
  x = Q[head];
  if(head + 1 == N) head = 0;
  else head++;
  return x;
}
  
void bfs(void){
  int u,v;

  for(u = 1; u <= n; u++){
    color[u] = WHITE;
    d[u] = INFTY;
  }

  color[1] = GRAY;
  d[1] = 0;

  initialize();

  enqueue(1);

  while(!isEmpty()){
    u = dequeue();
    for(v = 1; v <= n; v++){
      if(M[u][v] == 1){
	if(color[v] == WHITE){
	  color[v] = GRAY;
	  d[v] = d[u] + 1;
	  enqueue(v);
	}
      }
    }
    color[u] = BLACK;
  }
}
  

