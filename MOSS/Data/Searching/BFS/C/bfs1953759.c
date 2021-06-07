#include <stdio.h>

int n, M[1000][1000];
int d[1000];
int Q[1000];
int tail=0;
int head=0;

void enq(int x) {
  Q[tail++] = x;
}

int deq() {
  return Q[head++];
}

void bfs(int s) {
  int i,u,v;
  enq(s);
  for(i=1;i<=n;i++){
    d[i] = 100000;
    d[s] = 0;
  }
  while(head != tail){
    u = deq();
    for(v=1;v<=n;v++){
      if(M[u][v] == 0){
	continue;
      }
      if(d[v] != 100000){
	continue;
      }
      d[v] = d[u] +1;
      enq(v);
    }
  }
}

int main() {
  int i,j,u,k,v;

  scanf("%d",&n);
  for(i=1;i<=n;i++){
    for(j=0;j<n;j++){
      M[i][j] = 0;
    }
  }

  for(i=1;i<=n;i++){
    scanf("%d %d",&u,&k);
    for(j=0;j<k;j++){
      scanf("%d",&v);
      M[u][v] = 1;
    }
  }

  bfs(1);
  
  for(i=1;i<=n;i++){
    if(d[i] == 100000){
      d[i] = -1;
    }
    printf("%d %d\n",i,d[i]);
  }

  return 0;
}
