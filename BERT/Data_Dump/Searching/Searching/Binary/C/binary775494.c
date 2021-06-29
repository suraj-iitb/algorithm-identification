#include <stdio.h>
int main(void) {
	int s[100000], n, q, t, i, j, num = 0;
	int half;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", s+i);
	}
	scanf("%d", &q);
	half = n / 2;
	for (j = 0; j < q; j++) {
		scanf("%d", &t);
		if (t < s[half]) {
			for (i = 0; i < half; i++) {
				if (t == s[i]) {
					num++;
					break;
				}
			}
		} else {
			for (i = half; i < n; i++) {
				if (t == s[i]) {
					num++;
					break;
				}
			}
		}
	}
	printf("%d\n", num);
	return 0;
}
