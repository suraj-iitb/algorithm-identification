#include<stdio.h>
#define N 1001
static int INFTY = (1<<21);

int n, G[N][N];
int color[N], b[N], f[N], tt;
int P[N*2], head, tail;

void init(){
  head = tail = 1;
}

void enqueue(int x){
  P[tail++] = x;
}

int empty(){
  return head == tail;
}

int dequeue(){
  int x = P[head++];
  return x;
}

void bfs(int s){
  int i, u, v;
  init();
  enqueue(s);
  for ( i = 0; i < n; i++ )b[i] = INFTY;
  b[s] = 0;
  while(!empty()){
    u = dequeue();
    for ( v = 0; v < n; v++ ){
      if ( G[u][v] == 0 ) continue;
      if ( b[v] != INFTY ) continue;
      b[v] = b[u] + 1;
      enqueue(v);
    }
  }
  for ( i = 0; i < n; i++ ){
    printf("%d %d\n", i+1,((b[i]==INFTY)?(-1):b[i]));
  }
}

int main(){
  int  u, k, v, i, j; 
  scanf("%d", &n);
  for ( i = 0; i <n; i++ ){
    for ( j = 0; j <n; j++ ) G[i][j] = 0;
  }
  
  for ( i = 0; i < n; i++ ){
    scanf("%d %d", &u, &k);
    u--;
    for ( j = 0; j < k; j++ ){
      scanf("%d", &v);
      v--;
      G[u][v] = 1;
    }
  }
  
  bfs(0);

  return 0;
}
