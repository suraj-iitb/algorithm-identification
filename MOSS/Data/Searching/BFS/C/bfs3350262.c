#include <stdio.h>

#define MAX 100
#define INF 10000000
#define WHITE 0
#define GRAY 1
#define BLACK 3

int n,M[MAX+1][MAX+1];
int D[MAX+1],colr[MAX+1],Q[MAX+1];
int tail,head;

void bfs(int);
void enqueue(int);
int dequeue(void);

int main(){
  int i,j,u,k,v;

  scanf("%d",&n);

  for(i=0;i<n+1;i++){
    for(j=0;j<n+1;j++){
      M[i][j] = 0;
    }
  }

  for(i=1;i<=n;i++){
    scanf("%d %d",&u,&k);

    for(j=1;j<=k;j++){
      scanf("%d",&v);
      M[u][v] = 1;
    }
  }

  bfs(1);

  return 0;
}

void bfs(int s){
  int i,u,v;

  for(i=0;i<n+1;i++){
    colr[i] = WHITE;
    D[i] = INF;
  }

  colr[s] = GRAY;
  D[s] = 0;
  enqueue(s);

  while(head != tail ){
    u = dequeue();

    for(v=1;v<=n;v++){
      if(M[u][v] == 1 && colr[v] == WHITE){
        colr[v] = GRAY;
        D[v] = D[u] + 1;
        enqueue(v);
      }
    }
    colr[u] = BLACK;
  }

  for(i=1;i<=n;i++){
    printf("%d %d\n",i,(D[i] == INF) ? (-1) : D[i]);
  }
}  
       
void enqueue(int x){
  Q[tail] = x;
  tail = (tail +1) % (MAX+1);
}

int dequeue(void){
  int x;

  x = Q[head];
  head = (head + 1) % (MAX +1);
  return x;
}
  
