#include <stdio.h>
#define N 100
#define white 0
#define gray 1
#define black 2
int h, qpt1 = 0, qpt2 = 0;
int A[N][N], color[N], d[N], Q[N];

void enq(int u) {
  Q[++qpt1] = u;
}

int deq(void) {
  int u = Q[++qpt2];
  return u;
}

void bfs(void) {
  int s = 0;
  int u;
  for ( int i = 0; i < h; ++i ) {
    color[i] = white;
    d[i] = -1;
  }
  color[s] = gray;
  d[s] = 0;
  enq(s);

  while ( qpt1 != qpt2 ) {
    u = deq();
    for ( int v = 0; v < h; ++v) {
      if ( A[u][v] && color[v] == white) {
        color[v] = gray;
        d[v] = d[u] + 1;
        enq(v);
      }
    }
    color[u] = black;
  }
}

void print(void) {
  for ( int i = 0; i < h; ++i ) {
    printf("%d %d", i + 1, d[i]);
    putchar('\n');
  }
}

int main(void) {
  int a, b, v;
  scanf("%d", &h);
  for ( int i = 0; i < h; ++i ) {
    scanf("%d%d", &a, &b);
    a--;
    for ( int j = 0; j < b; ++j ) {
      scanf("%d", &v);
      v--; 
      A[a][v] = 1;
    }
  }
  bfs();
  print();
}

