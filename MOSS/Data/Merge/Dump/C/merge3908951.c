#include <stdio.h>
#define INT_MAX (1<<30)

int
merge(int *a, int l, int m, int r)
{
	int ln = m - l;
	int rn = r - m;
	int ls[ln + 1], rs[rn + 1];
	int i, j, k, c = 0;

	for (i = 0; i < ln; i++)
		ls[i] = a[l + i];
	ls[i] = INT_MAX;

	for (i = 0; i < rn; i++)
		rs[i] = a[m + i];
	rs[i] = INT_MAX;

	for (i = j = 0, k = l; k < r; k++) {
		if (ls[i] <= rs[j])
			a[k] = ls[i++];
		else
			a[k] = rs[j++];
		c++;
	}

	return c;
}

int
merge_sort(int *a, int l, int r)
{
	if (l + 1 < r) {
		int m = (l + r) / 2;

		return (merge_sort(a, l, m) +
			merge_sort(a, m, r) +
			merge(a, l, m, r));
	}

	return 0;
}

int
main(int argc, char **argv)
{
	int n;

	scanf("%d", &n);

	{
		int a[n];
		int i, s;

		for (i = 0; i < n; i++)
			scanf("%d", a + i);

		s = merge_sort(a, 0, n);

		for (i = 0; i < n; i++)
			printf("%s%d", i ? " " : "", a[i]);
		printf("\n%d\n", s);
	}

	return 0;
}
