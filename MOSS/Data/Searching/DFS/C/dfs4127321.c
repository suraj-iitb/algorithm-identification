#include <stdio.h>
#include <stdlib.h>

#define WHITE 0
#define BLACK 1
#define GLAY  2

int *Adj[101];
int d[101];
int f[101];
int k[101];
int color[101];
int t;

void dfs(int);
void visit(int);

int main()
{
  int i, j, n, u;

  scanf("%d", &n);
  for( i = 1; i<=n; i++ )
    {
      /* 各頂点ごとに隣接する頂点の番号を格納する配列を用意 */
      scanf("%d", &u);
      scanf("%d", &k[u]);
      Adj[u] = (int *)malloc( sizeof(int) * k[u] );

      /* 頂点uに隣接する頂点の番号を読み込む */
      for( j = 0; j<k[u]; j++ )
	scanf("%d", Adj[u]+j);
    }

  dfs(n);
  
  /* 結果出力 */
  for( i = 1; i<=n; i++ )
    printf("%d %d %d\n", i, d[i], f[i]);

  for( i = 0; i<=100; i++ )
    free(Adj[i]);
  return 0;
}


/* 有向グラフに対して深さ優先探索を行う関数 */
void dfs(int n)
{
  int i;

  /* colorをWHITEで初期化 */
  for( i = 1 ; i<=n; i++ )
    color[i] = WHITE;

  /* まだ訪れていない頂点を訪れる */
  for( i = 1; i<=n; i++ )
    {
      if( color[i] == WHITE )
	visit(i);
    }
}


/* 頂点uとそれに隣接する頂点を再帰的に訪れ、タイムスタンプを押す関数 */
void visit(int u)
{
  int i;

  color[u] = GLAY;     /* 頂点uを訪れたと設定 */
  d[u] = ++t;       /* 発見時刻スタンプを押す */

  for( i = 0; i<k[u]; i++ )
    {
      if( color[ *(Adj[u]+i) ] == WHITE )
	visit( *(Adj[u]+i) );
    }

  color[u] = BLACK;       /* 頂点uを調べ終わったと設定 */
  f[u] = ++t;          /* 終了時刻スタンプを押す */
}

