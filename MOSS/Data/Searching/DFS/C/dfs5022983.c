#include<stdio.h>
#include<stdlib.h>

typedef struct {
  int *a;    // list to store indexes of adjucency head
  int *adj; // adjucency list
  int n;    // number of nodes
} Graph;

void initG(Graph *g, int n)
{
  g->n = n;
  
  g->a = (int *)calloc(n, sizeof(int));
  g->adj = (int *)calloc(n*n, sizeof(int));

  for (int i = 0; i < n; i++)
    g->a[i] = -1;
}

void inputG(Graph *g)
{
  int u, v, k;
  int offset = 0;
  
  for (int i = 0; i < g->n; i++) {
    scanf("%d %d", &u, &k);
    g->a[u-1] = offset;
    for (int j = 0; j < k; j++) {
      scanf("%d", &v);
      g->adj[offset++] = v-1;
    }
    g->adj[offset++] = -1;
  }
}


void printG(Graph *g) {

  int *adj = (int *)calloc(g->n, sizeof(int));
  
  for (int i = 0; i < g->n; i++) {
    for (int j = 0; j < g->n; j++)
      adj[j] = 0;
    
    int offset = g->a[i];
    while(g->adj[offset] != -1) {
      int j = g->adj[offset++];
      adj[j] = 1;
    }
    
    for (int j = 0; j < g->n-1; j++) 
      printf("%d ", adj[j]);
    printf("%d\n", adj[g->n-1]);
  }
}

int time;
int *d, *f;

void init_dfs(int n)
{
  d = (int *)calloc(n, sizeof(int));
  f = (int *)calloc(n, sizeof(int));
                    
  for (int i = 0; i < n ; i++) {
    d[i] = f[i] = 0;
  }

  time = 0;
}

void dfs(int u, Graph *g)
{
  int v;
  int offset = g->a[u];

  if (d[u] > 0)
    return;
  d[u] = ++time;

  while(g->adj[offset] != -1) {
    v = g->adj[offset++];
    dfs(v, g);
  }
  f[u] = ++time;
}


int main(void)
{
  int n;
  Graph g;
  
  scanf("%d", &n);
  
  initG(&g, n);
  inputG(&g);
  init_dfs(n);
  
  for (int i = 0; i < n; i++) {
    if (d[i] == 0)
      dfs(i, &g);
  }

  for (int i = 0; i < n; i++) {
    printf("%d %d %d\n", i+1, d[i], f[i]);
  }
  return 0;
}

