#include <stdio.h>
#define WHITE  0
#define GRAY   1
#define BLACK  2
#define NIL   -1
#define N    150

typedef struct{
  int id;
  int k;
  int v[N];
}DATA;

void bfs(int,int,int);
void enqueue(int);
int dequeue(void);
  
int count=0;
int d[N],color[N],G[N][N],Q[N];
DATA data[N];

int main() {

  int i,j,n;
  
  scanf("%d",&n);
  for(i = 1; i <= n; i++) {
    scanf("%d%d",&data[i].id,&data[i].k);
    if(data[i].k == 0 ) data[i].v[1] = 0;
    
    for(j = 1; j <= data[i].k; j++) {
      scanf("%d",&data[i].v[j]);
      if(data[i].v[j] == data[i].v[data[i].k]) data[i].v[(data[i].k)+1] = NIL;
    }
  }
  
  for(i = 1; i <= n; i++) {
    for(j = 1; j <= n; j++) {
      G[i][data[i].v[j]] = 1;   
    }
  }

  bfs(1,data[1].id,n);

  for(i = 1; i <= n; i++) {
    printf("%d %d\n",data[i].id,d[i]);
  }

  return 0;
}

void bfs(int s,int u,int V)
{
  int i,x;
  for(i = u; i <= V; i++) {
    color[i] = WHITE;
    d[i] = NIL;
  }
  color[s] = GRAY;
  d[s] = 0;
  enqueue(s);
  
  while(count != 0) {
    x = dequeue();
    for(i = u; i <= V; i++) {
      if(G[x][i] == 1 && color[i] == WHITE) {
	color[i] = GRAY;
	d[i] = d[x]+1;
	enqueue(i);

      }
    }
    color[x] = BLACK;
  }
}

void enqueue(int a)
{
  Q[count] = a;
  count++;
}

int dequeue(void)
{
  int head,i;
  head = Q[0];
  for(i = 0; i < count; i++) {
    Q[i] = Q[i+1];
  }
  count--;
  return head;
}

