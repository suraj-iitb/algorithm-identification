#include <stdio.h>
#include <stdlib.h>

int binarySearch(int *, int, int);

main() {

	int n, q;
	int *s, *t;
	int c=0;
	
	int i, j, k;


	scanf("%d", &n);
	s = (int *)malloc( sizeof(int) *n );
	for( i=0; i<n; i++) {
		scanf("%d", &s[i]);
	}
	
	
	scanf("%d", &q);
	t = (int *)malloc( sizeof(int) *q );
		for( i=0; i<q; i++) {
		scanf("%d", &t[i]);
	}
	
	for( i=0; i<q; i++) {
		c += binarySearch( s, n, t[i]);
	}
	
	printf("%d\n", c);
	
	return 0;
}


int binarySearch(int *array, int length, int key) {
	
	int left = 0;
	int right = length;
	int mid = (int)length/2;
	
	while(left < right) {
		mid = (left + right)/2;
		if(key==array[mid]) {
			return 1;
		}
		if(key>array[mid]){
			left=mid+1;
		}
		else if(key<array[mid]) {
			right = mid;
		}
	}
	return 0;
}
