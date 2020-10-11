#include <stdio.h>          // printf(), scanf()
#define MAX_N 100

int
main(int argc, char** argv)
{
	int a[MAX_N];
	int x;
	int n;
	int i, j;

	scanf("%d", &n);
	for (i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
		printf("%d%c", a[i], (i != n - 1) ? ' ' : '\n');
	}

	for (i = 1; i < n; ++i)
	{
		x = a[i];
		for (j = i - 1; j >= 0 && x < a[j]; --j)
			a[j + 1] = a[j];

		a[j + 1] = x;

		for (j = 0; j < n; ++j)
			printf("%d%c", a[j], (j != n - 1) ? ' ' : '\n');
	}

	return 0;
}
