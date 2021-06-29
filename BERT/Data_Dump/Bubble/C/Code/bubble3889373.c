#include <stdio.h>

int main( void ){
	int i, n, count, flag, tmp;
	
	scanf("%d", &n );
	
	int a[n];
	
	for( i = 0; i < n; i++ ){
		scanf("%d", &a[i] );
	}
	
	count = 0;
	flag = 1;
	while( flag == 1 ){
		flag = 0;
		for( i = n-1; i >= 1; i-- ){
			if( a[i] < a[i-1] ){
				tmp = a[i];
				a[i] = a[i-1];
				a[i-1] = tmp;
				count++;
				flag = 1;
			}
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
