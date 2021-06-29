#include<stdio.h>
#include<limits.h>
#define LEN 100

int Q[LEN];
int G[LEN][LEN];
int head,tail;
int d[LEN];
int n;

void enqueue(int x){
  Q[tail] = x;
  tail = (tail+1) % LEN;
}
int dequeue(){
  int  x = Q[head];
  head = (head+1)%LEN;
  return x;
}

void bfs(int s){
  int i;
  int u,v;
  enqueue(s);

  for(i=0;i<n;i++){
    d[i] = INT_MAX;
  }

  d[s] = 0;

  while(head!=tail){
    u = dequeue();
    for(v=0;v<n;v++){
      if(G[u][v] == 0)continue;
      if(d[v] != INT_MAX)continue;
      d[v] = d[u] + 1;
      enqueue(v);
    }
  }

  for(i=0;i<n;i++){
    printf("%d %d\n",i+1,((d[i] == INT_MAX)? -1 : d[i]));
  }
}

int main(){
  int k,u,v,i,j;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      G[i][j] = 0;
    }
  }

  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    u--;
    for(j=0;j<k;j++){
      scanf("%d",&v);
      v--;
      G[u][v] = 1;
    }
  }

  bfs(0);

  return 0;
}

