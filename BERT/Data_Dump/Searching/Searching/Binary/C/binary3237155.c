#include <stdio.h>

int binarysearch(int ans, int n, int a[])
{
	int left = 0;
	int right = n;
	int mid;

	while (left < right)
	{
		mid = (left + right) / 2;
		if (a[mid] == ans)
			return 1;
		else if (ans > a[mid])
			left = mid + 1;
		else
			right = mid;
	}
	return 0;
}

int main(void)
{
	int i, n, m, ans;
	int a[100000];
	int count = 0;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);

	scanf("%d", &m);
	for (i = 0; i < m; i++)
	{
		scanf("%d", &ans);
		if (binarysearch(ans, n, a))
			count++;
	}

	printf("%d\n", count);

	return 0;
}
