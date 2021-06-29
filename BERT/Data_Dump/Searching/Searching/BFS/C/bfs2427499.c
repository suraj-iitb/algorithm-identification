#include <stdio.h>
#include <string.h>
#define Q_LEN 1000000
int queue[Q_LEN];
int head, tail;
void enque(int i) {
  if((tail+1)%Q_LEN == head) return;
  queue[tail] = i;
  tail++;
  tail %= Q_LEN;
}
int deque() {
  int res;
  if(head == tail) return -1;
  res = queue[head];
  head++;
  head %= Q_LEN;
  return res;
}
int empty() {
  return head == tail;
}
int main() {
  int n;
  int A[101][101] = {{}};
  int i, j;
  scanf("%d", &n);
  for(i = 0; i < n; i++) {
    int u, k;
    scanf("%d %d", &u, &k); --u;
    for(j = 0; j < k; j++) {
      int v;
      scanf("%d", &v); --v;
      A[u][v] = 1;
    }
  }
  int dist[101];
  memset(dist, -1, sizeof(dist));
  enque(0);
  dist[0] = 0;
  while(!empty()) {
    int u = deque();
    for(i = 0; i < n; i++) {
      if(A[u][i] == 1 && dist[i] == -1) {
	enque(i);
	dist[i] = dist[u]+1;
      }
    }
  }
  for(i = 0; i < n; i++) printf("%d %d\n", i+1, dist[i]);

  return 0;
}
