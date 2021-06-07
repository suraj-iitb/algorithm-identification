// c.c

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NMIN 1 // n min/max
#define NMAX 100
#define START 1 // where finding distance from
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define INF (int)pow(2,31)-1

typedef struct{
  int k; // degree
  int *v; // IDs of vertices adjacent to u
  int color; // white/gray/black
  int d; // the distance from vertex 1
} Vertex;

typedef struct{
  int data[NMAX];
  int head;
  int tail;
} Queue;

void BFS(Vertex *, int);
void enqueue(Queue *, int);
int dequeue(Queue *);
void output(Vertex *, int);

int time;

int main() {
  Vertex *V; // adjacency list
  int n; // number of vertices
  int u; // IDs of vertices
  int i, j; // counter

  // input n
  scanf("%d", &n);
  if(n<NMIN || NMAX<n) {
    fprintf(stderr,"%d <= n <= %d\n", NMIN, NMAX);
    exit(8);
  }
  
  // input vertices data
  V = (Vertex *)malloc(sizeof(Vertex)*(n+1));
  for(i=1; i<=n; i++) {
    scanf("%d", &u);
    scanf("%d", &V[u].k);
    V[u].v = (int *)malloc(sizeof(int)*V[u].k);
    for(j=0; j<V[u].k; j++) {
      scanf("%d", &V[u].v[j]);
    }
  }

  BFS(V,n);
  output(V,n);
  
  for(i=1; i<=n; i++)
    free(V[i].v);
  free(V);

  return 0;
}

void BFS(Vertex *V, int n) {
  Queue Q;
  int u;
  int i; // counter

  Q.head = 0;
  Q.tail = 0;
  
  for(i=1; i<=n; i++) {
    V[i].color = WHITE;
    V[i].d = -1;
  }
  V[START].color = GRAY;
  V[START].d = 0;
  
  enqueue(&Q,START);
  while(Q.head != Q.tail) {
    u = dequeue(&Q);
    for(i=0; i<V[u].k; i++)
      if(V[V[u].v[i]].color==WHITE) {
	V[V[u].v[i]].color = GRAY;
	V[V[u].v[i]].d = V[u].d+1;
	enqueue(&Q,V[u].v[i]);
      }
    V[u].color = BLACK;
  }
}

void enqueue(Queue *Q, int s) {
  Q->data[Q->tail] = s;
  Q->tail++;
}

int dequeue(Queue *Q) {
  Q->head++;
  return Q->data[Q->head-1];
}

void output(Vertex *V, int n) {
  int id; // counter

  for(id=1; id<=n; id++) {
    printf("%d ", id);
    printf("%d\n", V[id].d);
  }
}

