#include <stdio.h>
#define N 100

int n, M[N][N], d[N];
char color[N], q[N+1];
int head, tail;

void enqueue( int x )
{
	q[tail] = x;
	if( tail + 1 == N+1 )
	{
		tail = 0;
	}
	else
	{
		tail++;
	}
}

int dequeue()
{
	int x;
	x = q[head];
	if( head + 1 == N+1 )
	{
		head = 0;
	}
	else
	{
		head++;
	}
	return x;
}

void bfs( int u )
{
	int s, i;
	color[u] = 'g';
	d[u] = 0;
	enqueue( u );
	
	while( head != tail )
	{
		s = dequeue();
		
		for( i = 0; i < n; i++ )
		{
			if( M[s][i] == 1 && color[i] == 'w')
			{
				color[i] = 'g';
				d[i] = d[s] + 1;
				enqueue( i );
			}
		}
		
		color[s] = 'b';
	}
}

int main( void )
{
	int u, k, i, j, a;
	
	scanf( "%d", &n );
	
	for( i = 0; i < n; i++ )
	{
		for( j = 0; j < n; j++ )
		{
			M[i][j] = 0;
		}
	}
	
	for( i = 0; i < n; i++ )
	{
		scanf( "%d", &u );
		scanf( "%d", &k );
		
		for( j = 0; j < k; j++ )
		{
			scanf( "%d", &a );
			M[u-1][a-1] = 1;
		}
	}
	
	for( i = 0; i < n; i++ )
	{
		color[i] = 'w';
	}
	
	for( i = 0; i < n; i++ )
	{
		d[i] = -1;
	}
	
	bfs( 0 );
	
	for( i = 0; i < n; i++ )
	{
		printf( "%d %d\n", i+1, d[i] );
	}
	
	return 0;
}
	
		
