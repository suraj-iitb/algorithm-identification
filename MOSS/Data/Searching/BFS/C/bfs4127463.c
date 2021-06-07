/*　有向グラフを幅優先探索を用いて探索するプログラム　*/
#include <stdio.h>
#include <stdlib.h>

#define QSIZE 128
#define WHITE 0
#define BLACK 1
#define GLAY  2
#define INF -1

int d[101];      /*　頂点１からその頂点までの距離　*/
int k[101];      /* k[i] 頂点iの隣接頂点の数　*/
int *Adj[101];
int color[101];

void enqueue(int q[], int *, int *, int);
int dequeue(int q[], int *, int *);
void bfs(int q[], int *, int *, int, int);

int main()
{
  int u, n, i, j, head = 0, tail = 0, q[QSIZE];

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

  bfs(q, &head, &tail, 1, n);

  /*　各頂点について　id 距離d を表示　*/
  for( i = 1; i<=n; i++ )
    printf("%d %d\n", i, d[i]);
  
  return 0;
}


/*　キューqにint型整数numを挿入する関数 */
void enqueue(int q[], int *head, int *tail, int num)
{
  /*　キューqに挿入できる空きがあるか確認　*/
  if( *head == *tail+1 )
    {
      fprintf(stderr, "You can't insert integer in queue because queue is already full.\n");
      exit(2);
    }

  q[ *tail ] = num;
  *tail = (*tail+1)%QSIZE;
}


/*　キューqから要素を取り出して返す関数　*/
int dequeue(int q[], int *head, int *tail)
{
  int num;
  
  /*　キューqが空でないか確認　*/
  if( *head == *tail )
    {
      fprintf(stderr, "You can't take the integer of queue out because there are no integer in queue.\n");
      exit(2);
    }

  num = q[ *head ];
  *head = ( *head+1 )%QSIZE;

  return num;
}


/*　有向グラフに対して幅優先探索を行い、頂点sから各頂点への距離d(たどり着けない場合は-1)を求める関数*/
void bfs(int q[], int *head, int *tail, int s, int n)
{
  int u, i;

  /* colorをWHITEで初期化　*/
  for( i = 1; i<=n; i++ )
    {
      color[i] = WHITE;
      d[i] = INF;
    }

  color[s] = GLAY;
  enqueue(q, head, tail, s);
  d[s] = 0;                    /*　始点s自身の距離dを0に設定　*/
  
  /*　キューが空になるまで幅優先探索を行う*/
  while( *head != *tail )
    {
      u = dequeue(q, head, tail);

      /*　頂点uの隣接頂点の番号をキューに挿入し、距離dを求める　*/
      for( i = 0; i<k[u]; i++ )
	{
	  if( color[ *(Adj[u]+i) ] == WHITE )
	    {
	      color[ *(Adj[u]+i) ] = GLAY;
	      d[ *(Adj[u]+i) ] = d[u] + 1;
	      enqueue(q, head, tail, *(Adj[u]+i) );
	    }
	}

      color[u] = BLACK;
    }
}

