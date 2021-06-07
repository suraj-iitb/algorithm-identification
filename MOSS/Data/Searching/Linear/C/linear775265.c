#include <stdio.h>
int main(void) {
	int s[10000], t, n, q, i, num_intersection = 0;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", s+i);
	}
	scanf("%d", &q);
	while (q--) {
		scanf("%d", &t);
		for (i = 0; i < n; i++) {
			if (t == s[i]) {
				s[i] = -1;
				num_intersection++;
				break;
			}
		}
	}
	printf("%d\n", num_intersection);
	return 0;
}
