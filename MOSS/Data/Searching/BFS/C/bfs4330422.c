#include <stdio.h>

#define MAX 100
#define NIL -1
#define WHITE 0
#define GRAY 1
#define BLACK 2

void enqueue(int);
int dequeue(void);
void bfs(void);

int head,tail,Queue[MAX];
int color[MAX],M[MAX][MAX],d[MAX],n;

int main(){
  int u,k,v;
  int i,j;

  scanf("%d",&n);

  for (i = 0;i < n;i++){
    scanf("%d %d",&u,&k);

    u--;
    for (j = 0;j < k;j++){
      scanf("%d",&v);

      v--;
      M[u][v] = 1;
    }
  }

  bfs();

  for (i = 0;i < n;i++)
    printf("%d %d\n",i + 1,d[i]);
  
  return 0;
}

void enqueue(int u){
  Queue[tail] = u;

  if (tail + 1 == MAX)
    tail = 0;

  else
    tail++;
}

int dequeue(void){
  int x;

  x = Queue[head];

  if (head + 1 == MAX)
    head = 0;

  else
    head++;

  return x;
}

void bfs(void){
  int u,v;
  int i;

  for (i = 0;i < n;i++){
    color[i] = 0;
    d[i] = NIL;
  }

  color[0] = GRAY;
  d[0] = 0;
  enqueue(0);

  while (head != tail){
    u = dequeue();

    for (v = 0;v < n;v++){
      if (M[u][v] && color[v] == WHITE){
	color[v] = GRAY;
	d[v] = d[u] + 1;
	enqueue(v);
      }
    }

    color[u] = BLACK;
  }
}

