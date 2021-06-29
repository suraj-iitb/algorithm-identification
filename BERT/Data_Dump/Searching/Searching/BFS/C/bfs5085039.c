#include <stdio.h>
#include <stdlib.h>

/*見やすさを考慮して配列やループを0ではなく1から始める*/

typedef struct adj_list //adjacency list: 隣接リスト
{
	int *v; //隣接頂点を収納する配列
	int ak; //配列の大きさ
}adj_list_t;

adj_list_t *Adj_l; //隣接リストAdj_l[n] ただしAdj_l[1]~Adj_l[n]を使用

int *d; //d[v]: 頂点vが頂点１からどれだけ離れているかを記録する

void BFS(int k); //幅優先探索(Breath First Search) 頂点kの隣接点の距離が-1あるいは頂点kの距離+1より大きいなら隣接点を更新してやり更新点にBFSを促す

int main(void)
{
	//定義
	int n, u, k; //n: 頂点数, u: 頂点番号, k: uの出次数
	int uj; //j番目に隣接する頂点の番号
	int length = 0; //距離
	//入力, 動的確保および初期化. 配列と頂点番号で数字の始まりが異なるのに注意
	scanf("%d", &n);
	Adj_l = (adj_list_t*)malloc(sizeof (adj_list_t) * (n+1)); //Adj_l[0]を使わない
	d = (int *)malloc(sizeof(int) * (n+1)); //0と1~nのn+1個
	
	int i,j;
	for(i=1; i<=n; i++)
	{
		scanf("%d %d", &u, &k);
		Adj_l[u].v = (int *) malloc (sizeof (int) * (k+1)); //v[0]は使わない
		Adj_l[u].ak = k;
		for(j=1; j<=k; j++)
		{
			scanf("%d", &uj);
			Adj_l[u].v[j] = uj;
		}
	}
	for(i=1; i<=n; i++) //配列dの初期化。初期値は-1とする -1ならその頂点は頂点1からたどり着けない
	{
		d[i] = -1;
	}
	
	//BFS
	d[1] = 0; //頂点１は頂点１から距離０である
	BFS(1);//k:次に向かう頂点番号
	
	//出力
	
	for(i=1; i<=n; i++)
	{
		printf("%d ", i); //id
		printf("%d", d[i]); //頂点1からその頂点までの距離
		printf("\n");
	}
		
	//動的配列の解放
	free(d); d = NULL;
	for(i=1; i<=n; i++)
	{
		free(Adj_l[i].v); Adj_l[i].v = NULL;
	}
	free(Adj_l); Adj_l = NULL;
	
	
	return 0;
}

void BFS(int k) //幅優先探索(Breath First Search)
{
	//k:次に向かう頂点番号
	//定義 
	int aaa = k;//現在処理する頂点番号
	
	//動作
	int i;
	for(i=1; i<=Adj_l[aaa].ak; i++) //現在地の頂点の、隣接点の中で距離が、-1あるいは現在地の距離＋１より大きいなら、更新する
	{
		if(d[Adj_l[aaa].v[i]] == -1 || d[Adj_l[aaa].v[i]] > d[aaa] + 1)
		{
			d[Adj_l[aaa].v[i]] = d[aaa] + 1;
		}
	}
	for(i=1; i<=Adj_l[aaa].ak; i++)//更新した頂点に対してBFSを促す
	{
		if(d[Adj_l[aaa].v[i]] == d[aaa] + 1)
		{
			BFS(Adj_l[aaa].v[i]);
		}
	}
}
