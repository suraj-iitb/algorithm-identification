#include <stdio.h>
#define N 101
#define null (-1)
#define INF (1 << 21)
#define WHITE 0
#define BLACK 1;
#define GRAY 2

void BFS(int);
void Enqueue(int);
int Dequeue();
int G[N][N];
int vertex[N];
int color[N];
int d[N];
int queue[N];
int n;
int head, tail;
int e[N];

int main(void){

  int i, j;
  scanf("%d",&n);
  
  for(i = 1;i <= n;i++){
    scanf("%d", &vertex[i]);
    scanf("%d", &e[vertex[i]]);
    
    for(j = 1;j <= e[vertex[i]];j++)
      scanf("%d", &G[i][j]);
  }

  BFS(vertex[1]);  
  
    for(i = 1;i <= n;i++)
  printf("%d %d\n",vertex[i], d[vertex[i]]);
  
  return 0;
  
}

void BFS(int s){
  
  int i, u, v;
  int next;
  int empty;
 
  for(u = 1; u <= n;u++){
    color[u] = WHITE;
    d[u] = INF;
  }

  color[s] = GRAY;
  d[s] = 0;
  empty = 0;

  //最初はsをキューに入れる。
  Enqueue(s);
  empty++;

  //空じゃなかったら
  while(empty != 0 ){    
    u = Dequeue();
    empty--;

    //取り出したキューがエッジを持つなら、訪問する。
    for(v = 1;v <= e[u];v++){
      next = G[u][v];
      if(next && (color[next] == WHITE)){
	color[next] = GRAY;
	d[next] = d[u] + 1;
	Enqueue(next);
	empty++;
      }
    }
    
    //訪問した場所は黒くする。
    color[u] = BLACK;
  }

  for(i = 1;i <= n;i++){
    if(color[i] == WHITE)
      d[i] = null;
  }
}

void Enqueue(int v){

  if(tail == N)
    tail = 0;
  queue[tail++] = v;
}

int Dequeue(){

  if(head == N)
    head = 0;
  return queue[head++];
}
