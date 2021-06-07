#include <stdio.h>          // printf(), scanf()
#define MAX_N 10000

int
main(int argc, char** argv)
{
	int s[MAX_N + 1];
	int n = 0;
	int q = 0;
	int t = 0;
	int i, j;

	scanf("%d", &n);
	for (i = 0; i < n; ++i)
		scanf("%d", &s[i]);

	scanf("%d", &q);
	int count = 0;
	for (i = 0; i < q; ++i)
	{
		scanf("%d", &t);
		s[n] = t;
		for (j = 0; s[j] != t; ++j)
			;

		if (j < n)
			count++;
	}

	printf("%d\n", count);
	return 0;
}
