#include <stdio.h>
#define N 105
#define BLACK -2
#define WHITE 1
#define GRAY 7
#define INF -1

typedef struct {
  int color, discover, id;  
}Record;
 
void bfs(int);
void enqueue(int);
int dequeue();


int adj[N][N], que[N];
int size, n, head, tail;
Record data[N];

int main () {
  int m, i, j, k, l;

  scanf("%d",&n);

  for(i = 1 ; i <= n ; i++) {
    scanf("%d %d",&l,&m);
    data[l].id = l;
    for(j = 1 ; j <= m ; j++) {
      scanf("%d",&k);
      
      adj[l][k] = 1;
    }
  }
  
  

  bfs(1);


  for(i = 1 ; i <= n ; i++) {
    printf("%d %d\n",data[i].id,data[i].discover);
  }

  return 0;
}


void bfs(int s) {
  int i, u;

  for(i = 1 ; i <= n ; i++) {
    data[i].color = WHITE;
    data[i].discover = INF;
  }

  data[s].color = GRAY;
  data[s].discover = 0;

  enqueue(s);

  while(size > 0) {
    u = dequeue();

    for(i = 1 ; i <= n ; i++) {
      if(adj[u][i] == 1 && data[i].color == WHITE) {
	data[i].color = GRAY;
	data[i].discover = data[u].discover + 1;
	enqueue(i);
      }
    }
    data[u].color = BLACK;
    
  }
}



void enqueue(int x) {
  que[tail] = x;
  size++;
  if(tail == N) tail = 0;
  else tail++;
}

int dequeue () {
  int x = 0;
  x = head;
  if(head == N) head = 0;
  else head++;
  size--;
  return que[x];
}

