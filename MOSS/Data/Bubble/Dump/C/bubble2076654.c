#include <stdio.h>

int main () {
	
	int i, j, N, a[1000], flag, k, temp;
	int count = 0 ;

	
	scanf ("%d",&N) ;
	for ( i = 0 ; i < N ; i ++ ) {
		scanf("%d", &a[i] ) ;
	}
	
	flag = 1 ;
	while (flag ) {
		flag = 0 ;
		for ( j = N - 1 ; j >= 1 ; j-- ) {
			if (a[j] < a[j-1] ) { 
				temp = a[j] ;
				a[j] = a[j-1] ;
				a[j-1] = temp ;
				flag = 1 ;
				count++ ;
			}
			
		}
		
	}
		for ( k = 0 ; k < N ; k++ ) {
			printf("%d",a[k] ) ;
				if (k != N-1)
					printf(" ");
					else 
					printf("\n");
		}
	printf("%d\n",count ) ;
	
	
	

return 0;
}
