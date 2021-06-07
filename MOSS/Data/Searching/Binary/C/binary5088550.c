#include <stdio.h>

int main() {
	int n, q, i, o;
	int S[100000];
	int key;
	int cnt = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &S[i]);
	}

	scanf("%d", &q);

	for (i = 0; i < q; i++) {
		scanf("%d", &key);
		cnt += serch(n, S, key);
	}

	printf("%d\n", cnt);
	return 0;
}



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

