#include <stdio.h>

int main(void) {
	int n, q;
	int cnt = 0;
	int s[10000] = { 0 };
	int t[500] = { 0 };
	int i, j;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &s[i]);
	}
	
	scanf("%d",&q);

	for (i = 0; i < q; i++) {
		scanf("%d", &t[i]);
		for (j = 0; j < i ;j++) {
			if (t[i] == t[j]) {
				i--;
				break;
			}
		}
	}

	for (i = 0; i < q ; i++) {
		for (j = 0; j < n ;j++) {
			if (t[i] == s[j]) {
				cnt++;
				break;
			}
		}
	}

	printf("%d\n", cnt);

	return 0;
}
