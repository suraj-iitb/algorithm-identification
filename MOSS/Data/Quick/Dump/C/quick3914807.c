#include <stdio.h>
#include <stdlib.h>

#define SWAP(a, b, v) v = a, a = b, b = v
#define PRED(a, b) ((a)->value > (b)->value)

typedef struct card {
	char suite[4];
	int value;
	int order;
} TYPE;

int
partition(TYPE *a, int p, int r)
{
	TYPE x = a[r];
	TYPE v;
	int i;

	for (i = p; i < r; i++) {
		if (PRED(&a[i], &x))
			continue;

		SWAP(a[p], a[i], v);
		p++;
	}

	SWAP(a[p], a[r], v);

	return p;
}

void
quick_sort(TYPE *a, int p, int r)
{
	if (p < r) {
		int q = partition(a, p, r);
		quick_sort(a, p, q - 1);
		quick_sort(a, q + 1, r);
	}
}

int
is_stable(TYPE *a, int n)
{
	int i;

	for (i = 1; i < n; i++)
		if (a[i - 1].value == a[i].value &&
		    a[i - 1].order > a[i].order)
			return 0;

	return 1;
}

int
main(void)
{
	int i, n, q;
	TYPE *a;

	scanf("%d", &n);

	a = (TYPE *)malloc(sizeof(TYPE) * n);
	if (a == NULL)
		return 1;

	for (i = 0; i < n; i++)
		scanf("%s%d", a[i].suite, &a[i].value), a[i].order = i;

	quick_sort(a, 0, n - 1);

	printf("%stable\n", is_stable(a, n) ? "S" : "Not s");
	for (i = 0; i < n; i++)
		printf("%s %d\n", a[i].suite, a[i].value);

	return 0;
}

