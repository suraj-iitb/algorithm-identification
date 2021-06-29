#include <stdio.h>

#define N 100
#define INF 100000000

int n, M[N][N];
int d[N];
int Q[N];
int head, tail;

void enqueue(int x){

  Q[tail] = x;

  if(tail+1 == N){
    tail = 0;
  } else {
    tail++;
  }
}

int dequeue(){
  int x;

  x = Q[head];
  if(head+1 == N){
    head = 0;
  } else {
    head++;
  }
  return x;
}

void bfs(int s){
  int u, i, v, check=0;

  enqueue(s);

  for(i=0; i<n; i++) d[i] = INF;
  d[s] = 0;

  while(head != tail){
    u = Q[head];
    dequeue();
    for(v=0; v<n; v++){
      if(M[u][v] == 0) continue;
      if(d[v] != INF) continue;
      d[v] = d[u]+1;
      enqueue(v);
    }
  }

  for(i=0; i<n; i++){
    check = (d[i]==INF) ? (-1) : d[i];
    printf("%d %d\n", i+1, check);
  }

}

int main(){
  int i, j, u, k, v;

  scanf("%d", &n);
  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      M[i][j] = 0;
    }
  }

  for(i=0; i<n; i++){
    scanf("%d %d", &u, &k);
    u--;
    for(j=0; j<k; j++){
      scanf("%d", &v);
      v--;
      M[u][v] = 1;
    }
  }

  bfs(0);

  return 0;
}
