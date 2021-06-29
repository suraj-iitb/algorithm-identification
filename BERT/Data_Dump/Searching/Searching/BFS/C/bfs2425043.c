#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX 100
#define INFTY INT_MAX
#define WHITE 0
#define GRAY 1
#define BLACK 2

/* Prototype Declaration */
void enqueue(int);
int dequeue(void);
int isEmpty(void);
int isFull(void);
void breadthFirstSearch(int);

/* Global Variables */
int Queue[MAX];
int head, tail;
int AM[MAX][MAX], color[MAX], d[MAX];
int n;

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

  breadthFirstSearch(0);

  for ( i = 0; i < n; i++ ) {
    printf("%d ", i + 1);
    if ( d[i] == INFTY )
      printf("-1\n");
    else
      printf("%d\n", d[i]);
  }

  return 0;
}

/* Queue Statements */
void enqueue(int x) {
  if ( isFull() ) {
    fprintf(stderr, "Error : Queue Overflow\n");
    exit(1);
  }

  Queue[tail] = x;

  // Ring Buffer
  if ( tail + 1 == MAX ) tail = 0;
  else tail++;

}

int dequeue(void) {
  int e;

  if ( isEmpty() ) {
    fprintf(stderr, "Error : Queue Underflow\n");
    exit(2);
  }

  e = Queue[head];

  // Ring Buffer
  if ( head + 1 == MAX ) head = 0;
  else head++;

  return e;
}

int isEmpty() {
  return ( head == tail ) ? 1 : 0;
}

int isFull() {
  return ( head == ((tail + 1) % MAX) ) ? 1 : 0;
}

/* Breadth First Search Statement */
void breadthFirstSearch(int s) {
  int i, u, v;

  for ( i = 0; i < n; i++ ) {
    color[i] = WHITE;
    d[i] = INFTY;
  }

  color[s] = GRAY;
  d[s] = 0;
  enqueue(s);

  while ( !isEmpty() ) {
    u = dequeue();
    for ( v = 0; v < n; v++ ) {
      if ( AM[u][v] == 1 && color[v] == WHITE ) {
        color[v] = GRAY;
        d[v] = d[u] + 1;
        enqueue(v);
      }
    }
    color[u] = BLACK;
  }
}
