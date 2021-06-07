#include <stdio.h>
#define N 100

int n, M[N][N], d[N], f[N], time;
char color[N];

void dfu( int u )
{
	int S[N+1], top = 1, v, i;
	S[top] = u;
	color[u] = 'g';
	time++;
	d[u] = time;
	
	while( top > 0 )
	{
		u = S[top];
		v = -1;
		
		for( i = 0; i < n; i++ )
		{
			if( M[u][i] == 1 && color[i] == 'w')
			{
				v = i;
				break;
			}
		}
		
		if( v != -1 )
		{
			color[v] = 'g';
			time++;
			d[v] = time;
			top++;
			S[top] = v;
		}
		
		else
		{
			top--;
			color[u] = 'b';
			time++;
			f[u] = time;
		}
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
	
	time = 0;
	
	for( u = 0; u < n; u++ )
	{
		if( color[u] == 'w' )
		{
			dfu(u);
		}
	}
	
	for( i = 0; i < n; i++ )
	{
		printf( "%d %d %d\n", i+1, d[i], f[i] );
	}
	
	return 0;
}
	
		
