#include <stdio.h>
#define N_MAX 10000
#define Q_MAX 500

int	linear_search(int n, int *S, int key)
{
	int	i = 0;
	S[n] = key;
	while (S[i] != key)
		i++;
	if (i == n)
		return (0);
	return (1);
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
		cnt += linear_search(n, S, T[i]);
	printf("%d\n", cnt);
}
