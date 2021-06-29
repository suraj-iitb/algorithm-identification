#include<stdio.h>

int serch(int n, int S[], int q, int T[]) {
	int count = 0;
	int i, j;
	for (i = 0; i < q; i++) {
		for (j = 0; j < n; j++) {
			if (T[i] == S[j]) {
				count++;
				break;
			}
		}
	}
	return count;
}

int main() {
	int n, q;
	int S[10000], T[500];
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &S[i]);
	}
	scanf("%d", &q);
	for (i = 0; i < q; i++) {
		scanf("%d", &T[i]);
	}
	printf("%d\n", serch(n, S, q, T));
	return 0;
}
