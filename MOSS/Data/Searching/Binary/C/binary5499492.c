#include <stdio.h>
#define N_MAX 100000
#define Q_MAX 50000

int	binary_search(int n, int S[], int key)
{
	int	left = 0;
	int	right = n;
	int	mid;

	while (left < right)
	{
		mid = (left + right) / 2;
		if (S[mid] == key)
			return (1);
		else if (key < S[mid])
			right = mid;
		else
			left = mid + 1;
	}
	return (0);
}

int	main(void)
{
	int	n;
	int	q;
	int	S[N_MAX];
	int	T[Q_MAX];
	int	i;
	int	cnt = 0;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &S[i]);
	scanf("%d", &q);
	for (i = 0; i < q; i++)
		scanf("%d", &T[i]);

	for (i = 0; i < q; i++)
		cnt += binary_search(n, S, T[i]);
	printf("%d\n", cnt);
	return (0);
}

