#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N_MAX 100

void
print_array(int *a, int n)
{
	int i;

	for (i = 0; i < n; i++)
		printf("%d%s", a[i], i + 1 < n ? " " : "");
	printf("\n");
}

int
insertion_sort(int *a, int n)
{
	int i, j, v;
	for (i = 1; i < n; i++) {
		v = a[i];
		j = i - 1;
		while (0 <= j && v < a[j]) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = v;
		print_array(a, n);
	}
}

int main(void)
{
	int p0, i, n = 0;
	int a[N_MAX];
	char *p;

	scanf("%d", &p0);

	if (p0 < 1 || N_MAX < p0)
		return 1;

	while (n < p0)
		scanf("%d", a + n++);

	print_array(a, n);
	insertion_sort(a, n);

	return 0;
}

