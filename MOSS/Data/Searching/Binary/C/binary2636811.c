#include <stdio.h>

int binarySearch(int *S, int n, int t)
{
	int head, mid, tail;

	head = 0;
	tail = n - 1;
	while (head <= tail)
	{
		mid = head + (tail - head) / 2;
		if (S[mid] == t) return 1;
		if (S[mid] < t) head = mid + 1;
		else tail = mid - 1;
	}

	return 0;
}

int main()
{
	int c, i, n, q, t;
	int S[100000];

	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &S[i]);

	c = 0;
	scanf("%d", &q);
	for (i = 0; i < q; i++)
	{
		scanf("%d", &t);
		c += binarySearch(S, n, t);
	}

	printf("%d\n", c);

	return 0;
}
