#include <stdio.h>
#include <stdlib.h>

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
		for (j = 0; j < n; j++)
			if (a == s[j]) {
				c++;
				break;
			}
	}

	printf("%d\n", c);

	return 0;
}

