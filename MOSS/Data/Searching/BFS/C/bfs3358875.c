#include<stdio.h>

#define MAX 100
#define INF 100000000
#define WHITE 0
#define GRAY 1
#define BLACK 2

typedef struct{
  int data[MAX];
  int head;
  int tail;
}queue;

queue Q;

int n,d[MAX],g[MAX][MAX],color[MAX];

void bfs(int);
void enqueue(int);
int dequeue();
int isEmpty();

int main(){
  int i,j,k,m,v;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d %d",&k,&m);
    for(j=0;j<m;j++){
      scanf("%d",&v);
      g[k-1][v-1] = 1;
    }
  }
  for(i=0;i<n;i++) d[i] = INF;

  bfs(0);

  for(i=0;i<n;i++){
    if(d[i] == INF)printf("%d %d\n",i+1,-1);
    else printf("%d %d\n",i+1,d[i]);
  }
  return 0;
}

void bfs(int s){
  int v,u;

  d[s] = 0;
  color[s] = GRAY;
  Q.head = Q.tail = 0;
  enqueue(s);

  while(isEmpty()){
    u = dequeue();
    if(u == INF) break;
    for(v=0;v<n;v++){
      if(g[u][v] == 0) continue;
      if(color[v] == WHITE){
	d[v] = d[u] + 1;
	color[v] = GRAY;
	enqueue(v);
      }
    }
    color[u] = BLACK;
  }
}

void enqueue(int s){

  if(Q.tail >= n) return;
  
  Q.data[Q.tail] = s;
  Q.tail++;
}

int dequeue(){
  int s;

  if(Q.head == Q.tail)return INF;

  s = Q.data[Q.head];
  Q.head++;

  return s;
}
int isEmpty(){
  if(Q.head == Q.tail) return 0;
  else return 1;
}

