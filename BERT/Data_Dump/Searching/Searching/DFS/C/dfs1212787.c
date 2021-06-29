#include <stdio.h>
#include <stdlib.h>

struct vertex {
  int d;
  int f;
  int k;
  int visited;
  int *vlist;
};

struct vertex *adj;
int t;

void dfs(int id);

int main(int argc, char *argv[])
{
  int n, i, j, id;

  t = 0;

  scanf("%d", &n);
  adj = (struct vertex *)malloc(sizeof(struct vertex) * (n + 1));

  for (i = 0; i < n; i++) {
    scanf("%d", &id);
    scanf("%d", &(adj[id].k));
    adj[id].vlist = (int *)malloc(sizeof(int) * adj[id].k);
    adj[id].visited = 0;
    adj[id].d = 0;
    adj[id].f = 0;
    for (j = 0; j < adj[id].k; j++) scanf("%d", &(adj[id].vlist[j]));
  }


  for (i = 1; i <= n; i++) {
    if (adj[i].d == 0) dfs(i);
  }

  for (i = 1; i <= n; i++) printf("%d %d %d\n", i, adj[i].d, adj[i].f);

  return 0;
}

void dfs(int id)
{
  int current = id;

  t++;
  if (adj[id].d == 0) adj[id].d = t;

  while (adj[id].visited != adj[id].k) {
    current = adj[id].vlist[adj[id].visited++];
    if (adj[current].d == 0) dfs(current);
  }

  t++;
  if (adj[id].f == 0) adj[id].f = t;
}
