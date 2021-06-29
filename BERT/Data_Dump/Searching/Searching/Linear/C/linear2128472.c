#include <stdio.h>
#define MAX 10001

int S[MAX];
int T[500];

int main(void)
{
	int n, i, j, q, cnt;
	
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf(" %d", &S[i]);
	}

	scanf("%d", &q);
	for (i = 0; i < q; ++i) {
		scanf(" %d", &T[i]);
	}

	cnt = 0;
	for (i = 0; i < q; ++i) {
		for (j = 0; j < n; ++j) {
			if (T[i] == S[j]) {
				++cnt;
				break;
			}
		}
	}
	printf("%d\n", cnt);
	
	return 0;
}
