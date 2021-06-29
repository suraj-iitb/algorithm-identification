#include <stdio.h>
#include <limits.h>

#define M 101
#define WHITE 0
#define GRAY 1
#define BLACK 2


void bfs(int);
void enqueue(int);
int dequeue(void);
int isEmpty(void); 

int g[M][M];
int Q[M];
int d[M];
int color[M];

int n, head = 0, tail = 0;


int main(){
  int u, k, v;
  int i, j;

  for(i = 0; i < M; i++) Q[i] = 0;

  scanf("%d", &n);

  for(i = 0; i <= n; i++){
    for(j = 0; j <= n; j++){
      g[i][j] = 0;
    }
  }

  for(i = 1; i <= n; i++){
    scanf("%d", &u);
    scanf("%d", &k);

    for(j = 1; j <= k; j++){
      scanf("%d", &v);

      g[u][v] = 1;
    }
  }

  bfs(1);

  for(i = 1; i <= n; i++) printf("%d %d\n", i, d[i]);

  
  return 0;
}


void bfs(int s){
  int i;
  int u, v;

  for(i = 1; i <= n; i++){
    color[i] = WHITE;
    d[i] = -1;
  }

  color[i] = GRAY;
  d[s] = 0;

  enqueue(s);

  while(isEmpty() != 1){
    u = dequeue();

    for(v = 1; v <= n; v++){
      if(color[v] == WHITE && g[u][v] == 1){
	color[v] = GRAY;
	d[v] = d[u] + 1;
	enqueue(v);
      }
    }

    color[u] = BLACK;
  }
}


void enqueue(int x){
  Q[tail] = x;

  if(tail + 1 == M) tail = 0;

  else tail++;
}


int dequeue(){
  int x;

  x = Q[head];

  if(head + 1 == M) head = 0;

  else head++;

  return x;
}


int isEmpty(){
  int sta = 0;

  if(head == tail) sta = 1;

  return sta;
}

