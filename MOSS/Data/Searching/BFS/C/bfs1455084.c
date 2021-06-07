#include <stdio.h>
#define N 1001
#define inf 1000
int n, M[N][N];
int color[N], d[N], f[N], t;
int Q[2*N], head=0, tail=0;

void enqueue(int x){
  Q[tail++] = x;
}
int dequeue(){
  int x;
  x = Q[head++];
  return x;
}
void bfs(int s){
  int i, u, v;
  enqueue(s);
  for(i = 1; i <= n; i++) d[i] = inf;
  d[s] = 0;
  while(head != tail){
    u = dequeue();
    for(v = 1; v <= n; v++){
      if(M[u][v] == 0) continue;
      if(d[v] != inf) continue;
      d[v] = d[u] + 1;
      enqueue(v);
    }
  }
}

int main(){
  int u, k, v, i, j;
  scanf("%d", &n);
  for(i = 1; i <= n; i++){
    for(j = 1; j <= n; j++){
      M[i][j] = 0;
    }
  }
  for(i = 0; i < n; i++){
    scanf("%d %d",&u, &k);
    for(j = 0; j < k; j++){
      scanf("%d",&v);
      M[u][v] = 1;
    }
  }
  bfs(1);
  for(i = 1; i <= n; i++){
    if(d[i] == inf) d[i] = -1;
    printf("%d %d\n",i, d[i]);
  }
  return 0;
}
