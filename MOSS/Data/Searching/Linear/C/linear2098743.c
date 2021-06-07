#include <stdio.h>

int main () {
	
	int n, s[10000],t[500], i, j, q;
	int count = 0 ;

	
	scanf ("%d",&n) ;
	for ( i = 0 ; i < n ; i ++ ) {
		scanf("%d", &s[i] ) ;
	}
	scanf ("%d",&q) ;
	for ( i = 0 ; i < q ; i ++ ) {
		scanf("%d", &t[i] ) ;
	}
	
	for ( j = 0 ; j < q ; j++) {
		for ( i = 0 ; i < n ; i++) {
			if ( s[i] == t[j] ) {
				count++ ;
				break;
			}
		}
	}
	
	printf("%d\n",count);
	
return 0;
}


 
