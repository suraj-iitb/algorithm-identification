// b.c

#include <stdio.h>
#include <stdlib.h>

#define NMIN 1 // n min/max
#define NMAX 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

typedef struct{
  int k; // degree
  int *v; // IDs of vertices adjacent to u
  int color; // white/gray/black
  int d; // the discover time
  int f; // the finish time
} Vertex;

void DFS(Vertex *, int);
void visit(Vertex *, int);
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

  DFS(V,n);
  output(V,n);
  
  for(i=1; i<=n; i++)
    free(V[i].v);
  free(V);

  return 0;
}

void DFS(Vertex *V, int n) {
  int u; // vertex ID

  for(u=1; u<=n; u++) // each vertex u in V
    V[u].color =  WHITE;

  time = 0;
  for(u=1; u<=n; u++) // each vertex u in V
    if(V[u].color==WHITE)
      visit(V,u);
}

void visit(Vertex *V, int u) {
  int i; // counter
  
  V[u].color = GRAY; // White vertex u has just been discovered
  V[u].d = ++time;

  for(i=0; i<V[u].k; i++) // each v in Adj[u], Explore edge (u,v)
    if(V[V[u].v[i]].color==WHITE)
      visit(V,V[u].v[i]);
  
  V[u].color = BLACK; // Blacken u, it is finished
  V[u].f= ++time;
}

void output(Vertex *V, int n) {
  int id; // counter

  for(id=1; id<=n; id++) {
    printf("%d ", id);
    printf("%d ", V[id].d);
    printf("%d\n", V[id].f);
  }
}

