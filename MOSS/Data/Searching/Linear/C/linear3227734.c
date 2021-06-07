#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10000

long int S[MAX];

int linearSearch(int key, int n)
{
	int i;
	
	i = 0;
	S[n] = key;
	while (S[i] != key) {
		i++;
	}
	if (i == n) {
		return 1;
	}
	return 0;
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
		linearSearch(T[i], n);
		if (linearSearch(T[i], n) == 0) {
			cnt++;
		}
	}
	printf("%d\n",cnt);
return 0;
}
