#include<stdio.h>

#define N 100
#define INF 999999
#define LEN 1000

int n,M[N][N];
int d[N];

int Q[LEN+1];
int head = 0, tail = 0;

void enqueue(int x){
  Q[tail] = x;
  tail = (tail + 1) % LEN;
}

int dequeue(){
  int x;
  x = Q[head];
  head = (head + 1) % LEN;
  return x;
}

void bfs(int s){
  int i,u,v,swap;
  enqueue(s);
  for(i = 0; i < n; i++){
    d[i] = INF;
  }
  d[s] = 0;
  while(head != tail){
    u = Q[head];
    swap = dequeue();
    for(v = 0; v < n; v++){
      if(M[u][v] == 0)continue;
      if(d[v] != INF)continue;
      d[v] = d[u] + 1;
      enqueue(v);
    }
  }
  for(i = 0; i < n; i++){
    printf("%d ",i + 1);
    if(d[i] == INF) printf("%d",-1);
    else printf("%d",d[i]);
    printf("\n");
  }
  
}
 
int main(){
  int i,j,u,k,v;
  
  scanf("%d",&n);
  
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      M[i][j] = 0;
    }
  }

  for(i = 0; i < n; i++){
    scanf("%d%d",&u,&k);
    u--;
    for(j = 0; j < k; j++){
      scanf("%d",&v);
      v--;
      M[u][v] = 1;
    }
  }
  bfs(0);
  
  return 0;
}

