#include<stdio.h>

int main() {
	int n, q;
	int i, j=0;
	int cnt = 0;
	int S[10000];
	int T[10000];

	//数値の読み込み
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &S[i]);
	}
	scanf("%d", &q);
	for (i = 0; i < q; i++) {
		scanf("%d", &T[i]);
	}

	for (i = 0; i < q; i++) {
		S[n] = T[i];
		j = 0;
		while (S[j] != T[i]) {
			j++;
		}
		if (j < n && S[j] == T[i]) {
			cnt++;
		}
	}
	printf("%d\n", cnt);

	return 0;
}
