#include <stdio.h>
int main(void) {
	int n, q, t;
	int i, j, count = 0;
	int s[10001];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &s[i]);
	scanf("%d", &q);
	for (i = 0; i < q; i++) {
		scanf("%d", &t);
		s[n] = t;
		j = 0;
		while (s[j] != t)
			j++;
		if (j < n)
			count++;
	}
	printf("%d\n", count);
	return 0;
}
