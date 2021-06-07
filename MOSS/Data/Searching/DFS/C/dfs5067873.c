#define N 100

int n;
int time = 0; //時間
int d[N+1], f[N+1];
int M[N+1][N+1] = {0};
int count[N+1] = {0}; //訪問した回数

void dfs_visit(int u)
{
	int i;
	
	time++; //時間を増やす
	
	count[u] = 1; //1回目の訪問
	d[u] = time; //1回目の訪問時間
	
	for( i=1; i<n+1; i++ )
	{
		if( (M[u][i] == 1) && (count[i] == 0) ) //隣接している頂点の中でまだ訪問していない点
		{
			dfs_visit(i); //訪問する
		}
	}
	
	time++; //時間を増やす
	count[u] = 2; //2回訪問したので
	f[u] = time; //完了時刻を記録
}

int main(void)
{
	int i, j, u, k, v;
	
	scanf("%d", &n);
	
	for( i=1; i<n+1; i++ )
	{
		scanf("%d", &u);
		scanf("%d", &k);
		
		for( j=1; j<k+1; j++ )
		{
			scanf("%d", &v);
			
			M[u][v] = 1;
		}
	}
	
	for( i=1; i<n+1; i++ )
	{
		if( count[i] == 0 ) //まだ訪問していないところを探索
		{
			dfs_visit(i);
		}
	}
	
	for( i=1; i<n+1; i++ )
	{
		printf("%d %d %d\n", i, d[i], f[i]);
	}
	
	return 0;
}
