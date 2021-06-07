#include<stdio.h>

int main(void)
{
	int n, q, i, c, z, d;
	scanf( "%d", &n );
	int s[n];
	for( i = 0; i < n; i++ ){
		scanf( "%d", &s[i] );
	}
	scanf( "%d", &q );
	int t[q];
	for( i = 0; i < q; i++ ){
		scanf( "%d", &t[i] );
	}
	
	c = 0;
	d = 0;
	for( i = 0; i < q; i++ ){
		for( z = 0; z < n; z++ ){
			if( t[i] == s[z] ){
				d = 1;
				s[z] = -1;
			}
		}
		if( d == 1 ){
			c++;
		}
		d = 0;
	}
	
	printf( "%d\n", c );
	
	return 0;
}
