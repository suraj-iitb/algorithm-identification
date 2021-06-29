#include <stdio.h>
#define INF -1//辿りつけなかったらー１
#define TRUE 1000
#define FALSE -1000
#define WHITE -2
#define GRAY -3
#define BLACK -4
#define N 100

void bfs(int);
int dequeue(void);
void enqueue(int);
int empty(void);

int Q[N], color[N], d[N];//d -> distance
int G[N+1][N+1];//隣接行列 0-origin
int head = 0, tail = 0;
int n = 0;

int main(){

  int i = 0, j = 0, l = 0, u = 0;
  int id = 0, k = 0;

  for(i = 0; i < N; i++){
    for(j = 0; j < N; j++){
      G[i][j] = 0;
    }
  }
  scanf("%d",&n);
  
  for(i = 0; i < n; i++){
    scanf("%d%d",&id,&k);
    for(j = 0; j < k; j++){
      scanf("%d",&u);
      G[id-1][u-1] = 1;
    }
  }

  bfs(0);

  for(i = 0; i < n; i++){
    printf("%d %d\n",i+1,d[i]);
  }
  return 0;
  
}

void bfs(int s){//s->source vertex

  int u = 0, v = 0, i = 0;
  
  for(u = 0; u < n; u++){//全て白に
    
    color[u] = WHITE;
    d[u] = INF;
    
  }
  
  color[s] = GRAY;
  d[s] = 0;
  enqueue(s);

  while(empty() == FALSE){
    
    u = dequeue();
    
    for(v = 0; v < n; v++){

      if(G[u][v] == 0)continue;//隣接していない
      if(d[v] != INF)continue;//一度通ったらとばす
      if(color[v] == WHITE){
	color[v] = GRAY;
	d[v] = d[u] + 1;
	enqueue(v);
      }
      
    }
    
    color[u] = BLACK;
    
  }
}

int dequeue(void){
  
  int q = 0;

  q = Q[head];
  head++;

  return q;
  
}

void enqueue(int q){
  
  Q[tail] = q;
  tail++;
  
}

int empty(void){
  
  if(head == tail){
    return TRUE;
  }
  else return FALSE;
  
}

