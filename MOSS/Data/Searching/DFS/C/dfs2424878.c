#include <stdio.h>
#define MAX 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

/* Prototype Declaration */
void depthFirstSearch(void);
void dfsVisit(int);

/* Global Variables */
int AM[MAX+1][MAX+1]; //Adjacency Matrix
int color[MAX], d[MAX], f[MAX];
int n, time;

int main() {
  int i, j;
  int u, k, v;

  scanf("%d", &n);

  //Initialize Adjacency Matrix
  for ( i = 0; i < n; i++ )
    for ( j = 0; j < n; j++ )
      AM[i][j] = 0;

  for ( i = 0; i < n; i++ ) {
    scanf("%d%d", &u, &k);
    for ( j = 0; j < k; j++ ) {
      scanf("%d", &v);
      AM[u - 1][v - 1] = 1;
    }
  }

  //Depth First Search for The Graph
  depthFirstSearch();

  for ( i = 0; i < n; i++ )
    printf("%d %d %d\n", i + 1, d[i], f[i]);

  return 0;
}

/* Depth First Search Statements */
void depthFirstSearch() {
  int i;
  for ( i = 0; i < n; i++ )
    color[i] = WHITE;

  for ( i = 0; i < n; i++ )
    if ( color[i] == WHITE )
      dfsVisit(i);
}

void dfsVisit(int u) {
  int v;
  color[u] = GRAY;
  d[u] = ++time;
  for ( v = 0; v < n; v++ ) {
    if ( AM[u][v] == 1 && color[v] == WHITE )
      dfsVisit(v);
  }
  color[u] = BLACK;
  f[u] = ++time;
}
