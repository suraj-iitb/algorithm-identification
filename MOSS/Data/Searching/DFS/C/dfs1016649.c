#include<stdio.h>
#define N 101
#define WHITE -3
#define GRAY -2
#define BLACK -1

typedef struct{
  int Adj[N];
  int color;
  int k;
  int d;
  int f;
}Node;

Node node[N];
int n, time;

void visit(int u){
  int i;
  node[u].color = GRAY;
  node[u].d = ++time;
  for(i = 0;i < node[u].k;i++){
    if(node[node[u].Adj[i]].color == WHITE)
      visit(node[u].Adj[i]);
  }
  node[u].color = BLACK;
  node[u].f = ++time;
}

void DFS(void){
  int i;
  for(i = 1;i < n+1;i++){
    node[i].color = WHITE;
    time = 0;
  }
  for(i = 1;i < n+1;i++)
    if(node[i].color == WHITE)
      visit(i);
}

int main(){
  int i, j, l, id;
  scanf("%d", &n);
  for(i = 1;i < n+1;i++){
    scanf("%d%d", &id, &node[i].k);
    for(j = 0;j < node[i].k;j++)
      scanf("%d", &node[i].Adj[j]);
  }
  DFS();
  for(i = 1;i < n+1;i++)
    printf("%d %d %d\n", i, node[i].d, node[i].f);
  
  return 0;
}
