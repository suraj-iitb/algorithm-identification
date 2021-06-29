#include<stdio.h>
#define MAX 100
#define NOT_FOUND -1
#define BLACK 1
#define WHITE 0
#define GRAY 2

void push(int);
int pop(void);
void DFS(int, int); //深さ優先探索
int adjust(int, int);

int adj[MAX+1][MAX+1] = {};
int s[MAX];
int top = 0;
int time = 0;
int color[MAX];
int d[MAX]; //発見時刻
int f[MAX]; //完了時刻

int main(){
  int n, u, k, v;
  int i, j;

  //1オリジンで
  scanf("%d", &n);
  for(i=0;i<n;i++){
    scanf("%d %d", &u, &k);
    for(j=0;j<k;j++){
      scanf("%d", &v);
      adj[u][v] = 1;
    }
  }

  //colorの初期化
  for(i=1;i<=n;i++){
    color[i] = WHITE;
  }

  //まだ訪問していないuを始点にする
  for(i=1;i<=n;i++){
    if(color[i] == WHITE) DFS(n, i);
  }

  for(i=1;i<=n;i++) printf("%d %d %d\n", i, d[i], f[i]);

  return 0;
}

void push(int x){
  top++;
  s[top] = x;
}

int pop(){
  top--;
  return s[top+1];
}

//uに隣接する頂点を探す
int adjust(int n, int u){
  int i;
  for(i=1;i<=n;i++){
    if(adj[u][i] == 1 && color[i] == WHITE) return i;
  }
  return NOT_FOUND;
}

void DFS(int n, int u){
  int v;
  
  push(u);
  color[u] = GRAY;
  time++;
  d[u] = time;

  while(top != 0){
    u = s[top];
    v = adjust(n, u);
    if(v != NOT_FOUND){
      if(color[v] == WHITE){
	color[v] = GRAY;
	time++;
	d[v] = time;
	push(v);
      }
    }
    else{
      pop();
      color[u] = BLACK;
      time++;
      f[u] = time;
    }
  }
}

