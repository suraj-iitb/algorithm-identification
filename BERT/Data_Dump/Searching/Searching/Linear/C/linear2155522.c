#include <stdio.h>

int linearSearch(int, int *, int, int);

int main(void)
{
	int n, S[10000], q, T[500], i, a = 0;
	
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &S[i]);
	scanf("%d", &q);
	for (i = 0; i < q; i++)
		scanf("%d", &T[i]);
	for (i = 0; i < q; i++) {
		if (linearSearch(n, S, q, T[i]) != -1)
			a++;
	}
	printf("%d\n", a);
	return 0;
}

int linearSearch(int n, int *S, int q, int T)
{
	int i = 0;

	S[n] = T;
	while (S[i] != T)
		i++;
	if (i == n) {
		return -1;
	}
	return i;
}
