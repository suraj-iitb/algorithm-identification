#include <stdio.h>

int serch(int n, int S[], int x) {
	int left = 0;
	int right = n;
	int center;
	while (left < right) {
		center = (left + right) / 2;
		if (S[center] == x) {
			return 1;
		} else if (x < S[center]) {
			right = center;
		} else {
			left = center + 1;
		}
	}
	return 0;
}

int main() {
	int n, q;
	int S[100000];
	int i;
	int key;
	int count = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &S[i]);
	}
	scanf("%d", &q);
	for (i = 0; i < q; i++) {
		scanf("%d", &key);
		count += serch(n, S, key);
	}
	printf("%d\n", count);
	return 0;
}

