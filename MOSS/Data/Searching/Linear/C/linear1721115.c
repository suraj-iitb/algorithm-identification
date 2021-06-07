#include <stdio.h>

int main(int argc, char** argv)
{
	int i, j, k, n, q;
	long S[10000], T[500], result[500];

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%ld", &S[i]);
	}

	scanf("%d", &q);
	for (i = 0; i < q; i++) {
		scanf("%ld", &T[i]);
	}

	int cnt = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < q; j++) {
			if (S[i] == T[j]) {
				int is_match = 0;
				for (k = 0; k < cnt; k++) {
					if (result[k] == S[i]) {
						is_match = 1;
						break;
					}
				}
				if (!is_match) {
					result[cnt++] = S[i];
					break;
				}
			}
		}
	}

	printf("%d\n", cnt);
	return 0;
}
