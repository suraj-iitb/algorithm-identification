#include<stdio.h>

#define WHITE 1
#define BLACK 2
#define GRAY  3
#define MAX   101
#define INF   2000000000

typedef struct {
  int k;
  int v[10];
} node;

node Adj[MAX];
int n, head, tail;
int color[MAX], d[MAX], q[MAX];

void enqueue(int u){
  q[tail] = u;
  tail++;
  if(tail == MAX) tail = 0;
}

int dequeue(){
  int u;
  u = q[head];
  head++;
  if(head == MAX) head = 0;
  return u;
}

void bfs(){
  int i, u, tmp;
  
  for(i = 1; i <= n; i++){
    color[i] = WHITE;
    d[i] = INF;
  }
  color[1] = GRAY;  // 1から探索
  d[1] = 0;
  head = tail = 0;

  enqueue(1);

  while(head != tail){
    u = dequeue();
    for(i = 1; i <= Adj[u].k; i++){
      if(color[Adj[u].v[i]] == WHITE){
	color[Adj[u].v[i]] = GRAY;
	
	tmp = d[u] + 1;
	if(d[Adj[u].v[i]] > tmp) d[Adj[u].v[i]] = tmp;
	enqueue(Adj[u].v[i]);
      }
    }
    color[u] = BLACK;
  }
}

int main(){
  int i, j, u;

  scanf("%d", &n);
  for(i = 1; i <= n; i++){
    scanf("%d", &u);
    scanf("%d", &Adj[u].k);
    
    for(j = 1; j <= Adj[u].k; j++){
      scanf("%d", &Adj[u].v[j]);
    }
  }
  bfs();
  
  for(i = 1; i <= n; i++){
    if(d[i] == INF) printf("%d -1\n", i);
    else            printf("%d %d\n", i, d[i]);
  }
  return 0;
}

