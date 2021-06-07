#include<stdio.h>
#define N 1001
static const int INFTY = (1<<21);

int n, M[N][N];
int color[N], d[N], f[N], TT;
int Q[N*2], head, tail;

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

void bfss(int s){
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

int main(){
  int  u, k, v, i, j; 

  scanf("%d", &n);

  for ( i = 0; i <n; i++ ){
    for ( j = 0; j <n; j++ ) M[i][j] = 0;
  }
  
  for ( i = 0; i < n; i++ ){
    scanf("%d %d", &u, &k);
    u--;
    for ( j = 0; j < k; j++ ){
      scanf("%d", &v);
      v--;
      M[u][v] = 1;
    }
  }
  
  bfss(0);

  return 0;


}
