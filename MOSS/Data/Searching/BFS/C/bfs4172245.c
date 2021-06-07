#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 1001
static const int INFTY = (1<<21);

void bfs(int s);
void enqueue(int x);
int dequeue();

int n, head, tail;
int M[N][N], d[N], Q[N*2];

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
  
  bfs(0);

  return 0;
}

void enqueue(int x) {
	tail += 1;
  Q[tail] = x;
}

int dequeue() {
  int x;
  head += 1; 
  x = Q[head];
  return x;
}

void bfs(int s) {
  int i, u, v;
  head = tail = 1;
  enqueue(s);
  for ( i = 0; i < n; i++ )d[i] = INFTY;
  d[s] = 0;
  while(head != tail){
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

