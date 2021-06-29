#include <stdio.h>

int A[10000000];
int n;

int binarySearch(int key)
{
	int left = 0;
	int right = n;
	int mid;
	
	while (left < right){
		mid = (left + right) / 2;
		if(key == A[mid]) return 1;
		if(key > A[mid]) left = mid + 1;
		else if(key < A[mid]) right = mid;
	}
	return 0;
}


int main()
{
	int i, q, k;
	int c = 0;
	
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%d", &A[i]);
	}
	
	scanf("%d", &q);
	for(i=0; i<q; i++){
		scanf("%d", &k);
		if(binarySearch(k)) c++;
	}
	printf("%d\n", c);
	
	return 0;
}
