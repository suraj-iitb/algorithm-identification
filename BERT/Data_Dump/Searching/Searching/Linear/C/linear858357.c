#include <stdio.h>


int main(void) {
	int n, q;
	int v, c = 0;
	int S[10000];
	int i;
	
	scanf("%d", &n);
	
	for (i = 0; i < n; ++i) {
		scanf("%d", &v);
		S[i] = v;
	}
	
	scanf("%d", &q);
	
	++q;
	while (--q) {
		scanf("%d", &v);
		for (i = 0; i < n; ++i) {
			if (S[i] == v) {
				++c;
				break;
			}
		}
	}
	
	printf("%d\n", c);
	
	return 0;	
}
