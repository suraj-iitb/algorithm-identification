#include<stdio.h>
#define N 100
#define LINK 1
#define NOT_LINK -1
#define WHITE 2
#define GRAY 3
#define BLACK 4

void enqueue(int);
int dequeue(void);
void BFS(int); //幅優先探索

int head = 0;
int tail = 0;
int q[N]; //キュー
int d[N+1]; //始点から各頂点iまでの距離
int m[N+1][N+1]; //頂点iから頂点jに辺があるかないか
int n; //頂点の数

int main(){
  int u, k, v; //uは頂点, kはuの出次数, kはuに隣接する頂点
  int i, j;

  //初期化
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      m[i][j] = NOT_LINK;
    }
  }

  //入力
  scanf("%d", &n);
  for(i=0;i<n;i++){
    scanf("%d %d", &u, &k);
    for(j=0;j<k;j++){
      scanf("%d", &v);
      m[u][v] = LINK;
    }
  }

  //幅優先探索開始、始点は1
  BFS(1);

  //出力
  for(i=1;i<=n;i++) printf("%d %d\n", i, d[i]);
    
  return 0;
}

void enqueue(int x){
  q[tail] = x;
  if(tail == N-1) tail = 0;
  else tail++;
}

int dequeue(void){
  int x;
  x = q[head];
  if(head == N-1) head = 0;
  else head++;
  return x;
}

void BFS(int s){
  int color[N+1];
  int u, v;
  int i;

  //初期化
  for(i=1;i<=n;i++){
    color[i] = WHITE;
    d[i] = NOT_LINK;
  }

  //始点の設定
  color[s] = GRAY;
  d[s] = 0;
  enqueue(s);

  while(head != tail){
    u = dequeue(); //uの訪問を完了させる
    for(v=1;v<=n;v++){
      //u -> v　かつ vが未訪問
      if(m[u][v] == LINK && color[v] == WHITE){
	color[v] = GRAY;
	d[v] = d[u] + 1;
	enqueue(v);
      }
    }
    color[u] = BLACK;
  }
  
}

