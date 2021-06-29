#include <stdio.h>
#define t 1000000

int x[t], n;

int search(int key) {
	
	int mid;
	
	int left = 0;
	
	int right = n;
	
	while(left < right) {
		mid = (left + right ) / 2;
		if( x[mid] == key) {
			return 1;
		}
		if ( key > x[mid] ) {
			left = mid + 1;
		} else if( key < x[mid] ) {
			right = mid;
		}
	}
		return  0;
}

int main() {
	int i, q, l, sum = 0;
	
	scanf("%d", &n);
	for( i = 0; i < n; i++) {
		scanf("%d",&x[i]);
	}
	
	scanf("%d", &q);
	for( i = 0; i < q; i++) {
		scanf("%d", &l);
		if( search( l )) {
			sum = sum + 1;
		}
	}
	printf("%d\n", sum);
	
	return 0;
	
}
