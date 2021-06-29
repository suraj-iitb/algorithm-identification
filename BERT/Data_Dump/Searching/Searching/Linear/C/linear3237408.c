#include <stdio.h>

int main(void) {
	int s[10000], t[500];
	int i, j;
	int n, m, count = 0;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &s[i]);
	}

	scanf("%d", &m);
	for (i = 0; i < m; i++) {
		scanf("%d", &t[i]);
		for (j = 0; j < n; j++) {
			if (t[i] == s[j]) {
				count++;
				break;
			}
		}
	}

	printf("%d\n", count);

	return 0;
}

