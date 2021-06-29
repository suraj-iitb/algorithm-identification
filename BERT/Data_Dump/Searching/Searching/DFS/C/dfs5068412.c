#include <stdio.h>
#define N 100

typedef struct {
  int state;
  int d;
  int f;
  int neighbor[N];
} vertex_t;

int n, time;
vertex_t vertex[N+1];

void dfs_visit(int i)
{
  int j;
  vertex[i].state = 1;
  vertex[i].d = ++time;
  for(j = 0; vertex[i].neighbor[j] > 0; j++) {
    if(vertex[vertex[i].neighbor[j]].state == 0) dfs_visit(vertex[i].neighbor[j]);
  }
  vertex[i].state = 2;
  vertex[i].f = ++time;
}

void dfs()
{
  int i;
  time = 0;

  for(i = 1; i <= n; i++) {
    if(vertex[i].state == 0) dfs_visit(i);
  }

  for(i = 1; i <= n; i++) printf("%d %d %d\n", i, vertex[i].d, vertex[i].f);
}

int main()
{
  int i, j, k, u;
  scanf("%d", &n);
  for(i = 0; i < n; i++) {
    scanf("%d %d", &u, &k);
    for(j = 0; j < k; j++) scanf("%d", &vertex[u].neighbor[j]);
    vertex[u].neighbor[k] = 0;
  }

  for(i = 0; i < n; i++) vertex[i].state = 0;
  dfs();

  return 0;
}
