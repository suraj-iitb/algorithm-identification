#include<stdio.h>
#define N 100

int n, A[N][N], cp[N];

void Width(int a,int b)
{
	int i;
	
	b++; //インクリメント
	cp[a]=b;
	
	for(i=0; i<n; i++)
	{
		if(A[a][i]==1)
		{
			if(cp[i]<=b && cp[i]>=0){}
			else Width(i,b); //再帰的に繰り返す
		}
	}
}

int main(void)
{
	int i, j, k, u, x;
	
	scanf("%d", &n); //頂点数を受け取る
	
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			A[i][j] = 0; //初期化
		}
	}
	
	for(i=0; i<n; i++)
	{
		scanf("%d %d", &u, &k); //頂点番号とその出次数を受け取る
		
		for(j=0; j<k; j++)
		{
			scanf("%d", &x); //隣接頂点番号を受け取る
			
			A[u-1][x-1] = 1; //隣接するなら1を代入
		}
	}
	
	for(i=0; i<n; i++) cp[i] = -1; //初期化
	
	Width(0,-1);
	
	for(i=0; i<n; i++) printf("%d %d\n", i+1, cp[i]);
	
	return 0;
}

