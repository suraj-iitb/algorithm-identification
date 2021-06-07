#include <stdio.h>

int a[10010];

int main() {
	int n, q, t, cnt = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}

	scanf("%d", &q);
	for (int i = 0; i < q; ++i) {
		scanf("%d", &t);
		for (int j = 0; j < n; ++j) {
			if (a[j] == t) {
				cnt++;
				break;
			}
		}
	}

	printf("%d\n", cnt);
}

