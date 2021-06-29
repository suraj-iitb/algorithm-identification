#include<stdio.h>
#define N 101
#define WHITE -4
#define GRAY -3
#define BLACK -2
#define INF -1

typedef struct{
  int Adj[N];
  int k;
  int color;
  int d;
  int id;
}Node;

Node node[N];
int head, tail, n, Q[N];

void enqueue(int x){
  Q[tail] = x;
  if(tail == n)
    tail = 0;
  else
    tail++;
}

int dequeue(void){
  int y;
  y = Q[head];
  if(head == n)
    head = 0;
  else
    head++;
  return y;
}

void BFS(){
  int i, u;
  for(i = 1;i < n+1;i++){
    node[i].color = WHITE;
    node[i].d = INF;
  }
  node[1].color = GRAY;
  node[1].d = 0;
  head = tail = 0;
  enqueue(node[1].id);
  while(head != tail){
    u = dequeue();
    for(i = 0;i < node[u].k;i++){
      if(node[node[u].Adj[i]].color == WHITE){
	node[node[u].Adj[i]].color = GRAY;
	node[node[u].Adj[i]].d = node[u].d + 1;
	enqueue(node[u].Adj[i]);
      }
    }
    node[u].color = BLACK;
  }
}
  

int main(){
  int i, j, l;
  scanf("%d", &n);
  for(i = 1;i < n+1;i++){
    scanf("%d%d", &node[i].id, &node[i].k);
    for(j = 0;j < node[i].k;j++)
      scanf("%d", &node[i].Adj[j]);   
  }
    BFS();
  for(i = 1;i < n+1;i++)
    printf("%d %d\n", i, node[i].d);
  return 0;
}
