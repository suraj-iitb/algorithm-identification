#include<stdio.h>

int main(){
	int i, j, k, S[10000], T[500], n, q, c = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &S[i]);
	}
	scanf("%d", &q);
	for (i = 0; i < q; i++) {
		scanf("%d", &T[i]);
	}
	for (j = 0; j < q; j++) {
		for (i = 0; i < n; i++) {
			if (T[j] == S[i]) {
				c += 1;
				T[j] = -1;
			}
		}
	}
	printf("%d\n", c);
	return 0;
}

