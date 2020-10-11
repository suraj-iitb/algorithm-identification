#include <stdio.h>          // printf(), scanf()
#include <stdbool.h>

#define MAX_N 100
#define swap(x, y) {int t = x; x = y; y = t;}

int
main(int argc, char** argv)
{
	int a[MAX_N];
	int count;
	int n;
	bool f;
	int i, j;

	scanf("%d", &n);
	for (i = 0; i < n; ++i)
		scanf("%d", &a[i]);

	count = 0;
	f = true;
	for (i = 0; f; ++i)
	{
		f = false;
		for (j = n - 1; j >= i + 1; --j)
		{
			if (a[j - 1] > a[j])
			{
				swap(a[j - 1], a[j]);
				f = true;
				count++;
			}
		}
	}

	for (i = 0; i < n; ++i)
		printf("%d%c", a[i], (i != n - 1) ? ' ' : '\n');

	printf("%d\n", count);
	return 0;
}
