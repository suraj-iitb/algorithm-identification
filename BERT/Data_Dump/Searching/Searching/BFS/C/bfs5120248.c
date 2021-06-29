#include <stdio.h>
#define N 100

typedef struct {
  int state;
  int neighbor[N];
  int d;
} vertex_t;

typedef int data_t;
int n, head = 0, tail = -1, queue_num = 0;
vertex_t vertex[N+1];

void enqueue (data_t a[], data_t n) {
  tail++;
  a[tail] = n;
  queue_num++;
}

data_t dequeue (data_t a[]) {
  head++;
  queue_num--;
  return a[head-1];
}

void bfs(int i)
{
  int j, u;
  data_t queue[N];

  enqueue(queue, i);
  for(j = 1; j <= n; j++) vertex[j].d = -1;
  vertex[i].state = 1;
  vertex[i].d = 0;

  while(queue_num != 0) {
    u = dequeue(queue);
    for(j = 0; vertex[u].neighbor[j] > 0; j++) {
      if(vertex[vertex[u].neighbor[j]].state == 0) {
        vertex[vertex[u].neighbor[j]].state = 1;
        vertex[vertex[u].neighbor[j]].d = vertex[u].d + 1;
        enqueue(queue, vertex[u].neighbor[j]);
      }
    }
    vertex[u].state = 2;
  }

  for(i = 1; i <= n; i++) printf("%d %d\n", i, vertex[i].d);
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

  for(i = 1; i <= n; i++) vertex[i].state = 0;
  bfs(1);

  return 0;
}
