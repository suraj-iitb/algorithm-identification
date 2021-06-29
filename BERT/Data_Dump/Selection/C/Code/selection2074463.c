#include <stdio.h>

int main () {
	
	int i, j, N, a[100], temp, minj, count;
	
	count = 0 ;
	
	scanf ("%d",&N) ;
	for ( i = 0 ; i < N ; i ++ ) {
		scanf("%d", &a[i] ) ;
	}
		
	for (i = 0 ; i < N ; i++ ) {
		minj =i ;
		for ( j = i ; j < N ; j++ ) {
			if ( a[j] < a[minj] ){
				minj = j ;
			}
		}
		
		temp =a[i] ;
		a[i] = a[minj] ;
		a[minj] = temp ;
		if ( minj !=  i ) {
			count++ ;
		}
	}
	
	for ( i = 0 ; i < N ; i ++ ) {
		printf("%d",a[i] ) ;
		if (i != N-1)
		printf(" ");
	}
	printf("\n") ;
    printf ("%d\n", count) ;

return 0;
}
