#include <stdio.h>
#include <string.h>
int queue[1000000];
int head, tail;

void enq(int i);

int deq();

int emp();


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
  enq(0);
  dist[0] = 0;
  while(!emp()) {
    int u = deq();
    for(i = 0; i < n; i++) {
      if(A[u][i] == 1 && dist[i] == -1) {
    enq(i);
    dist[i] = dist[u]+1;
      }
    }
  }
  for(i = 0; i < n; i++) printf("%d %d\n", i+1, dist[i]);
 
  return 0;
}

void enq(int i) {
  if((tail+1)%1000000 == head) return;
  queue[tail] = i;
  tail++;
  tail %= 1000000;
}

int deq() {
  int res;
  if(head == tail) return -1;
  res = queue[head];
  head++;
  head %= 1000000;
  return res;
}

int emp() {
  return head == tail;
}

