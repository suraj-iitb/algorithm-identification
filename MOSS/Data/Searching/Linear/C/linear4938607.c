#include<stdio.h>

#define MAX 100000

int main() {
	
	int i, j;
	int n;
	int S[MAX];
	int q;
	int T[MAX];
	int count = 0;
	
	scanf("%d", &n);
	
	for(i = 0; i < n; i++) {
		scanf("%d",&S[i]);
	}
	
	scanf("%d", &q);
	for(j = 0; j < q; j++) {
		scanf("%d",&T[j]);
	}
	
	for(i = 0; i < q; i++) {
		for(j = 0; j < n; j++) {
			if(S[j] == T[i]) {
				count++;
				break;
			}
		}
	}
	
	printf("%d\n", count);
	
	return 0;
}
