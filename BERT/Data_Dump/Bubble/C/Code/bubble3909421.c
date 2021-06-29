#include<stdio.h>

int main(void)
{
	int n, c, i, x, z;
	scanf( "%d", &n );
	int a[n];
	for( i = 0; i < n; i++ ){
		scanf( "%d", &a[i] );
	}
	
	c = 0;
	x = 1;
	
	while( x == 1 ){
		x = 0;
		for( i = n-1; i > 0; i-- ){
			if( a[i] < a[i-1] ){
				z = a[i];
				a[i] = a[i-1];
				a[i-1] = z;
				x = 1;
				c++;
			}
		}
	}
	
	printf( "%d", a[0] );
	for( i = 1; i < n; i++ ){
		printf( " %d", a[i] );
	}
	
	printf( "\n%d\n", c );
	
	return 0;
}
