#include<stdio.h>
#define N 100
#define INFTY (1<<21)
#define LEN 1000


int Q[LEN];
int head, tail;
int n, G[N][N], d[N];

void enqueue(int x){
  Q[tail] = x;
  tail = ( tail + 1 ) % LEN;
}

void dequeue(){
  int x = Q[head];
  head = ( head + 1 ) % LEN;
}

void bfs(int s){
  int i, u, v;

  enqueue(s);

  for( i = 0 ; i < n ; i++ ) d[i] = INFTY;
  d[s] = 0;

  while( head != tail ){
    u = Q[head];
    dequeue();
    for( v = 0 ; v < n ; v++ ){
      if( G[u][v] == 0 ) continue;
      if( d[v] != INFTY ) continue;
      d[v] = d[u] + 1;
      enqueue(v);
    }
  }

  for( i = 0 ; i < n ; i++ ){
    printf("%d %d\n",i+1,((d[i]==INFTY) ? (-1) : d[i]));
  }
}

int main(){
  int i, j, u, k ,v;

  scanf("%d",&n);

  for( i = 0 ; i < n ; i++ ){
    for( j = 0 ; j < n ; j++ ){
      G[i][j] = 0;
    }
  }

  for( i = 0 ; i < n ; i++ ){
    scanf("%d%d",&u,&k);
    u--;
    for( j = 0 ; j < k ; j++ ){
      scanf("%d",&v);
      v--;
      G[u][v] = 1;
    }
  }
  
  bfs(0);
  return 0;

}

