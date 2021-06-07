#include<stdio.h>

#define MAX 100000

int main() {
	
	int i, j;
	int n;
	int S[MAX];
	int q;
	int T[MAX];
	int count = 0;
	
	int left, right, mid;
	
	scanf("%d", &n);
	
	for(i = 0; i < n; i++) {
		scanf("%d",&S[i]);
	}
	
	scanf("%d", &q);
	for(j = 0; j < q; j++) {
		scanf("%d",&T[j]);
		left = 0;
		right = n;
		while(left < right) {
			mid = (left + right) / 2;
			if(S[mid] == T[j]) { count++;  break; }
			else if(T[j] < S[mid]) { right = mid; }
			else { left = mid + 1; }
		}
	}
	printf("%d\n", count);
	
	return 0;
}
