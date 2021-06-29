#include <stdio.h>

int linersearch(int a[], int n, int ans)
{
	int i = 0;
	a[n] = ans;

	while (a[i] != ans)
		i++;

	return i != n;
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
		if (linersearch(a, n, ans))
			count++;
	}

	printf("%d\n", count);

	return 0;
}
