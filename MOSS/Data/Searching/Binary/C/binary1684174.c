#include <stdio.h>

int binarySearch(int *, int);

int n;

int main(void)
{
	int i, S[100000], q, T[50000], c=0;
	
	scanf("%d",&n);
	for (i=0; i<n; i++) {
		scanf("%d",&S[i]);
	}
	scanf("%d",&q);
	for (i=0; i<q; i++) {
		scanf("%d",&T[i]);
	}
	
	for (i=0; i<q; i++) {
		if( binarySearch( S, T[i] ) != -1 ) c++;
	}
	
	printf("%d\n",c);
	
	return 0;
}

int binarySearch(int *S, int key)
{
	int left=0, right=n, mid;
	
	while ( left < right ) {
		mid = ( left + right ) / 2;
		if( S[mid] == key ) {
			return mid;
		} else if( key < S[mid] ) {
			right = mid;
		} else {
			left = mid + 1;
		}
	}
	return -1;
}
