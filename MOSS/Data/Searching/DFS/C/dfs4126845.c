#include <stdio.h>
#include <stdlib.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2

void DFS(int);
void visit(int,int);

int t,G[105][105],u,v;
int color[105],d[105],f[105];

int main()
{
  int n,i,j,k;

  scanf("%d",&n);
  if(n<1 || n>100) exit(1);

  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      G[i][j] = 0;
    }
  }

  for(i=0;i<n;i++){
    scanf("%d %d",&u,&k);
    for(j=0;j<k;j++){
      scanf("%d",&v);
      G[u-1][v-1] = 1;
    }
  }

  DFS(n); //深さ検索
      
  return 0;
}

void DFS(int n)
{
  int u;
  
  for(u=0;u<n;u++) color[u] = WHITE; //初期化
  t = 0;

  for(u=0;u<n;u++)
    if(color[u] == WHITE) visit(u,n); //白なら訪問する

  for(u=0;u<n;u++)
    printf("%d %d %d\n",u+1,d[u],f[u]);
}

void visit(int u,int n)
{
  int i,v;
  
  color[u] = GRAY; //訪問したらグレーにする
  d[u] = ++t; //訪問の時間を記録

  for(v=0;v<n;v++){
    if(G[u][v] == 0) continue; //行列にない部分は飛ばす
    if(color[v] == WHITE) visit(v,n); //白なら再起的に訪問
  }
  color[u] = BLACK; //訪問が終わったら黒にする
  f[u] = ++t; //訪問完了の時間を記録
}

