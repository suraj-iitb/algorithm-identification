#include <stdio.h>
#include <limits.h>

#define WHITE 1
#define GRAY 2
#define BLACK -1

int Adj[101][101], d[101], time, n;
int head, tail;
int Q[100];

enque(int x){
  Q[tail] = x;
  if(tail + 1 == 100){
    tail = 0;
  }else{
    tail++;
  }
}

int deque(){
  int x = Q[head];
  if(head + 1 == 100){
    head = 0;
  }else{
    head++;
  }

  return x;

}  

int isEmpty(){
  if(tail == head){
    return 1;
  }else{
    return 0;
  }
}

bfs(){
  int s = 1, u, v;
  int color[101];

  for(u=2; u<=n; u++){
    color[u] = WHITE;
    d[u] = -1;
  }

  color[s] = GRAY;
  d[s] = 0;

  enque(s);

  while(!isEmpty(Q)){
    u = deque();
    for(v=1; v<=n; v++){
      if(Adj[u][v] && color[v] == WHITE){
	color[v] = GRAY;
	d[v] = d[u] + 1;
	enque(v);
      }
    }
    color[u] = BLACK;
  }

}


int main(){
  int i, j, u, k, temp;

  scanf("%d", &n);

  for(i=0; i<n; i++){
    scanf("%d%d", &u, &k);
    for(j=0; j<k; j++){
      scanf("%d",&temp);
      Adj[u][temp] = 1;
    }
  }

  bfs();

  for(i=1; i<=n; i++){
    printf("%d %d\n", i, d[i]);
  }

  return 0;

}
