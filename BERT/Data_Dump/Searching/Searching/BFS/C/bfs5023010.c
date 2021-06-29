#include<stdio.h>
#include<stdlib.h>

#define MAX 101

typedef struct {
  int data[MAX];
  int head, tail;
} Queue;

void initQ(Queue *q)
{
  q->head = q->tail = 0;
}

int isEmpty(Queue *q)
{
  return q->head == q->tail;
}

int isFull(Queue *q)
{
  return q->head == (q->tail + 1) % MAX;
}

void enqueue(Queue *q, int data)
{
  if (isFull(q))
    exit(1);
  
  q->data[q->tail] = data;
  q->tail = (q->tail + 1) % MAX;
}

int dequeue(Queue *q)
{
  if (isEmpty(q))
    exit(1);

  int data = q->data[q->head];
  q->head = (q->head + 1) % MAX;
 
  return data;
}

void printQ(Queue *q) {
  
  int i = q->head;
  printf("\thead %d tail %d ", q->head, q->tail);
  while( i != q->tail) {
    printf("(i %d d[i] %d) ", i, q->data[i]+1);
    i = (i + 1) % MAX;
  }
  printf("\n");
}


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

  free(adj);
}

int *d;


void bfs(int st, Graph *g)
{
  int u, v, offset;
  Queue q;

  d = (int *)calloc(g->n, sizeof(int));
  for (int i = 0; i < g->n ; i++) {
    d[i] = -1;
  }

  initQ(&q);
  enqueue(&q, st);
  d[st] = 0;

  while( !isEmpty(&q) ) {
    u = dequeue(&q);

    offset = g->a[u];
    while(g->adj[offset] != -1) {
      v = g->adj[offset++];
      if (d[v] == -1) {
        d[v] = d[u] + 1;
        enqueue(&q, v);
      }
    }
  }
}

int main(void)
{
  int n;
  Graph g;

  scanf("%d", &n);

  initG(&g, n);
  inputG(&g);

  bfs(0, &g);

  for (int i = 0; i < n; i++) {
    printf("%d %d\n", i+1, d[i]);
  }
  return 0;
}

