#include <stdio.h>

int linearSearch(int A[], int n, int key) {
	int i;
	int cnt = 0;
	for (i = 0; i < n; i++) {
		if (A[i] == key) return 1;
	}
	return 0;
}

int main() {
	int i;
	int n, q;
	int S[10005], T[505];
	int ans = 0;

	scanf("%d", &n);
	for (i = 0; i < n; i++){
		scanf("%d", &S[i]);
	}

	scanf("%d", &q);
	for (i = 0; i < q; i++) {
		scanf("%d", &T[i]);
		if (linearSearch(S, n, T[i]) == 1) ans++;
	}

	printf("%d\n", ans);

	return 0;
}
