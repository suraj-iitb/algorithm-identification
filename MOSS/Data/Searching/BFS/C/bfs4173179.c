#include<stdio.h>

#define INFTY -1
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define N 105

typedef struct{
  int data[N];
  int head;
  int tail;
}queue;

queue Q;

int n;
int M[N][N];
int d[N] = {INFTY};
int color[N] = {WHITE};

void BFS(int);
void enqueue(int);
int dequeue();

int main(){
  int i, j;
  int u, k, v;

  scanf("%d",&n);

  for(i = 0 ; i < n ; i++){
    scanf("%d %d",&u,&k);
    for(j = 0 ; j < k ; j++){
      scanf("%d",&v);
      M[u-1][v-1] = 1;
    }
  }

  for(i = 0 ; i < n ; i++) d[i] = INFTY;

  BFS(0);

  for(i = 0 ; i < n ; i++){
    if(d[i] == INFTY) printf("%d %d\n",i+1,-1);
      else printf("%d %d\n",i+1,d[i]);
  }

  return 0;
}

void BFS(int s){
  int v, u;

  d[s] = 0;
  color[s] = GRAY;
  Q.head = Q.tail = 0;

  enqueue(s);

  while(Q.tail < n){
    u = dequeue();
    if(u == INFTY) break;
    for(v = 0 ; v < n ; v++){
      if(M[u][v] == 0) continue;
      if(color[v] == WHITE){
	d[v] = d[u] + 1;
	color[v] = GRAY;
	enqueue(v);
      }
    }
		color[u] = BLACK;
  }
}

void enqueue(int x){

  if(Q.tail >= n) return;

  Q.data[Q.tail] = x;
  Q.tail++;
}

int dequeue(){
  int s;

  if(Q.head == Q.tail) return INFTY;

  s = Q.data[Q.head];
  Q.head++;

  return s;
}

