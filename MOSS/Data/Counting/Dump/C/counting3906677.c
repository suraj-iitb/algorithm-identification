#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
counting_sort(int *a, int *b, int k_, int n)
{
	int k = k_ + 1;
	int c[k];
	int i;

	memset(c, 0, sizeof(int) * k);

	for (i = 0; i < n; i++)
		c[ a[i] ]++;

	for (i = 1; i < k; i++)
		c[i] = c[i] + c[i - 1];

	for (i = 0; i < n; i++)
		b[ --c[ a[i] ] ] = a[i];
}

int
main(int argc, char **argv)
{
	int i, k, n;
	int *a, *b;

	scanf("%d", &n);

	a = (int *)malloc(sizeof(int) * n);
	if (a == NULL)
		return 1;

	b = (int *)malloc(sizeof(int) * n);
	if (b == NULL)
		return 1;

	k = 0;
	for (i = 0; i < n; i++) {
		scanf("%d", a + i);
		if (k < a[i])
			k = a[i];
	}
	memcpy(b, a, n);

	counting_sort(a, b, k, n);

	for (i = 0; i < n; i++)
		printf("%s%d", i ? " " : "", b[i]);
	printf("\n");

	return 0;
}

