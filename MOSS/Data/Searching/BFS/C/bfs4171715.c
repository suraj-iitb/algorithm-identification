#include<stdio.h>
#define N 1001
static const int INFTY = (1<<21);

int n, M[N][N];
int color[N], d[N], f[N], tt;
int Q[N*2], head, tail;

void init();
void enqueue(int x);
int empty();
int dequeue();
void bfs(int s);

int main(){
  int  l, m, k, i, j; 

  scanf("%d", &n);

  for ( i = 0; i <n; i++ ){
    for ( j = 0; j <n; j++ ) M[i][j] = 0;
  }
  
  for ( i = 0; i < n; i++ ){
    scanf("%d %d", &l, &m);
    l--;
    for ( j = 0; j < m; j++ ){
      scanf("%d", &k);
      k--;
      M[l][k] = 1;
    }
  }
  
  bfs(0);

  return 0;
}

void init(){
  head = tail = 1;
}

void enqueue(int x){
  Q[tail++] = x;
}

int empty(){
  return head == tail;
}

int dequeue(){
  int x = Q[head++];
  return x;
}

void bfs(int s){
  int i, u, v;
  init();
  enqueue(s);
  for ( i = 0; i < n; i++ )d[i] = INFTY;
  d[s] = 0;
  while(!empty()){
    u = dequeue();
    for ( v = 0; v < n; v++ ){
      if ( M[u][v] == 0 ) continue;
      if ( d[v] != INFTY ) continue;
      d[v] = d[u] + 1;
      enqueue(v);
    }
  }
  for ( i = 0; i < n; i++ ){
    printf("%d %d\n", i+1,((d[i]==INFTY)?(-1):d[i]));
  }
}

