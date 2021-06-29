#include<stdio.h>

int search( int z, int s[], int n )
{
	int c = 0;
	int r = n;
	int l = 0;
	int m;
	while( l < r ){
		m = (l+r)/2;
		if( s[m] == z ){
			c = 1;
			break;
		}else if( z < s[m] ){
			r = m;
		}else{
			l = m+1;
		}
	}
	
	return c;
}

int main(void)
{
	int n, q, i, c, z;
	scanf( "%d", &n );
	int s[n];
	for( i = 0; i < n; i++ ){
		scanf( "%d", &s[i] );
	}
	
	c = 0;
	
	scanf( "%d", &q );
	
	for( i = 0; i < q; i++ ){
		scanf( "%d", &z );
		if( search( z, s, n ) == 1 ){
			c++;
		}
	}
	
	printf( "%d\n", c );
	
	return 0;
}
