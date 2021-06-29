#include <stdio.h>

int main( void )
{
	int n, q, i, j, count = 0;
	
	scanf( "%d", &n );
	
	int S[n];
	
	for( i = 0; i < n; i++ )
	{
		scanf( "%d", &S[i] );
	}
	
	scanf( "%d", &q );
	
	int T[q];
	
	for( i = 0; i < q; i++ )
	{
		scanf( "%d", &T[i] );
	}
	
	
	for( i = 0; i < q; i++ )
	{
		j = 0;
		S[n] = T[i];
		
		while( S[j] != T[i] )
		{
			j++;
		}
		
		if( j!= n )
		{
			count++;
		}
	}
	
	printf( "%d\n", count );
	
	return 0;
}
