#include <stdio.h>

#define N 100000

int cnt, n, q;
int s[N], t[N];

void scanData() {
	int i;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &s[i]);
	}

	scanf("%d", &q);

	for (i = 0; i < q; i++) {
		scanf("%d", &t[i]);
	}
}

void linearSearch(int a, int n) {
	int i;

	for (i = 0; i < n; i++) {
		if (s[i] == a) {
			cnt++;
			break;
		}
	}
}

int main() {
	int i;

	scanData();

	for (i = 0; i < q; i++) {
		linearSearch(t[i], n);
	}

	printf("%d\n", cnt);

	return 0;
}
