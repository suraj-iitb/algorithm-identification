#include<stdio.h>
#define N 101
#define WHITE 0
#define BLACK 1
#define GRAY 2
typedef struct{
  int k;
  int d;
  int color;
  int v[N];
} Graph;
Graph g[N];
int n,head=0,tail=0,q[N];
 
void enqueue(int x)
{
  q[tail] = x;
  if(tail+1 == N-1) tail = 0;
  else tail++;
}
 
int dequeue()
{
  int x;
  x = q[head];
  if(head+1 == N-1) head=0;
  else head++;
  return x;
}
 
void bfs()
{
  int i,u,v;
  for(i=2; i<=n; i++) {
    g[i].color = WHITE;
    g[i].d = N+1;
  }
  g[1].color = GRAY;
  g[1].d = 0;
  enqueue(1);
  while(head!=tail) {
    u = dequeue();
    for(i=0; i<g[u].k; i++){
      v=g[u].v[i];
      if(g[v].color == WHITE){
        g[v].color = GRAY;
        g[v].d = g[u].d +1;
        enqueue(v);
      }
    }
    g[u].color = BLACK;
  }
}
 
int main()
{
  int u,i,j,k;
  scanf("%d",&n);
  for(i=0; i<n; i++) {
    scanf("%d%d",&u,&k);
    g[u].k = k;
    for(j=0; j<g[u].k; j++) {
      scanf("%d",&g[u].v[j]);
    }
  }
  bfs();
  for(i=1; i<=n; i++) {
    if(g[i].d == N+1) g[i].d = -1;
  }
  for(i=1; i<=n; i++){
    printf("%d %d\n",i,g[i].d);
  }
  return 0;
}
