#include <stdio.h>
#include <stdlib.h>

int n,head, tail;
char color[103];
int d[103];
int Q[104];
int G[103][103];

void initialize(void);
int isEmpty(void);
int isFull(void);
void enqueue(int);
int dequeue(void);
void bfs(int);

int main()
{
  int i,u,k,j;
  int *U;

  /* 初期化 */
  for(i = 0;i < 103;i++){
    for(j = 0;j < 103;j++){
      G[i][j] = 0;
    }
  }

  scanf("%d",&n);

  for(i = 0;i < n;i++){
    scanf("%d",&u);
    scanf("%d",&k);

    U = (int *)malloc(sizeof(int) * k);
    if(U == NULL) exit(0);

    for(j = 0;j < k;j++){
      scanf("%d",&U[j]);
      G[u][U[j]] = 1;
    }
  }

  bfs(1);

  /* 出力 */
  for(i = 1;i <= n;i++){
    printf("%d %d\n",i,d[i]);
  }

  return 0;
}

void bfs(int s)
{
  int u,v;

  for(u = s + 1;u <= n;u++){
    color[u] = 'W';    // WHITE 何もしていない
    d[u] = -1;
  }
  color[s] = 'G';  // GRAY 一度訪れて、現在キューに入っている */

  d[s] = 0;

  initialize(); // Q = empty
  enqueue(s);

  while(isEmpty() != 1){
    u = dequeue();
    
    for(v = 1;v <= n;v++){
      if(G[u][v] == 1){
	if(color[v] == 'W'){
	  color[v] = 'G';
	  d[v] = d[u] + 1;
	  enqueue(v);
	}
	else color[u] = 'B';
      }
    }
  }
}

void enqueue(int x){
  if(isFull() == 1){
    fprintf(stderr,"オーバーフロー\n");
    exit(1);
  }

  Q[tail] = x;

  if((tail + 1) == 104) tail = 0;
  else tail++;
}

int dequeue(void){
  int x;
  if(isEmpty() == 1){
    fprintf(stderr,"アンダーフロー\n");
    exit(1);
  }
   
  x = Q[head];

  if((head + 1) == 104) head = 0;

  else head++;

  return x;
}

void initialize(void)
{
  head  = 0;
  tail  = 0;
}

int isEmpty(void)
{
  if(head == tail) return 1;
  return 0;
}

int isFull(void)
{
  if(head == (tail + 1) % 104) return 1;
  return 0;
}
