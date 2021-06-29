#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100000

long int S[MAX];

int binarySearch(int key, int n)
{
	int left, right, mid;
	
	left = 0;
	right = n;
	
	while (left < right) {
		mid = (left + right) / 2;
		if (S[mid] == key) {
			return 0;
		}
		else if (key < S[mid]) {
			right = mid;
		}
		else {
			left = mid + 1;
		}
	}
	return 1;
}


int main()
{
	int n, q;
	long int T[MAX];
	int i, cnt;
	
	cnt = 0;
	
	scanf("%d",&n);
	for (i = 0; i < n; i++) {
		scanf("%ld",&S[i]);
	}
	
	scanf("%d",&q);
	for (i = 0; i < q; i++) {
		scanf("%ld",&T[i]);
	}
	
	for (i = 0; i < q; i++) {
		binarySearch(T[i], n);
		if (binarySearch(T[i], n) == 0) {
			cnt++;
		}
	}
	printf("%d\n",cnt);
return 0;
}
