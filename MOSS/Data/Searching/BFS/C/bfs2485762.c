#include <stdio.h>
 
#define MAX 100
#define WHITE 0
#define BLACK 1
#define GRAY 2
#define INF 1000000
 
void bfs();
int empty();
void enqueue(int);
int dequeue();
 
int num, time, head, tail, inum;
int graph[MAX][MAX];
int dis[MAX];
int color[MAX];
int Q[MAX];
 
int main(){
 
  int i, j, jnum, line;
 
  scanf("%d", &num);
 
  for(i = 0; i < num; i++){
 
    for(j = 0; j < num; j++){
 
      graph[i][j] = 0;
 
    }
 
    scanf("%d %d", &inum, &jnum);
 
    for(j = 0; j < jnum; j++){
 
      scanf("%d", &line);
 
      graph[inum - 1][line - 1] = 1;
 
    }
 
  }
 
  bfs(0);
   
  for(i = 0; i < num; i++){
 
    if(dis[i] == INF)
      printf("%d %d\n", (i + 1), -1);
 
    else
      printf("%d %d\n", (i + 1), dis[i]);
 
  }
 
  return 0;
 
}
 
void bfs(int s){
 
  int u, v;
 
  for(u = 0; u < num; u++){
 
    color[u] = WHITE;
 
    dis[u] = INF;
 
  }
 
  dis[s] = 0;
 
  enqueue(s);
 
  while(empty() == 0){
 
    u = dequeue();
 
    for(v = 0; v < num; v++){
 
      if(graph[u][v] == 0)
    continue;
 
      if(dis[v] != INF)
    continue;
 
      dis[v] = dis[u] + 1;
 
      enqueue(v);
 
    }
 
  }
 
}
 
 
int empty(){
 
  if(head == tail)
    return 1;
 
  else
    return 0;
 
}
 
void enqueue(int data){
 
  Q[tail] = data;
 
  if(tail == MAX) 
    tail = 0;
  else
    tail++;
 
}
 
int dequeue(){
 
  int data;
 
  data = Q[head];
 
  if(head == MAX) 
    head = 0;
 
  else
    head++;
 
  return data;
 
}
