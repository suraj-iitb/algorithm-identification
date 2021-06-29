#include <stdio.h>
#include <stdlib.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define INF 10000
#define empty 0

void BFS(int);
void enqueue(int);
int dequeue();
void visit(int);

int num=0,n,Q,cnt=0;
int d[105];
//int queue[105],color[105];
int G[105][105];

int main()
{
  int i,j,u,k,v;

  scanf("%d",&n);
  if(n<1 || n>100) exit(1);

  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      G[i][j] = 0; //初期化
    }
  }
  
  for(i=0;i<n;i++){
    
    scanf("%d %d",&u,&k);
    for(j=0;j<k;j++){
      scanf("%d",&v);
      G[u-1][v-1] = 1; //0オリジン
    }
    d[i+1] = INF;
  }

  visit(0);
  
  for(i=0;i<n;i++)
    printf("%d %d\n",i+1,((d[i]==INF)?(-1):d[i]));

  return 0;
}
/*
void BFS(int s)
{
  int i,u;
  
  for(i=0;i<n;i++){
    color[i] = WHITE; //全部白
    d[i] = INF; //支点から辿りつけるかどうかの判断をする
  }
  color[s] = GRAY; //訪問1回目
  d[s] = 0; //支点の深さは0
  num = empty; //キューに入ってる数
  enqueue(s); //0をキューの0番目に入れる

  while(num != empty){ //キューの数が空じゃない限り回す
    u = dequeue(); 
    for(i=0;i<n;i++){
      if(G[u][i] == 0) continue; 
      if(d[i] != INF) continue; //深さが1回決まったら変えない
      if(color[i] == WHITE){
	color[i] = GRAY;
	d[i] = d[u]+1;
	enqueue(i);
      }
    }
    color[u] = BLACK;
  }
}

void enqueue(int s)
{
  queue[num] = s;
  num++;
}

int dequeue()
{
  int s,i;

  s = queue[0];

  for(i=0;i<queue[num];i++)
    queue[i] = queue[i+1];

  num--;
  queue[num] = 0;
  
  return s;
}
*/
void visit(int a)
{
  int i;

  d[a] = cnt; //cntは深さをカウントする変数
  for(i=0;i<n;i++){
    if(G[a][i] == 1 && d[i] > cnt){
      cnt++;
      visit(i);
      cnt--;
    }
  }
}

