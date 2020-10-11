#include <stdio.h>          // printf(), scanf()

#define MAX_N 100
#define swap(x, y) {int t = x; x = y; y = t;}

int
main(int argc, char** argv)
{
	int a[MAX_N];
	int n;
	int i, j;

	scanf("%d", &n);
	for (i = 0; i < n; ++i)
		scanf("%d", &a[i]);

	int count = 0;
	for (i = 0; i < n; ++i)
	{
		int minj = i;
		for (j = i; j < n; ++j)
		{
			if (a[j] < a[minj])
				minj = j;
		}

		if (i != minj)
		{
			swap(a[i], a[minj]);
			count++;
		}
	}

	for (i = 0; i < n; ++i)
		printf("%d%c", a[i], (i != n - 1) ? ' ' : '\n');

	printf("%d\n", count);
	return 0;
}
