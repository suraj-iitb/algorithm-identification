#include<stdio.h>
#define N 105
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define INF 1000000
#define NIL -1

int n, head = 0, tail = 0;
int color[N], d[N], array[N][N], e[N], Q[N];

void Enqueque(int x){
  Q[tail] = x;
  tail++;
}

void BFS(int s){
  int i, u, next;
  for(i = 1; i < n+1; i++){
      color[i] = WHITE;
      d[i] = NIL;
  }

  color[s] = GRAY;
  d[s] = 0;
  Enqueque(s);

  while(head != tail){
    u = Dequeque();
    for(i = 1; i <= n; i++){
      if((color[i] == WHITE) && (array[u][i] == 1)){
	color[i] = GRAY;
	d[i] = d[u] + 1;
	Enqueque(i);
      }
    }
    color[u] = BLACK;
  }
}

int Dequeque(){
  head++;
  return Q[head - 1];
}
 
main(){

  scanf("%d", &n);

  int i, u, e, v, j;
  for(i = 1; i < n+1; i++){
    for(j = 1; j < n+1; j++){
      array[i][j] = 0;
    }
  }

  for(i = 1; i < n+1; i++){
    scanf("%d%d", &u, &e);
    for(j = 1; j <= e; j++){
      scanf("%d", &v);
      array[i][v] = 1;
    }
  }

  BFS(1);
  
  for(i = 1; i < n+1; i++){
    printf("%d ", i);
    printf("%d\n", d[i]);
  }
  return 0;
}
