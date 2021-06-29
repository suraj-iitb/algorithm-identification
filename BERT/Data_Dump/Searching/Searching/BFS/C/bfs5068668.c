#include<stdio.h>
#define n_MAX 101

int A[n_MAX][n_MAX]={0};
int d[n_MAX]={0};
int state[n_MAX]={0};
int Q[n_MAX]={0};
int head=0, tail=0;

void enqueue(int x)
{
	Q[tail] = x;
	tail = ( tail + 1 ) % n_MAX;
}
int dequeue()
{
	int x = Q[head];
	head =( head + 1 ) % n_MAX;
	return x;
}

void Breadth_first_search(int u, int n)
{
	int i;
	state[u]=1;
	d[u]=0;
	enqueue(u);
	
	while( head != tail )
	{
		u = dequeue();
		for( i = 1; i <= n; i++ )
		{
			if( A[u][i] == 1 && state[i] == 0 )
			{
				enqueue(i);
				state[i] = 1;
				d[i] = d[u] + 1;
			}
		}
		state[u]=2;
	}
}

int main(void)
{
	int n, u, k, v, i, j;
	
	scanf("%d", &n);
	for( i = 1; i <= n; i++ )
	{
		scanf("%d %d", &u, &k);
		for( j = 1; j <= k; j++ )
		{
			scanf("%d", &v);
			A[u][v]=1;
		}
	}
	
	Breadth_first_search(1, n);
	
	for( i = 1; i <= n; i++ )
	{
		if( state[i]==0 ) d[i]=-1;
		printf("%d %d\n", i, d[i]);
	}
	return 0;
}
