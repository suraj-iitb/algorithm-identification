#include <stdio.h>
#define N 100
#define INF 1000000000
#define TRUE 1
#define FALSE 0

int Queue[N];

int head = 0,tail = 0;

int n,G[N][N];

int d[N];

int isEmpty(void){
  if(head == tail) return TRUE;
  return FALSE;
}

void enqueue(int key){
  Queue[tail] = key;
  tail = (tail + 1)%N;
}

int dequeue(void){
  int tmp;
  tmp  = Queue[head];
  head = (head + 1)%N; 
  return tmp;
}

void intialize(void){
  for(int i = 0; i < n; i++){
    d[i] = INF;
    for(int j = 0; j < n; j++){
      G[i][j] = 0;
    }
  }
}

void BFS(int s){
  enqueue(s);
  d[s] = 0;
  int u;
  while(isEmpty() != TRUE){
    u = dequeue();
    for(int v = 0; v < n; v++){
      if(G[u][v] == 0) continue;
      if(d[v] != INF) continue;
      d[v] = d[u] + 1;
      enqueue(v);
    }
  }
  for(int i = 0; i < n; i++){
    printf("%d ",i+1);
    if(d[i] == INF) printf("%d\n",-1);
    else printf("%d\n",d[i]);
  }
}
  
  

int main()
{
  int u,k,v;
  scanf("%d",&n);
  intialize();
  for(int i = 0; i < n; i++){
    scanf("%d%d",&u,&k);
    u--;
    for(int j = 0; j < k; j++){
      scanf("%d",&v);
      v--;
      G[u][v] = 1;
    }
  }
  
  BFS(0);

  return 0;
}
      

