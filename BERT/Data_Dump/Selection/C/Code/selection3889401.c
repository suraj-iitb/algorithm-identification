#include <stdio.h>

int main( void ){
	int i, j, n, count, minj, tmp;
	
	scanf("%d", &n );
	
	int a[n];
	
	for( i = 0; i < n; i++ ){
		scanf("%d", &a[i] );
	}
	
	count = 0;
	for( i = 0; i < n; i++ ){
		minj = i;
		for( j = i; j < n; j++ ){
			if( a[j] < a[minj] ){
				minj = j;
			}
		}
		if( i != minj ){
			tmp = a[i];
			a[i] = a[minj];
			a[minj] = tmp;
			count++;
		}
	}
	
	for( i = 0; i < n; i++ ){
		if( i != n-1 ){
			printf("%d ", a[i] );
		}
		else{
			printf("%d\n", a[i] );
		}
	}
	printf("%d\n", count );
	
	return 0;
}
