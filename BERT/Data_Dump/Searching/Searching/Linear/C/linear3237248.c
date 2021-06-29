#include <stdio.h>

int main(void)
{
	int s[10000], t[500], u[500];
	int c = 0;
	int n, q;
	int i, j, k;
	int flag;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &s[i]);
	}
	scanf("%d", &q);
	for (i = 0; i < q; i++) {
		scanf("%d", &t[i]);
	}

	for (i = 0; i < q; i++) {
		for (j = 0; j < n; j++) {
			if (t[i] == s[j]) {
				flag = 0;
				for (k = 0; k < c; k++) {
					if (u[k] == s[j]) {
						flag = 1;
					}
				}
				if (flag == 0) {
					u[c] = s[j];
					c++;
				}
			}
		}
	}

	printf("%d\n", c);

	return 0;
}
