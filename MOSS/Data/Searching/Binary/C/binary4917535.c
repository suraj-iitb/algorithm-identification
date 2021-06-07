#include <stdio.h>

int main( void )
{
	int n, q, i, count = 0;
	int left, right, mid;
	int j = 0;
	
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
		left = 0;
		right = n;
		
		while( left < right )
		{
			mid = ( left + right ) / 2;
			
			if( S[mid] == T[j] )
			{
				count++;
				break;
			}
			
			else if( T[j] < S[mid] )
			{
				right = mid;
			}
			
			else
			{
				left = mid + 1;
			}
		}
		
		j++;
	}
	
	printf( "%d\n", count );
	
	return 0;
}

