#include<stdio.h>
#define N 100
#define INF 100000000
int n,M[N][N],d[N],Q[N],tail = 0,head = 0;

void push(int a) {
  Q[tail] = a;
  tail ++;
}
int pop() {
  int a;
  a = Q[head];
  head++;
  return a;
}

void bfs(int s) {
  int i,u,v;

  push(s);
  for(i = 0;i < n;i++) d[i] = INF;
  d[s] = 0;

  while(tail != head) {
    u = pop();
    for(v = 0;v < n;v++) {
      if(M[u][v] == 0) continue;
      if(d[v] != INF) continue;
      d[v] = d[u] + 1;
      push(v);
    }
  }
  for(i = 0;i < n;i++) {
    if(d[i] == INF) d[i] = -1;
    printf("%d %d\n",i + 1,d[i]);
  }
}

int main() {
  int i,j,u,k,v;

  scanf("%d",&n);
  for(i = 0;i < n;i++) {
    for(j = 0;j < n;j++) M[i][j] = 0;
  }

  for(i = 0;i < n;i++) {
    scanf("%d%d",&u,&k);
    u--;
    for(j = 0;j < k;j++) {
      scanf("%d",&v);
      v--;
      M[u][v] = 1;
    }
  }

  bfs(0);

  return 0;
}

