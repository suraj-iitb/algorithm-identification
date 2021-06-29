#include<stdio.h>

int main( void ){
	int i, j, k, n, v;
	
	scanf("%d", &n );
	
	int a[n];
	
	for( i = 0; i < n; i++ ){
		scanf("%d", &a[i] );
	}
	
	for( k = 0; k < n; k++ ){
		printf("%d", a[k] );
		if( k != n-1 ){
			printf(" ");
		}
		else{
			printf("\n");
		}
	}
	
	for( i = 1; i <= n-1; i++ ){
		v = a[i];
		j = i - 1;
		
		while( j >= 0 && a[j] > v ){
			a[j+1] = a[j];
			j--;
		}
		
		a[j+1] = v;
		for( k = 0; k < n; k++ ){
			printf("%d", a[k] );
			if( k != n-1 ){
				printf(" ");
			}
			else{
				printf("\n");
			}
		}
	}
	
	return 0;
}
