#include <stdio.h>          // printf(), scanf()
#include <string.h>         // memset()
#include <stdbool.h>

#define MAX_N 100000
#define MAX_F 50000

int s[MAX_N];
bool f[MAX_F];
int m = 0;

bool
search(int x)
{
	int l = 0, r = m - 1;
	while (l <= r)
	{
		int i = (l + r) / 2;
		if (x > s[i])
			l = i + 1;

		else if (x < s[i])
			r = i - 1;

		else
			return true;
	}

	return false;
}

int
main(int argc, char** argv)
{
	int n = 0;
	int q = 0;
	int u = 0;
	int v = 0;
	int i;

	memset(f, 0x00, sizeof(f));
	scanf("%d", &n);
	m = 0;
	for (i = 0; i < n; ++i)
	{
		scanf("%d", &u);
		if (u < MAX_F)
			f[u] = true;
		else
			s[m++] = u;
	}

	scanf("%d", &q);
	int count = 0;
	for (i = 0; i < q; ++i)
	{
		scanf("%d", &v);
		if (v < MAX_F)
		{
			if (f[v])
				count++;
		}
		else
		{
			if (search(v))
				count++;
		}
	}

	printf("%d\n", count);
	return 0;
}
