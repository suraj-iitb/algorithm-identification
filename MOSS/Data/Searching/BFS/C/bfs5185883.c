#include <stdio.h>

#define MAX 100
#define INF 10000001

int M[MAX][MAX],Q[MAX],head,tail,n,d[MAX];

void enkyu(int x)
{
	Q[tail] = x;
	tail++;
}

int dekyu()
{
	int tmp;
	tmp = Q[head];
	head++;

	return tmp;
}



//幅優先探索

void bfs(int s)
{

	int i,u,v;
	enkyu(s);
	
	for( i = 0; i < n; i++)
	{
		d[i] = INF;
	}
	d[s] = 0;
	
	while(head != tail)
	{
		u = dekyu();
		for(v = 0; v< n; v++)
		{
			if(M[u][v] == 0)continue;
			if(d[v] != INF)continue;
			d[v] = d[u] + 1;
			enkyu(v);
		}
	}
	for(i = 0; i < n; i++)
	{
		printf("%d ",i+1);
		if(d[i] == INF)
		{
			printf("-1\n");
		}
		else
		{
			printf("%d\n",d[i]);
		}
	}
}






int main()
{
	int i,v,j,k,u;

	head = 0; 
	tail = 0;

	scanf("%d",&n);

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			M[i][j] = 0;//初期化フェーズ
		}
	}

	for(i = 0; i < n; i++)
	{
		scanf("%d%d",&u,&k);
		u--;
		for(j = 0; j<k; j++)
		{
			scanf("%d",&v);
			v--;
			M[u][v] = 1;
		}
	}
	bfs(0);


	return 0;
}


