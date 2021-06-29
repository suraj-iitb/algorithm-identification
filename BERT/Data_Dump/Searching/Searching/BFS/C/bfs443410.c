#include <stdio.h>
#define SIZE 201

int que[SIZE];
int head, tail;

int init() { head = tail = 0; }
int empty() { return head == tail; }
int push(int elm) { que[tail] = elm; tail = (tail+1)%SIZE; }
int front() { return que[head]; }
void pop() { head = (head+1)%SIZE; }

int bfs(int n, int G[][101], int *cost) {
  int i;
  init();
  push(1);
  cost[1] = 0;
  while(!empty()) {
    int p = front();
    pop();
    for(i = 1; i <= n; ++i) {
      if(!G[p][i]) continue;
      if(cost[i] != -1) continue;
      cost[i] = cost[p] + G[p][i];
      push(i);
    }
  }
}


int main() {
  int n;
  int i,j,k;
  int G[101][101];
  int src, dst;
  int cost[101];
  for(i = 0; i < 101; ++i)  {
    cost[i] = -1;
    for(j = 0; j < 101; ++j) {
      if(i == 0) G[i][j] = 1;
      else G[i][j] = 0;
    }
  }
  scanf("%d", &n);
  for(i = 1; i <= n; ++i) {
    scanf("%d %d", &src, &k);
    while(k--) {
      scanf("%d", &dst);
      G[src][dst] = 1;
    }
  }
  bfs(n,G,cost);
  for(i = 1; i <= n; ++i) {
    printf("%d %d\n", i, cost[i]);
  }
  return 0;
}
