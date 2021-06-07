#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int G[103][103];
int n,time,top;
int S[103];
char color[103];
int d[103];
int f[103];

void dfs(void);
void initialize(void);
int isEmpty(void);
int isFull(void);
void push(int);
void pop(void);
int next(int);
void visit(int);

int main()
{
  int i,u,k,j;
  int *U;

  /* 初期化 */
  for(i = 0;i < 103;i++){
    for(j = 0;j < 103;j++){
      G[i][j] = 0;
    }
  }

  /* 発見時刻の初期化 */
  for(i = 0;i < n;i++){
    d[i] = 0;
  }

  /* stackの初期化 */
  initialize();

  /* グラフG */
  scanf("%d",&n);

  for(i = 0;i < n;i++){
    scanf("%d",&u);
    scanf("%d",&k);

    U = (int *)malloc(sizeof(int) * k);
    if(U == NULL) exit(0);

    for(j = 0;j < k;j++){
      scanf("%d",&U[j]);
      G[u][U[j]] = 1;
    }
  }

  dfs();

  /* 出力 */
  for(i = 1;i <= n;i++){
    printf("%d %d %d\n",i,d[i],f[i]);
  }

  return 0;
 }

void dfs(void)
{
  int u;
  
  for(u = 1;u <= n;u++){
    color[u] = 'W'; // WHITE
  }
  time = 0;
  for(u = 1;u <=n; u++){
    if(color[u] == 'W') visit(u);
  }
}

void initialize(void)
{
  top = 0;
}

int isEmpty(void)
{
  /* top == 0なら1を返す */
  if(top == 0) return 1;
  return 0;
}

int isFull(void)
{
  /* top >= MAX(103) - 1なら1を返す */
  if(top >= 103 - 1) return 1;
  return 0;
}

void push(int x)
{
  if(isFull() == 1){
    fprintf(stderr,"オーバーフロー\n");
    exit(1);
  }

  top++;
  S[top] = x;
}

void pop(void)
{
  if(isEmpty() == 1){
    fprintf(stderr,"アンダーフロー\n");
    exit(1);
  }

  top--;
}

void visit(int r)
{
  int u,v;

  push(r); // stack S にrを入れる

  color[r] = 'G'; // GRAY 発見済み
  d[r] = ++time;

  while(isEmpty() != 1){
    u = S[top];
    v = next(u); // 次の探索場所を返す

    if(v != -1){
      if(color[v] == 'W'){
	push(v);
	color[v] = 'G';
	d[v] = ++time;
      }
    }

    else{
      pop();
      color[u] = 'B'; // BLACK 探索済み
      f[u] = ++time;
    }
  }
}

int next(int u)
{
  int i;

  for(i = 1; i <= n;i++){
    if(G[u][i] == 1){
      if(d[i] == 0) return i;
    }
  }

  return -1;
}
