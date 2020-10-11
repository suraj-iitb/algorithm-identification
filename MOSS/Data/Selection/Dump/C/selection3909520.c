#include<stdio.h>

int main(void)
{
	int i, c, x, n, min, s;
	
	scanf( "%d", &n );
	int a[n];
	for( i = 0; i < n; i++ ){
		scanf( "%d", &a[i] );
	}
	
	for( i = 0; i < n; i++ ){
		min = i;
		for( s = i; s < n; s++ ){
			if( a[s] < a[min] ){
				min = s;
			}
		}
		
		if( i != min ){
			x = a[i];
			a[i] = a[min];
			a[min] = x;
			c++;
		}
	}
	
	printf( "%d", a[0] );
	for( i = 1; i < n; i++ ){
		printf( " %d", a[i] );
	}
	printf( "\n%d\n", c );
	
	return 0;
}
