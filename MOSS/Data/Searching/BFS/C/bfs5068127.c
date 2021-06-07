#include<stdio.h>
#define N 100

int q[N+1] = {0}; //キューの要素
int head = 0; //キューの先頭
int tail = 0; //キューの最後

int n;
int d[N+1]; //頂点1からの距離
int M[N+1][N+1] = {0};

int isEmpty()
{
	if( head == tail )
	{
		return 0; //キューが空の時0を返す
	}
	else
	{
		return 1; //キューが空でないとき1を返す
	}
}

void push(int s) //キューにsを入れる
{
	q[tail] = s;
	tail++;
}

int pop() //キューの先頭の要素を取り出す
{
	int a;
	
	a = q[head];
	head++;
	
	return a;
}

void bfs(int s)
{
	int i, u;
	
	for( i=1; i<n+1; i++ )
	{
		d[i] = -1; //頂点1からの距離を-1で初期化
	}
	
	push(s);
	
	d[s] = 0;
	
	while( isEmpty() == 1 ) //キューが空でない間続ける
	{
		u = pop();
		
		for( i=1; i<n+1; i++ )
		{
			if( (M[u][i] == 1) && (d[i] == -1) ) //隣接している頂点のなかで、頂点1からの距離が-1
			{
				d[i] = d[u] + 1;
				push(i);
			}
		}
	}
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
	
	bfs(1);
	
	for( i=1; i<n+1; i++ )
	{
		printf("%d %d\n", i, d[i]);
	}
	
	return 0;
}
