#include <stdio.h>
#include <stdlib.h>

int linearSearch(int *, int, int);


main()
{

	int n, q;
	int *s, *t;
	int c=0;
	
	int i;


	scanf("%d", &n);
	s = (int *)malloc( sizeof(int) *(n+1) );
	for( i=0; i<n; i++) {
		scanf("%d", &s[i]);
	}
	
	scanf("%d", &q);
	t = (int *)malloc( sizeof(int) *q );
		for( i=0; i<q; i++) {
		scanf("%d", &t[i]);
	}
	
	
	for( i=0; i<q; i++) {
		c += linearSearch( s, n, t[i]);
	}
	
	printf("%d\n", c);
	
	return 0;
	
}


int linearSearch(int *array, int length, int key) {
		
	int i=0;
	array[length] = key;
	
	while(array[i] != key) {
			i++;
	}
	if( i==length ) {
		return 0;
	}
	return 1;
}
