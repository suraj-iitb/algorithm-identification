#include <stdio.h>
#include <stdlib.h>

typedef struct adj_list //adjacency list: 隣接リスト
{
	int *v; //隣接頂点を収納する配列
	int ak; //配列の大きさ
}adj_list_t;

adj_list_t *Adj_l; //隣接リストAdj_l[n] ただしAdj_l[1]~Adj_l[n]を使用

int *d; //d[v]: vを最初に発見した発見時刻を記録する
int *f; //f[v]: vの隣接リストを調べ終えた完了時刻を記録する。

int DFS(int n, int k, int t); //深さ優先探索(Depth First Search)

int main(void)
{
	//定義
	int n, u, k; //n: 頂点数, u: 頂点番号, k: uの出次数
	int uj; //j番目に隣接する頂点の番号
	int time = 0; //時刻
	//入力, 動的確保 初期化 配列と頂点番号で数字の始まりが異なるのに注意
	scanf("%d", &n);
	Adj_l = (adj_list_t*)malloc(sizeof (adj_list_t) * (n+1)); //Adj_l[0]を使わずAdj_l[1]~Adj_l[n]を使う→n+1個
	d = (int *)malloc(sizeof(int) * (n+1)); //0と1~nのn+1個
	f = (int *)malloc(sizeof(int) * (n+1)); //0と1~nのn+1個
	
	int i,j;
	for(i=0; i<n; i++)
	{
		scanf("%d %d", &u, &k);
		Adj_l[u].v = (int *) malloc (sizeof (int) * k);
		Adj_l[u].ak = k;
		for(j=0; j<k; j++)
		{
			scanf("%d", &uj);
			Adj_l[u].v[j] = uj;
		}
	}
	for(i=0; i<n+1; i++)
	{
		d[i] = 0;
	}
	for(i=0; i<n+1; i++)
	{
		f[i] = 0;
	}
	
	//DFS
	for(i=1; i<=n; i++)
	{
		if(d[i]==0) /*未発見の頂点が残っていれば*/
		{
			time = DFS(n, i, time);
		}
	}
	//出力
	
	for(i=1; i<=n; i++)
	{
		printf("%d ", i); //id
		printf("%d ", d[i]);
		printf("%d", f[i]);
		printf("\n");
	}
		
	//動的配列の解放
	for(i=0; i<n+1; i++)
	{
		free(Adj_l[i].v); Adj_l[i].v = NULL;
	}
	free(Adj_l); Adj_l = NULL;
	free(d); d = NULL;
	free(f); f = NULL;
	
	return 0;
}

int DFS(int n, int k, int t) //深さ優先探索(Depth First Search)
{
	//定義 
	int time = t; //時刻
	
	time++;
	d[k] = time;
	int i;
	for(i=0; i<Adj_l[k].ak; i++)
	{
		if(d[Adj_l[k].v[i]] == 0) /*未発見の頂点が残っていれば*/
		{
			time = DFS(n, Adj_l[k].v[i], time);
		}
	}
	time++;
	f[k] = time;
	
	return time;
}
