#include <stdio.h>
#define N 10000
#define Q 500

int LinearSearch(int n[], int num, int key) {
	int i;
	for (i = 0; i < num; i++) {
		if (n[i] == key) {
			return 1;
		}
	}
	return 0;
}

int main(void) {
	int i, j = 0, n, q, key, count = 0;
	int S[N], T[Q];
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &S[i]);
	}
	scanf("%d", &q);
	for (i = 0; i < q; i++) {
		scanf("%d", &T[i]);
	}

	for (i = 0; i < q; i++) {
		key = T[i];
		if (LinearSearch(S, n, key)) {
			count++;
		}
	}

	printf("%d\n", count);

	return 0;
}
