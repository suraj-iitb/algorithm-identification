#include <stdio.h>
#include <stdlib.h>

int
find(int a, int *s, int n)
{
	int p = 0, m = n;
	if (a < s[0] || s[n-1] < a)
		return 0;

	while (m > 2) {
		m >>= 1;
		if (a == s[p])
			return 1;
		else if (a < s[p])
			p -= m;
		else
			p += m;
	}
	if (a < s[p])
		m = -1;
	else
		m = 1;

	for (;;) {
		if (a == s[p])
			return 1;
		if (m < 0 && a > s[p]) {
			return 0;
		} else if (m > 0 && a < s[p]) {
			return 0;
		}
		p += m;
	}

	return 0;
}

int
main(int argc, char **argv)
{
	int i, j, n, q, a, c = 0;
	int *s;

	scanf("%d", &n);
	if (n <= 0)
		return 1;

	s = (int *)malloc(sizeof(int) * n);
	if (s == NULL)
		return 1;

	for (i = 0; i < n; i++)
		scanf("%d", s + i);

	scanf("%d", &q);
	if (q <= 0)
		return 1;

	for (i = 0; i < q; i++) {
		scanf("%d", &a);
		if (find(a, s, n))
			c++;
	}

	printf("%d\n", c);

	return 0;
}

